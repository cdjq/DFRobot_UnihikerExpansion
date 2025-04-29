# -*- coding: utf-8 -*-
import time
from pinpong.board import Board
from pinpong.libs.dfrobot_unihiker_expansion import UnihikerExpansion, MPeriod, MotorNum

Board("").begin()

eunihiker = UnihikerExpansion()
eunihiker.set_motor_period(MPeriod.MOTOR1_2, 255)
eunihiker.set_motor_period(MPeriod.MOTOR3_4, 255)


while True:

    eunihiker.set_motor_duty(MotorNum.MOTOR1_A, 255)
    eunihiker.set_motor_duty(MotorNum.MOTOR1_B, 0)
    eunihiker.set_motor_duty(MotorNum.MOTOR2_A, 0)
    eunihiker.set_motor_duty(MotorNum.MOTOR2_B, 255)
    eunihiker.set_motor_duty(MotorNum.MOTOR3_A, 0)
    eunihiker.set_motor_duty(MotorNum.MOTOR3_B, 20)
    eunihiker.set_motor_duty(MotorNum.MOTOR4_A, 20)
    eunihiker.set_motor_duty(MotorNum.MOTOR4_B, 0)
    time.sleep(1)
    eunihiker.set_motor_duty(MotorNum.MOTOR1_A, 0)
    eunihiker.set_motor_duty(MotorNum.MOTOR1_B, 255)
    eunihiker.set_motor_duty(MotorNum.MOTOR2_A, 255)
    eunihiker.set_motor_duty(MotorNum.MOTOR2_B, 0)
    eunihiker.set_motor_duty(MotorNum.MOTOR3_A, 20)
    eunihiker.set_motor_duty(MotorNum.MOTOR3_B, 0)
    eunihiker.set_motor_duty(MotorNum.MOTOR4_A, 0)
    eunihiker.set_motor_duty(MotorNum.MOTOR4_B, 20)
    time.sleep(1)