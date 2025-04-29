# -*- coding: utf-8 -*
import time
import numpy as np
from pinpong.board import gboard, I2C
from enum import Enum
from dataclasses import dataclass
from typing import List, Tuple

class MPeriod(Enum):
    MOTOR1_2 = 0
    MOTOR3_4 = 1

class RgbNum(Enum):
    RGB0 = 0
    RGB1 = 1

class ServoNum(Enum):
    SERVO0 = 0
    SERVO1 = 1
    SERVO2 = 2
    SERVO3 = 3
    SERVO4 = 4
    SERVO5 = 5

class MotorNum(Enum):
    MOTOR1_A = 0
    MOTOR1_B = 1
    MOTOR2_A = 2
    MOTOR2_B = 3
    MOTOR3_A = 4
    MOTOR3_B = 5
    MOTOR4_A = 6
    MOTOR4_B = 7

class Servo360Direction(Enum):
    FORWARD = 0
    BACKWARD = 1
    STOP = 2

class IOType(Enum):
    ADC = 0
    DHT11 = 1
    DHT22 = 2
    DS18B20 = 3
    GPIO_OUT = 4
    GPIO_IN = 5

class IONum(Enum):
    C0 = 0
    C1 = 1
    C2 = 2
    C3 = 3
    C4 = 4
    C5 = 5

class GpioState(Enum):
    LOW = 0
    HIGH = 1

@dataclass
class DHTData:
    temperature: float
    humidity: float
    state: int

class UnihikerExpansion:
    # Register addresses
    I2C_MOTOR12_PERIOD_H = 0x00
    I2C_MOTOR34_PERIOD_H = 0x02
    I2C_MOTOR1_Z_DUTY_H = 0x04
    I2C_SERVO0_DUTY_H = 0x18
    I2C_IO_MODE_C0 = 0x2C
    I2C_W_C0 = 0x39
    I2C_R_C0 = 0x3F
    I2C_ADC_C0_S = 0x45
    I2C_DHT_C0_S = 0x57
    I2C_18B20_C0_S = 0x75
    I2C_BATTERY = 0x87
    I2C_IR_S_STATE = 0x24
    I2C_IR_R_STATE = 0x88
    I2C_WS2812_STATE = 0x90
    I2C_WS2812_BRIGHT = 0x91
    I2C_WS2812_R0 = 0x92
    I2C_SR04_STATE = 0x29
    I2C_RESET_SENSOR = 0xA0
    DATA_ENABLE = 0x01
    DATA_DISABLE = 0x00
    MODE_ERROR = 0x02
    SR04_COLLECT = 0x01
    SR04_COMPLETE = 0x02
    ERROR_COUNT = 5  # 定义最大错误尝试次数

    def __init__(self, board=None, i2c_addr=0x33, bus_num=0):  # 修正默认地址为0x33
        if isinstance(board, int):
            i2c_addr = board
            board = gboard
        elif board is None:
            board = gboard
        self._connect = 0
        self.i2c_addr = i2c_addr
        self.board = board
        self.i2c = I2C(board=board, bus_num=bus_num)
        self.begin()
        
    def begin(self):
        self._write_regs(self.I2C_RESET_SENSOR, [self.DATA_ENABLE])
        time.sleep(0.5)
        
    def _read_regs(self, reg_addr, length):
        self._connect = 0
        while True:
            try:
                return list(self.i2c.readfrom_mem(self.i2c_addr, reg_addr, length))
            except Exception as e:
                self._connect += 1
                if self._connect >= self.ERROR_COUNT:
                    raise RuntimeError("Device communication failure") from e
                time.sleep(0.1)

    def _write_regs(self, reg_addr, data):
        self._connect = 0
        if not isinstance(data, (bytes, bytearray, list)):
            data = [data]
        while True:
            try:
                self.i2c.writeto(self.i2c_addr, [reg_addr]+data)
                return True
            except Exception as e:
                self._connect += 1
                if self._connect > self.ERROR_COUNT:
                    raise RuntimeError("Device communication failure") from e
                time.sleep(0.1)

    def set_motor_period(self, period_type: MPeriod, motor_period: int):
        reg_map = {
            MPeriod.MOTOR1_2: self.I2C_MOTOR12_PERIOD_H,
            MPeriod.MOTOR3_4: self.I2C_MOTOR34_PERIOD_H,
        }
        reg = reg_map[period_type]
        data = [(motor_period >> 8) & 0xFF, motor_period & 0xFF]
        self._write_regs(reg, data)
        time.sleep(0.02)

    def set_motor_duty(self, motor: MotorNum, duty: int):
        reg = self.I2C_MOTOR1_Z_DUTY_H + motor.value * 2
        data = [(duty >> 8) & 0xFF, duty & 0xFF]
        self._write_regs(reg, data)
        time.sleep(0.02)

    def set_servo_angle(self, servo: ServoNum, angle: int):
        if angle > 180:
            angle = 180
        period = 500 + angle * 11
        reg = self.I2C_SERVO0_DUTY_H + servo.value * 2
        data = [(period >> 8) & 0xFF, period & 0xFF]
        self._write_regs(reg, data)
        time.sleep(0.02)


    def set_servo360(self, servo: ServoNum, direction: Servo360Direction, speed: int):
        if speed > 100:
            speed = 100
        if direction == Servo360Direction.BACKWARD:
            period = int(1550 + speed * 4.5)  # 1550 ~ 2000
        elif direction == Servo360Direction.FORWARD:
            period = int(1450 - speed * 4.5)  # 1450 ~ 1000
        elif direction == Servo360Direction.STOP:
            period = 1500
        else:
            return
        if speed == 0:
            period = 1500

        reg = self.I2C_SERVO0_DUTY_H + servo.value * 2
        data = [(period >> 8) & 0xFF, period & 0xFF]
        self._write_regs(reg, data)
        time.sleep(0.02)

    def get_battery(self):
        data = self._read_regs(self.I2C_BATTERY, 1)
        return data[0]
        
    def get_dht_value(self, pin: IONum) -> DHTData:
        reg = self.I2C_DHT_C0_S + pin.value * 5
        dht_data = DHTData(0.0, 0.0, self.DATA_DISABLE)
        self._write_regs(reg, [self.DATA_ENABLE])
        time.sleep(0.03)
        data = self._read_regs(reg, 5)
        if data[0] == self.DATA_ENABLE:
            temp_sign = -1.0 if (data[1] & 0x80) else 1.0
            dht_data.temperature = (data[1] & 0x7F) + data[2] * 0.01
            dht_data.temperature *= temp_sign
            dht_data.humidity = data[3] + data[4] * 0.01
            dht_data.state = self.DATA_ENABLE
        elif data[0] == self.MODE_ERROR:
            dht_data.state = self.MODE_ERROR
        return dht_data

    def get_18b20_value(self, pin: IONum) -> float:
        reg = self.I2C_18B20_C0_S + pin.value * 3
        self._write_regs(reg, [self.DATA_ENABLE])
        time.sleep(0.05)
        
        data = self._read_regs(reg, 3)
        if data[0] == self.DATA_ENABLE:
            if data[1] == 0xFF and data[2] == 0xFF:
                return 0.0
            sign = -1.0 if (data[1] & 0x80) else 1.0
            raw_temp = ((data[1] & 0x7F) << 8) | data[2]
            return sign * raw_temp / 16.0
        return 0.0

    def get_sr04_distance(self) -> int:
        self._write_regs(self.I2C_SR04_STATE, [self.SR04_COLLECT])
        time.sleep(0.03)
        data = self._read_regs(self.I2C_SR04_STATE, 3)
        if data[0] == self.SR04_COMPLETE:
            distance = (data[1] << 8) | data[2]
            return np.int16(distance)
        return -1

    def get_mode(self, pin: IONum):
        reg = self.I2C_IO_MODE_C0 + pin.value
        data = self._read_regs(reg, 1)

    def set_mode(self, pin: IONum, mode: IOType):
        reg = self.I2C_IO_MODE_C0 + pin.value
        self._write_regs(reg, [mode.value])
        time.sleep(0.02)

    def set_gpio_state(self, pin: IONum, state: GpioState):
        reg = self.I2C_W_C0 + pin.value
        self._write_regs(reg, [state.value])
        time.sleep(0.02)

    def get_gpio_state(self, pin: IONum) -> int:
        reg = self.I2C_R_C0 + pin.value
        data = self._read_regs(reg, 1)
        return data[0]

    def get_adc_value(self, pin: IONum) -> int:
        reg = self.I2C_ADC_C0_S + pin.value * 3
        data = self._read_regs(reg, 3)
        if data[0] == self.DATA_ENABLE:
            adc_value = (data[1] << 8) | data[2]
            if adc_value > 3900: return 4095
            if adc_value < 40: return 0
            return adc_value
        return -1

    def send_ir(self, data: int):
        payload = [
            self.DATA_ENABLE,
            (data >> 24) & 0xFF,
            (data >> 16) & 0xFF,
            (data >> 8) & 0xFF,
            data & 0xFF
        ]
        self._write_regs(self.I2C_IR_S_STATE, payload)
        time.sleep(0.02)

    def get_ir_data(self) -> int:
        data = self._read_regs(self.I2C_IR_R_STATE, 5)
        if data[0] == self.DATA_DISABLE:
            return 0
        return (data[1] << 24) | (data[2] << 16) | (data[3] << 8) | data[4]

    def set_bright(self, brightness: int):
        payload = [self.DATA_ENABLE, brightness]
        self._write_regs(self.I2C_WS2812_STATE, payload)
    
    def get_bright(self):
        data = self._read_regs(self.I2C_WS2812_BRIGHT, 1)
        return data
    
    def get_RGB(self):
        data = self._read_regs(self.I2C_WS2812_R0, 3)
        return data
        
    def set_ws2812(self, num: RgbNum, color: int):
        payload = [self.DATA_ENABLE]
        payload += self.get_bright()
        if num == RgbNum.RGB0:
            pass
        else:
            payload +=  self.get_RGB()
        payload += [(color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF]
        self._write_regs(self.I2C_WS2812_STATE, payload)
        time.sleep(0.02)