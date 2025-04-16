# -*- coding: utf-8 -*-
import time
from pinpong.board import Board
from pinpong.libs.dfrobot_unihiker_expansion import UnihikerExpansion

Board("").begin()

eunihiker = UnihikerExpansion() 

while True:
    ir_data = eunihiker.get_ir_data()
    if ir_data != 0:    
        print(f"ir recv data = {ir_data}")
    time.sleep(0.5)
  