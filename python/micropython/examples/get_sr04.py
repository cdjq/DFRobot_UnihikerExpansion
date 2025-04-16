# -*- coding: utf-8 -*
'''!
  @file get_sr04.py
  @brief get sr04 distance
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
from dfrobot_unihiker_expansion import UnihikerExpansion

exp = UnihikerExpansion()

def setup():
    pass

def loop():
    distance = exp.get_sr04_distance()
    if distance < 0:
        print("SR04 Measurement Failed")
    else:
        print(f"Distance = {distance} cm")
    time.sleep(0.5)

def main():
    setup()
    while True:
        loop()

if __name__ == "__main__":
    main()
