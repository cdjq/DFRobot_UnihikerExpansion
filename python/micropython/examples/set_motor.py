# -*- coding: utf-8 -*
'''!
  @file set_motor.py
  @brief set motor
  @copyright Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license The MIT License (MIT)
  @author [ZhixinLiu](zhixin.liu@dfrobot.com)
  @version V1.0
  @date 2025-04-15
  @url https://github.com/DFRobot/DFRobot_UnihikerExpansion
'''
import sys
import os
sys.path.append('../')
import time
from dfrobot_unihiker_expansion import UnihikerExpansion, MotorNum, MPeriod

exp = UnihikerExpansion()

def setup():

    exp.set_motor_period("MOTOR1_2", 255)
    exp.set_motor_period("MOTOR3_4", 255)
    time.sleep(0.5)

def loop():   
    exp.set_motor_duty("MOTOR1_A", 255)
    exp.set_motor_duty("MOTOR1_B", 0)
    exp.set_motor_duty("MOTOR2_A", 0)
    exp.set_motor_duty("MOTOR2_B", 255)
    exp.set_motor_duty("MOTOR3_A", 20)
    exp.set_motor_duty("MOTOR3_B", 0)
    exp.set_motor_duty("MOTOR4_A", 0)
    exp.set_motor_duty("MOTOR4_B", 20)
    time.sleep(1)
    exp.set_motor_duty("MOTOR1_A", 0)
    exp.set_motor_duty("MOTOR1_B", 255)
    exp.set_motor_duty("MOTOR2_A", 255)
    exp.set_motor_duty("MOTOR2_B", 0)
    exp.set_motor_duty("MOTOR3_A", 0)
    exp.set_motor_duty("MOTOR3_B", 20)
    exp.set_motor_duty("MOTOR4_A", 20)
    exp.set_motor_duty("MOTOR4_B", 0)
    time.sleep(1)

def main():
    setup()
    while True:
        loop()

if __name__ == "__main__":
    main()
