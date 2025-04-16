# -*- coding: utf-8 -*
'''!
  @file set_servo.py
  @brief set servo angle
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
from dfrobot_unihiker_expansion import UnihikerExpansion, ServoNum

exp = UnihikerExpansion()

def setup():
    pass

def loop():
    exp.set_servo_angle("SERVO0", 0)
    exp.set_servo_angle("SERVO1", 0)
    exp.set_servo_angle("SERVO2", 0)
    exp.set_servo_angle("SERVO3", 0)
    exp.set_servo_angle("SERVO4", 0)
    exp.set_servo_angle("SERVO5", 0)
    time.sleep(1)
    exp.set_servo_angle("SERVO0", 30)
    exp.set_servo_angle("SERVO1", 60)
    exp.set_servo_angle("SERVO2", 90)
    exp.set_servo_angle("SERVO3", 120)
    exp.set_servo_angle("SERVO4", 150)
    exp.set_servo_angle("SERVO5", 180)
    time.sleep(1)

def main():
    setup()
    while True:
        loop()

if __name__ == "__main__":
    main()
