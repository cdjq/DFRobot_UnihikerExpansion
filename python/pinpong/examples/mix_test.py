# -*- coding: utf-8 -*-
import time
from pinpong.board import Board
from pinpong.libs.dfrobot_unihiker_expansion import UnihikerExpansion, IONum, IOType, ServoNum, MPeriod, RgbNum, MotorNum, GpioState, DHTData

Board("").begin()

eunihiker = UnihikerExpansion() 
eunihiker.set_mode(IONum.C0, IOType.ADC)
eunihiker.set_mode(IONum.C1, IOType.DHT11)
eunihiker.set_mode(IONum.C2, IOType.DHT22)
eunihiker.set_mode(IONum.C3, IOType.DS18B20)
eunihiker.set_mode(IONum.C4, IOType.GPIO_OUT)
eunihiker.set_mode(IONum.C5, IOType.GPIO_IN)

eunihiker.set_motor_period(MPeriod.MOTOR1_2, 60000)
eunihiker.set_motor_period(MPeriod.MOTOR3_4, 255)

while True:
    battery = eunihiker.get_battery()
    print(f"battery value is {battery} %")
    eunihiker.send_ir(12345678)
    time.sleep(0.1)
    ir_data = eunihiker.get_ir_data()
    if ir_data != 0:    
        print(f"ir recv data = {ir_data}")
    
    adcvalue = eunihiker.get_adc_value(IONum.C0)
    print(f"C0 adc value = {adcvalue}")
    
    dht11_data = eunihiker.get_dht_value(IONum.C1)
    if dht11_data.state == eunihiker.DATA_ENABLE:
        print(f"C1 dht temperature = {dht11_data.temperature}")
        print(f"C1 dht humidity = {dht11_data.humidity}")
        
    dht22_data = eunihiker.get_dht_value(IONum.C2)
    if dht22_data.state == eunihiker.DATA_ENABLE:
        print(f"C2 dht temperature = {dht22_data.temperature}")
        print(f"C2 dht humidity = {dht22_data.humidity}")
    
    data = eunihiker.get_18b20_value(IONum.C3)
    print(f"C3 ds18b20 temp = {data}")
        
    eunihiker.set_gpio_state(IONum.C4, GpioState.HIGH)
    time.sleep(0.05)
    state = eunihiker.get_gpio_state(IONum.C4)
    print(f"C4 io = {state}")
    
    state = eunihiker.get_gpio_state(IONum.C5)
    print(f"C5 io = {state}")
    
    distance = eunihiker.get_sr04_distance()
    if distance < 0:
      print("sr04 messure failed ")
    else:
      print(f"distance = {distance} cm")
      
    eunihiker.set_motor_duty(MotorNum.MOTOR1_A, 30000)
    eunihiker.set_motor_duty(MotorNum.MOTOR1_B, 0)
    eunihiker.set_motor_duty(MotorNum.MOTOR2_A, 0)
    eunihiker.set_motor_duty(MotorNum.MOTOR2_B, 30000)
    eunihiker.set_motor_duty(MotorNum.MOTOR3_A, 100)
    eunihiker.set_motor_duty(MotorNum.MOTOR3_B, 0)
    eunihiker.set_motor_duty(MotorNum.MOTOR4_A, 0)
    eunihiker.set_motor_duty(MotorNum.MOTOR4_B, 100)

    eunihiker.set_ws2812(RgbNum.RGB0, 0xFF00FF)
    eunihiker.set_ws2812(RgbNum.RGB1, 0x0000FF)
    eunihiker.set_bright(5)
    eunihiker.set_servo_angle(ServoNum.SERVO0, 0)
    eunihiker.set_servo_angle(ServoNum.SERVO1, 0)
    eunihiker.set_servo_angle(ServoNum.SERVO2, 0)
    eunihiker.set_servo_angle(ServoNum.SERVO3, 0)
    eunihiker.set_servo_angle(ServoNum.SERVO4, 0)
    eunihiker.set_servo_angle(ServoNum.SERVO5, 0)
    
    time.sleep(1)    
    
    
    eunihiker.set_motor_duty(MotorNum.MOTOR1_A, 300)
    eunihiker.set_motor_duty(MotorNum.MOTOR1_B, 0)
    eunihiker.set_motor_duty(MotorNum.MOTOR2_A, 0)
    eunihiker.set_motor_duty(MotorNum.MOTOR2_B, 300)
    eunihiker.set_motor_duty(MotorNum.MOTOR3_A, 10)
    eunihiker.set_motor_duty(MotorNum.MOTOR3_B, 0)
    eunihiker.set_motor_duty(MotorNum.MOTOR4_A, 0)
    eunihiker.set_motor_duty(MotorNum.MOTOR4_B, 10)

    eunihiker.set_ws2812(RgbNum.RGB0, 0x000000)
    eunihiker.set_ws2812(RgbNum.RGB1, 0xFFFFFF)
    eunihiker.set_bright(1)
    eunihiker.set_servo_angle(ServoNum.SERVO0, 30)
    eunihiker.set_servo_angle(ServoNum.SERVO1, 60)
    eunihiker.set_servo_angle(ServoNum.SERVO2, 90)
    eunihiker.set_servo_angle(ServoNum.SERVO3, 120)
    eunihiker.set_servo_angle(ServoNum.SERVO4, 150)
    eunihiker.set_servo_angle(ServoNum.SERVO5, 180)
    time.sleep(1)
    