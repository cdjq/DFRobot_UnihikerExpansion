# -*- coding: utf-8 -*-
import time
from pinpong.board import Board
from pinpong.libs.dfrobot_unihiker_expansion import UnihikerExpansion

Board("").begin()

eunihiker = UnihikerExpansion() 

while True:
    distance = eunihiker.get_sr04_distance()
    if distance < 0:
      print("sr04 messure failed ")
    else:
      print(f"distance = {distance} cm")
    time.sleep(0.2)