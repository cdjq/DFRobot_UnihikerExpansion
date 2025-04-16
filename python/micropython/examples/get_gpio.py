# -*- coding: utf-8 -*
'''!
  @file get_gpio.py
  @brief get gpio state
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
from dfrobot_unihiker_expansion import UnihikerExpansion, IONum, IOType, GpioState

exp = UnihikerExpansion()

def setup():
    for pin in ["C0", "C1", "C2", "C3", "C4", "C5"]:
        exp.set_mode(pin, "GPIO_IN")

def loop():
    for pin in ["C0", "C1", "C2", "C3", "C4", "C5"]:
        state = exp.get_gpio_state(pin)
        print(f"{pin} state = {state}")
    print("--------------------")
    time.sleep(0.5)

def main():
    setup()
    while True:
        loop()

if __name__ == "__main__":
    main()
