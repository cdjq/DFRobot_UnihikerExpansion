# -*- coding: utf-8 -*-
import sys
import os
sys.path.append('../')
from dfrobot_unihiker_expansion import *

exp = UnihikerExpansion()
while True:
    battery = exp.get_battery()
    print(f"Battery: {battery}%")
    time.sleep(1)