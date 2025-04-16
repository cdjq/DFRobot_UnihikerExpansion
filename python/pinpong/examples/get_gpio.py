# -*- coding: utf-8 -*-
import time
from pinpong.board import Board
from pinpong.libs.dfrobot_unihiker_expansion import UnihikerExpansion, IONum, IOType, GpioState

Board("").begin()

eunihiker = UnihikerExpansion() 
eunihiker.set_mode(IONum.C0, IOType.GPIO_IN)
eunihiker.set_mode(IONum.C1, IOType.GPIO_IN)
eunihiker.set_mode(IONum.C2, IOType.GPIO_IN)
eunihiker.set_mode(IONum.C3, IOType.GPIO_IN)
eunihiker.set_mode(IONum.C4, IOType.GPIO_IN)
eunihiker.set_mode(IONum.C5, IOType.GPIO_IN)


while True:
    for pin in [IONum.C0, IONum.C1, IONum.C2, IONum.C3, IONum.C4, IONum.C5]:
        state = eunihiker.get_gpio_state(pin)
        print(f"{pin} state = {state}")
    print("") 
    time.sleep(1)