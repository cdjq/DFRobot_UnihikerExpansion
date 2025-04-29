# -*- coding: utf-8 -*-
'''!
  @file DFRobot_unihiker_expansion.py
  @brief DFRobot_unihiker_expansion Class infrastructure, implementation of underlying methods
  @copyright Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license The MIT License (MIT)
  @author [ZhixinLiu](zhixin.liu@dfrobot.com)
  @version V1.0
  @date 2025-04-16
  @url https://github.com/DFRobot/DFRobot_UnihikerExpansion
'''
import time
from machine import I2C, Pin
from micropython import const

# Constant definitions to replace enums
MPeriod = {"MOTOR1_2": 0, "MOTOR3_4": 1}
RgbNum = {"RGB0": 0, "RGB1": 1}
ServoNum = {f"SERVO{i}": i for i in range(6)}
Servo360Direction = {"FORWARD", "BACKWARD", "STOP"}
MotorNum = {
  "MOTOR1_A": 0, "MOTOR1_B": 1, "MOTOR2_A": 2, "MOTOR2_B": 3,
  "MOTOR3_A": 4, "MOTOR3_B": 5, "MOTOR4_A": 6, "MOTOR4_B": 7
}
IOType = {
  "ADC": 0, "DHT11": 1, "DHT22": 2, "DS18B20": 3,
  "GPIO_OUT": 4, "GPIO_IN": 5
}
IONum = {f"C{i}": i for i in range(6)}
GpioState = {"LOW": 0, "HIGH": 1}

class DHTData:
    '''!
        @brief Data container for DHT temperature/humidity sensor
    '''
    def __init__(self, temperature=0.0, humidity=0.0, state=0):
        self.temperature = temperature
        self.humidity = humidity
        self.state = state

class UnihikerExpansion:
    '''!
        @brief Main class for controlling Unihiker expansion board via I2C
        @details Provides methods for motor control, sensor reading, GPIO operations, etc.
    '''
    # Register address constants
    I2C_MOTOR12_PERIOD_H = const(0x00)
    I2C_MOTOR34_PERIOD_H = const(0x02)
    I2C_MOTOR1_Z_DUTY_H = const(0x04)
    I2C_SERVO0_DUTY_H = const(0x18)
    I2C_IO_MODE_C0 = const(0x2C)
    I2C_W_C0 = const(0x39)
    I2C_R_C0 = const(0x3F)
    I2C_ADC_C0_S = const(0x45)
    I2C_DHT_C0_S = const(0x57)
    I2C_18B20_C0_S = const(0x75)
    I2C_BATTERY = const(0x87)
    I2C_IR_S_STATE = const(0x24)
    I2C_IR_R_STATE = const(0x88)
    I2C_WS2812_STATE = const(0x90)
    I2C_WS2812_BRIGHT = const(0x91)
    I2C_WS2812_R0 = const(0x92)
    I2C_SR04_STATE = const(0x29)
    I2C_RESET_SENSOR = const(0xA0)

    DATA_ENABLE = const(0x01)
    DATA_DISABLE = const(0x00)
    MODE_ERROR = const(0x02)
    SR04_COLLECT = const(0x01)
    SR04_COMPLETE = const(0x02)
    ERROR_COUNT = const(5)

    def __init__(self, i2c_addr=0x33, sda_pin=47, scl_pin=48, i2c_bus=0):
        '''!
            @brief Initialize I2C communication
            @param i2c_addr I2C device address (default 0x33)
            @param sda_pin SDA pin number (default 47)
            @param scl_pin SCL pin number (default 48)
            @param i2c_bus I2C bus number (default 0)
        '''
        self.i2c_addr = i2c_addr
        self.i2c = I2C(i2c_bus, scl=Pin(scl_pin), sda=Pin(sda_pin), freq=100000)
        self.begin()

    def begin(self):
        '''!
            @brief Initialize expansion board by sending reset signal
            @note This will reset all peripherals on the expansion board
        '''
        self._write_regs(self.I2C_RESET_SENSOR, [self.DATA_ENABLE])
        time.sleep(0.5)

    def _read_regs(self, reg_addr, length):
        '''!
            @brief Read multiple bytes from I2C register (internal method)
            @param reg_addr Register start address
            @param length Number of bytes to read
            @return Bytearray containing read data
        '''
        for _ in range(self.ERROR_COUNT):
            try:
                return self.i2c.readfrom_mem(self.i2c_addr, reg_addr, length)
            except OSError:
                time.sleep(0.1)
        return bytearray(length)

    def _write_regs(self, reg_addr, data):
        '''!
            @brief Write data to I2C register (internal method)
            @param reg_addr Target register address
            @param data Data to write (list or bytearray)
        '''
        if not isinstance(data, (list, bytearray)):
            data = [data]
        buf = bytearray([reg_addr] + data)
        for _ in range(self.ERROR_COUNT):
            try:
                self.i2c.writeto(self.i2c_addr, buf)
                return
            except OSError:
                time.sleep(0.1)

    def set_motor_period(self, period_type, motor_period):
        '''!
            @brief Set PWM period for motor groups
            @param period_type Motor group selection (MOTOR1_2/MOTOR3_4)
            @param motor_period PWM period value (0-0xFFFF)
            @throws ValueError If invalid period_type or out-of-range period
        '''
        if period_type not in MPeriod:
            raise ValueError("Invalid period_type")
        if not (0 <= motor_period <= 0xFFFF):
            raise ValueError("motor_period out of range")
        reg_map = {
            "MOTOR1_2": self.I2C_MOTOR12_PERIOD_H,
            "MOTOR3_4": self.I2C_MOTOR34_PERIOD_H,
        }
        reg = reg_map[period_type]
        data = [(motor_period >> 8) & 0xFF, motor_period & 0xFF]
        self._write_regs(reg, data)
        time.sleep(0.02)

    def set_motor_duty(self, motor, duty):
        '''!
            @brief Set duty cycle for specific motor channel
            @param motor Motor channel selection (MOTOR1_A to MOTOR4_B)
            @param duty Duty cycle value (0-0xFFFF)
            @throws ValueError If invalid motor or out-of-range duty
        '''
        if motor not in MotorNum:
            raise ValueError("Invalid motor")
        if not (0 <= duty <= 0xFFFF):
            raise ValueError("duty out of range")
        reg = self.I2C_MOTOR1_Z_DUTY_H + MotorNum[motor] * 2
        data = [(duty >> 8) & 0xFF, duty & 0xFF]
        self._write_regs(reg, data)
        time.sleep(0.02)


    def set_servo360(self, servo, direction, speed):
        '''!
            @brief Set servo motor360
            @param servo Servo channel selection (SERVO0-SERVO5)
            @param direction "FORWARD"/"BACKWARD"/"STOP"
            @Param speed (0-100)
            @throws ValueError If invalid servo channel
        '''
        if servo not in ServoNum:
            raise ValueError("Invalid servo")
        if direction not in Servo360Direction:
            raise ValueError("Invalid direction")
        if speed > 100:
            speed = 100
        if direction == "FORWARD":
            period = int(1550 + speed * 4.5)  # 1550 ~ 2000
        elif direction == "BACKWARD":
            period = int(1450 - speed * 4.5)  # 1450 ~ 1000
        elif direction == "STOP":
            period = 1500
        if speed == 0:
            period = 1500
        reg = self.I2C_SERVO0_DUTY_H + ServoNum[servo] * 2
        data = [(period >> 8) & 0xFF, period & 0xFF]
        self._write_regs(reg, data)
        time.sleep(0.02)
        
    def set_servo_angle(self, servo, angle):
        '''!
            @brief Set servo motor rotation angle
            @param servo Servo channel selection (SERVO0-SERVO5)
            @param angle Target angle (0-180 degrees)
            @throws ValueError If invalid servo channel
        '''
        if servo not in ServoNum:
            raise ValueError("Invalid servo")
        angle = max(0, min(180, angle))
        period = 500 + angle * 11
        reg = self.I2C_SERVO0_DUTY_H + ServoNum[servo] * 2
        data = [(period >> 8) & 0xFF, period & 0xFF]
        self._write_regs(reg, data)
        time.sleep(0.02)

    def get_battery(self):
        '''!
            @brief Read battery voltage level
            @return Battery level (0-255 scale)
        '''
        return self._read_regs(self.I2C_BATTERY, 1)[0]

    def get_dht_value(self, pin):
        '''!
            @brief Read DHT temperature/humidity sensor data
            @param pin Connected pin (C0-C5)
            @return DHTData object containing measurements
            @throws ValueError If invalid pin
        '''
        if pin not in IONum:
            raise ValueError("Invalid pin")
        reg = self.I2C_DHT_C0_S + IONum[pin] * 5
        dht_data = DHTData()
        self._write_regs(reg, [self.DATA_ENABLE])
        time.sleep(0.03)
        data = self._read_regs(reg, 5)
        if data[0] == self.DATA_ENABLE:
            temp_sign = -1.0 if (data[1] & 0x80) else 1.0
            dht_data.temperature = ((data[1] & 0x7F) + data[2] * 0.01) * temp_sign
            dht_data.humidity = data[3] + data[4] * 0.01
            dht_data.state = self.DATA_ENABLE
        elif data[0] == self.MODE_ERROR:
            dht_data.state = self.MODE_ERROR
        return dht_data

    def get_18b20_value(self, pin):
        '''!
            @brief Read DS18B20 temperature sensor
            @param pin Connected pin (C0-C5)
            @return Temperature in Celsius
            @throws ValueError If invalid pin
        '''
        if pin not in IONum:
            raise ValueError("Invalid pin")
        reg = self.I2C_18B20_C0_S + IONum[pin] * 3
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

    def get_sr04_distance(self):
        '''!
            @brief Measure distance with ultrasonic sensor
            @return Distance in cm (-1 if error)
        '''
        self._write_regs(self.I2C_SR04_STATE, [self.SR04_COLLECT])
        time.sleep(0.03)
        data = self._read_regs(self.I2C_SR04_STATE, 3)
        if data[0] == self.SR04_COMPLETE:
            distance = (data[1] << 8) | data[2]
            return distance if distance < 32768 else distance - 65536
        return -1

    def set_mode(self, pin, mode):
        '''!
            @brief Set IO pin working mode
            @param pin Target pin (C0-C5)
            @param mode Operation mode (ADC/DHT11/DHT22/DS18B20/GPIO_OUT/GPIO_IN)
            @throws ValueError If invalid parameters
        '''
        if pin not in IONum:
            raise ValueError("Invalid pin")
        if mode not in IOType:
            raise ValueError("Invalid mode")
        reg = self.I2C_IO_MODE_C0 + IONum[pin]
        self._write_regs(reg, [IOType[mode]])
        time.sleep(0.03)

    def set_gpio_state(self, pin, state):
        '''!
            @brief Set GPIO output state
            @param pin Target pin (C0-C5)
            @param state Output state (HIGH/LOW)
            @throws ValueError If invalid parameters
        '''
        if pin not in IONum:
            raise ValueError("Invalid pin")
        if state not in GpioState:
            raise ValueError("Invalid GPIO state")
        reg = self.I2C_W_C0 + IONum[pin]
        self._write_regs(reg, [GpioState[state]])
        time.sleep(0.02)

    def get_gpio_state(self, pin):
        '''!
            @brief Read GPIO input state
            @param pin Target pin (C0-C5)
            @return Current pin state (0/1)
            @throws ValueError If invalid pin
        '''
        if pin not in IONum:
            raise ValueError("Invalid pin")
        reg = self.I2C_R_C0 + IONum[pin]
        return self._read_regs(reg, 1)[0]

    def get_adc_value(self, pin):
        '''!
            @brief Read analog input value
            @param pin Target pin (C0-C5)
            @return ADC value (0-4095)
            @throws ValueError If invalid pin
        '''
        if pin not in IONum:
            raise ValueError("Invalid pin")
        reg = self.I2C_ADC_C0_S + IONum[pin] * 3
        data = self._read_regs(reg, 3)
        if data[0] == self.DATA_ENABLE:
            adc_value = (data[1] << 8) | data[2]
            if adc_value > 3900: return 4095
            if adc_value < 40: return 0
            return adc_value
        return -1

    def send_ir(self, data):
        '''!
            @brief Send infrared signal
            @param data 32-bit IR command data
        '''
        payload = [
            self.DATA_ENABLE,
            (data >> 24) & 0xFF,
            (data >> 16) & 0xFF,
            (data >> 8) & 0xFF,
            data & 0xFF
        ]
        self._write_regs(self.I2C_IR_S_STATE, payload)
        time.sleep(0.02)

    def get_ir_data(self):
        '''!
            @brief Receive infrared signal
            @return 32-bit received IR data (0 if no data)
        '''
        data = self._read_regs(self.I2C_IR_R_STATE, 5)
        if data[0] == self.DATA_DISABLE:
            return 0
        return (data[1] << 24) | (data[2] << 16) | (data[3] << 8) | data[4]

    def get_bright(self):
        '''!
            @brief Get current WS2812 LED brightness
            @return Brightness value (0-255)
        '''
        return self._read_regs(self.I2C_WS2812_BRIGHT, 1)

    def set_bright(self, brightness):
        '''!
            @brief Set WS2812 LED brightness
            @param brightness Target brightness (0-255)
        '''
        brightness = max(0, min(255, brightness))
        payload = [self.DATA_ENABLE, brightness]
        self._write_regs(self.I2C_WS2812_STATE, payload)
        time.sleep(0.02)

    def set_ws2812(self, num, color):
        '''!
            @brief Set WS2812 LED color
            @param num LED index (RGB0/RGB1)
            @param color 24-bit RGB color (0xRRGGBB)
            @throws ValueError If invalid LED index
        '''
        if num not in RgbNum:
            raise ValueError("Invalid RGB index")
        payload = [self.DATA_ENABLE]
        payload += self.get_bright()
        if num == "RGB1":
            payload += self._read_regs(self.I2C_WS2812_R0, 3)
        payload += [(color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF]
        self._write_regs(self.I2C_WS2812_STATE, payload)
        time.sleep(0.02)
