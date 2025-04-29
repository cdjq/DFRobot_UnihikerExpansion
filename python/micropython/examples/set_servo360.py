# -*- coding: utf-8 -*
'''!
  @file set_servo360.py
  @brief set servo 360 degree 
  @copyright Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license The MIT License (MIT)
  @author [ZhixinLiu](zhixin.liu@dfrobot.com)
  @version V1.0
  @date 2025-04-29
  @url https://github.com/DFRobot/DFRobot_UnihikerExpansion
'''
import sys
import os
sys.path.append('../')
import time
from dfrobot_unihiker_expansion import UnihikerExpansion, ServoNum, Servo360Direction

exp = UnihikerExpansion()

def setup():
    pass

def loop():
    exp.set_servo360("SERVO0", "FORWARD", 10)
    exp.set_servo360("SERVO1", "FORWARD", 50)
    exp.set_servo360("SERVO2", "FORWARD", 100)
    exp.set_servo360("SERVO3", "FORWARD", 0)
    exp.set_servo360("SERVO4", "STOP", 0)
    exp.set_servo360("SERVO5", "FORWARD", 100)
    time.sleep(1)
    exp.set_servo360("SERVO0", "BACKWARD", 10)
    exp.set_servo360("SERVO1", "BACKWARD", 50)
    exp.set_servo360("SERVO2", "BACKWARD", 100)
    exp.set_servo360("SERVO3", "BACKWARD", 0)
    exp.set_servo360("SERVO4", "STOP", 0)
    exp.set_servo360("SERVO5", "BACKWARD", 10)
    time.sleep(1)

def main():
    setup()
    while True:
        loop()

if __name__ == "__main__":
    main()