# -*- coding: utf-8 -*-
import time
from pinpong.board import Board
from pinpong.libs.dfrobot_unihiker_expansion import UnihikerExpansion, ServoNum

Board("").begin()

eunihiker = UnihikerExpansion() 

while True:
    eunihiker.set_servo_angle(ServoNum.SERVO0, 0)
    eunihiker.set_servo_angle(ServoNum.SERVO1, 0)
    eunihiker.set_servo_angle(ServoNum.SERVO2, 0)
    eunihiker.set_servo_angle(ServoNum.SERVO3, 0)
    eunihiker.set_servo_angle(ServoNum.SERVO4, 0)
    eunihiker.set_servo_angle(ServoNum.SERVO5, 0)
    time.sleep(1)
    
    eunihiker.set_servo_angle(ServoNum.SERVO0, 30)
    eunihiker.set_servo_angle(ServoNum.SERVO1, 60)
    eunihiker.set_servo_angle(ServoNum.SERVO2, 90)
    eunihiker.set_servo_angle(ServoNum.SERVO3, 120)
    eunihiker.set_servo_angle(ServoNum.SERVO4, 150)
    eunihiker.set_servo_angle(ServoNum.SERVO5, 180)
    time.sleep(1)