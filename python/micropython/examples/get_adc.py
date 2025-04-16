# -*- coding: utf-8 -*
'''!
  @file get_adc.py
  @brief get adc
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
        exp.set_mode(pin, "ADC")

def loop():
    for pin in ["C0", "C1", "C2", "C3", "C4", "C5"]:
        value = exp.get_adc_value(pin)
        print(f"{pin} ADC = {value}")
    print("--------------------")
    time.sleep(1)

def main():
    setup()
    while True:
        loop()

if __name__ == "__main__":
    main()
