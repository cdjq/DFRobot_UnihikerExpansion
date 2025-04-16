# -*- coding: utf-8 -*-
import time
from pinpong.board import Board
from pinpong.libs.dfrobot_unihiker_expansion import UnihikerExpansion, IONum, IOType

Board("").begin()
eunihiker = UnihikerExpansion() 
eunihiker.set_mode(IONum.C0, IOType.DS18B20)
eunihiker.set_mode(IONum.C1, IOType.DS18B20)
eunihiker.set_mode(IONum.C2, IOType.DS18B20)
eunihiker.set_mode(IONum.C3, IOType.DS18B20)
eunihiker.set_mode(IONum.C4, IOType.DS18B20)
eunihiker.set_mode(IONum.C5, IOType.DS18B20)


while True:
    for pin in [IONum.C0, IONum.C1, IONum.C2, IONum.C3, IONum.C4, IONum.C5]:
        data = eunihiker.get_18b20_value(pin)
        print(f"{pin} ds18b20 temp = {data}")
    print("")
    time.sleep(1)
