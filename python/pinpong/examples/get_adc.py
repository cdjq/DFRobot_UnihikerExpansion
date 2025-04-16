# -*- coding: utf-8 -*-
import time
from pinpong.board import Board
from pinpong.libs.dfrobot_unihiker_expansion import UnihikerExpansion, IONum, IOType

Board("").begin()

eunihiker = UnihikerExpansion() 
eunihiker.set_mode(IONum.C0, IOType.ADC)
eunihiker.set_mode(IONum.C1, IOType.ADC)
eunihiker.set_mode(IONum.C2, IOType.ADC)
eunihiker.set_mode(IONum.C3, IOType.ADC)
eunihiker.set_mode(IONum.C4, IOType.ADC)
eunihiker.set_mode(IONum.C5, IOType.ADC)


while True:
    for pin in [IONum.C0, IONum.C1, IONum.C2, IONum.C3, IONum.C4, IONum.C5]:
        adcvalue = eunihiker.get_adc_value(pin)
        print(f"{pin} adc value = {adcvalue}")
    print("")
    time.sleep(1)
