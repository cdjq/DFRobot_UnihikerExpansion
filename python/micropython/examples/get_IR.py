# -*- coding: utf-8 -*
'''!
  @file get_IR.py
  @brief get IR
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
    #exp.send_ir(0x12345678)
    time.sleep(0.1)
    ir_data = exp.get_ir_data()
    if ir_data != 0:
        print(f"IR Received: {hex(ir_data)}")
    time.sleep(0.5)

def main():
    setup()
    while True:
        loop()

if __name__ == "__main__":
    main()
