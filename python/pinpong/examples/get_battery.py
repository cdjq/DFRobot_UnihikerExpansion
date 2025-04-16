# -*- coding: utf-8 -*-
import time
from pinpong.board import Board
from pinpong.libs.dfrobot_unihiker_expansion import UnihikerExpansion

Board("").begin()

eunihiker = UnihikerExpansion() 

while True:
    battery = eunihiker.get_battery()
    print(f"battery value is {battery} %")
