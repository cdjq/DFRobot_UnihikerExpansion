# -*- coding: utf-8 -*-
import time
from pinpong.board import Board
from pinpong.libs.dfrobot_unihiker_expansion import UnihikerExpansion, MPeriod, MotorNum

Board("").begin()

eunihiker = UnihikerExpansion()
eunihiker.set_motor_period(MPeriod.MOTOR1_2, 60000)
eunihiker.set_motor_period(MPeriod.MOTOR3_4, 255)


while True:

    eunihiker.set_motor_duty(MotorNum.MOTOR1_A, 30000)
    eunihiker.set_motor_duty(MotorNum.MOTOR1_B, 0)
    
    eunihiker.set_motor_duty(MotorNum.MOTOR2_A, 0)
    eunihiker.set_motor_duty(MotorNum.MOTOR2_B, 30000)
    
    
    eunihiker.set_motor_duty(MotorNum.MOTOR3_A, 100)
    eunihiker.set_motor_duty(MotorNum.MOTOR3_B, 0)
    
    eunihiker.set_motor_duty(MotorNum.MOTOR4_A, 0)
    eunihiker.set_motor_duty(MotorNum.MOTOR4_B, 100)
    
    time.sleep(1)