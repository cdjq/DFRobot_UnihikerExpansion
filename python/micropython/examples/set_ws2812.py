# -*- coding: utf-8 -*-
'''!
  @file set_ws2812.py
  @brief Control WS2812 RGB LEDs using Unihiker Expansion Board
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
from dfrobot_unihiker_expansion import UnihikerExpansion, RgbNum

# Instantiate the Unihiker Expansion board object
exp = UnihikerExpansion()

# Define a list of colors in RGB hexadecimal format
COLORS = [
    0xFF0000,  # Red
    0x00FF00,  # Green
    0x0000FF,  # Blue
    0xFFFF00,  # Yellow
    0xFF00FF,  # Magenta
    0x000000,  # Off (Black)
    0x00FFFF   # Cyan
]

def setup():
    exp.set_bright(5)  # Brightness level (range 0–255)

def loop():
    for color in COLORS:
        exp.set_ws2812("RGB0", color)  # Set color on RGB0
        exp.set_ws2812("RGB1", color)  # Set color on RGB1
        time.sleep(0.1)  # Delay between changes

def main():
    setup()
    while True:
        loop()

# If this script is run directly, execute the main function
if __name__ == "__main__":
    main()

