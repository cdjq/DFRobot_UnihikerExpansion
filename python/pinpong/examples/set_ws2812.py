# -*- coding: utf-8 -*-
import time
from pinpong.board import Board
from pinpong.libs.dfrobot_unihiker_expansion import UnihikerExpansion, RgbNum

Board("").begin()

eunihiker = UnihikerExpansion() 
eunihiker.set_ws2812(RgbNum.RGB0, 0xFF00FF)
eunihiker.set_ws2812(RgbNum.RGB1, 0x0000FF)

while True:
    eunihiker.set_bright(5)
    time.sleep(1)
    eunihiker.set_bright(10)
    time.sleep(1)