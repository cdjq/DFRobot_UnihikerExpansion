# -*- coding: utf-8 -*-
import time
from pinpong.board import Board
from pinpong.libs.dfrobot_unihiker_expansion import UnihikerExpansion, ServoNum, Servo360Direction  

Board("").begin()

eunihiker = UnihikerExpansion() 

while True:
    eunihiker.set_servo360(ServoNum.SERVO0, Servo360Direction.FORWARD, 10)
    eunihiker.set_servo360(ServoNum.SERVO1, Servo360Direction.FORWARD, 50)
    eunihiker.set_servo360(ServoNum.SERVO2, Servo360Direction.FORWARD, 100)
    eunihiker.set_servo360(ServoNum.SERVO3, Servo360Direction.FORWARD, 0)
    eunihiker.set_servo360(ServoNum.SERVO4, Servo360Direction.STOP, 0)
    eunihiker.set_servo360(ServoNum.SERVO5, Servo360Direction.FORWARD, 100)
    time.sleep(1)
    eunihiker.set_servo360(ServoNum.SERVO0, Servo360Direction.BACKWARD, 10)
    eunihiker.set_servo360(ServoNum.SERVO1, Servo360Direction.BACKWARD, 0)
    eunihiker.set_servo360(ServoNum.SERVO2, Servo360Direction.BACKWARD, 100)
    eunihiker.set_servo360(ServoNum.SERVO3, Servo360Direction.BACKWARD, 0)
    eunihiker.set_servo360(ServoNum.SERVO4, Servo360Direction.STOP, 0)
    eunihiker.set_servo360(ServoNum.SERVO5, Servo360Direction.BACKWARD, 10)
    time.sleep(1)