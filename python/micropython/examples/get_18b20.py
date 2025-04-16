# -*- coding: utf-8 -*
'''!
  @file get_18b20.py
  @brief get 18b20 temp
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
from dfrobot_unihiker_expansion import UnihikerExpansion, IONum, IOType

exp = UnihikerExpansion()

def setup():
    for pin in ["C0", "C1", "C2", "C3", "C4", "C5"]:
        exp.set_mode(pin, "DS18B20")

def loop():
    for pin in ["C0", "C1", "C2", "C3", "C4", "C5"]:
        temp = exp.get_18b20_value(pin)
        print(f"{pin} Temp = {temp}°C")
    print("--------------------")
    time.sleep(1)

def main():
    setup()
    while True:
        loop()

if __name__ == "__main__":
    main()
