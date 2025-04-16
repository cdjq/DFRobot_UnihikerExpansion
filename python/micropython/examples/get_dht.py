# -*- coding: utf-8 -*
'''!
  @file get_dht.py
  @brief get dht temp hum
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
    exp.set_mode("C1", "DHT11")
    exp.set_mode("C2", "DHT22")
    
def loop():
    dht11_data = exp.get_dht_value("C1")
    if dht11_data.state == exp.DATA_ENABLE:
        print("[DHT11] Temperature: {:.1f}°C, Humidity: {:.1f}%".format(dht11_data.temperature, dht11_data.humidity))
    else:
        print("DHT11 read failed!")

    dht22_data = exp.get_dht_value("C2")
    if dht22_data.state == exp.DATA_ENABLE:
        print("[DHT22] Temperature: {:.1f}°C, Humidity: {:.1f}%".format(
            dht22_data.temperature,
            dht22_data.humidity
        ))
    else:
        print("DHT22 read failed!")
    
    print("--------------------")
    time.sleep(1)

def main():
    setup()
    while True:
        loop()

if __name__ == "__main__":
    main()
