# -*- coding: utf-8 -*
'''!
  @file set_gpio.py
  @brief set gpio
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
    exp.set_mode("C0", "GPIO_OUT")
    exp.set_mode("C1", "GPIO_OUT")
    exp.set_mode("C2", "GPIO_OUT")
    exp.set_mode("C3", "GPIO_OUT")
    exp.set_mode("C4", "GPIO_OUT")
    exp.set_mode("C5", "GPIO_OUT")


def loop():
    exp.set_gpio_state("C0", "HIGH")
    exp.set_gpio_state("C1", "HIGH")
    exp.set_gpio_state("C2", "HIGH")
    exp.set_gpio_state("C3", "HIGH")
    exp.set_gpio_state("C4", "HIGH")
    exp.set_gpio_state("C5", "HIGH")
    time.sleep(1)
    for pin in ["C0", "C1", "C2", "C3", "C4", "C5"]:
        state = exp.get_gpio_state(pin)
        print(f"{pin} out state = {state}")
    print("----------------")
    exp.set_gpio_state("C0", "LOW")
    exp.set_gpio_state("C1", "LOW")
    exp.set_gpio_state("C2", "LOW")
    exp.set_gpio_state("C3", "LOW")
    exp.set_gpio_state("C4", "LOW")
    exp.set_gpio_state("C5", "LOW")
    time.sleep(1)
    for pin in ["C0", "C1", "C2", "C3", "C4", "C5"]:
        state = exp.get_gpio_state(pin)
        print(f"{pin} out state = {state}")
    print("----------------")
def main():
    setup()
    while True:
        loop()

if __name__ == "__main__":
    main()
