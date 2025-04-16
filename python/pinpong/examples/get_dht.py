# -*- coding: utf-8 -*-
import time
from pinpong.board import Board
from pinpong.libs.dfrobot_unihiker_expansion import UnihikerExpansion, IONum, IOType

Board("").begin()

eunihiker = UnihikerExpansion() 
eunihiker.set_mode(IONum.C0, IOType.ADC)
eunihiker.set_mode(IONum.C1, IOType.DHT11)
eunihiker.set_mode(IONum.C2, IOType.DHT22)
eunihiker.set_mode(IONum.C3, IOType.ADC)
eunihiker.set_mode(IONum.C4, IOType.ADC)
eunihiker.set_mode(IONum.C5, IOType.ADC)



while True:
    for pin in [IONum.C0, IONum.C1, IONum.C2, IONum.C3, IONum.C4, IONum.C5]:
        dht_data = eunihiker.get_dht_value(pin)
        if dht_data.state == eunihiker.DATA_ENABLE:
            print(f"{pin} dht temperature = {dht_data.temperature}")
            print(f"{pin} dht humidity = {dht_data.humidity}")
    print("")
    time.sleep(1)
