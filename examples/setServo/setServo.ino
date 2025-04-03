 /*!
  * @file  setServo.ino
  * @brief set servo angle
  * @copyright Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @license The MIT License (MIT)
  * @author ZhixinLiu(zhixin.liu@dfrobot.com)
  * @version V1.0.0
  * @date 2025-04-03
  * @url https://github.com/DFRobot/DFRobot_UnihikerExpansion
  */

  #include "DFRobot_UnihikerExpansion.h"
  DFRobot_UnihikerExpansion_I2C eunihiker(&Wire);
  void setup()
  {
    Serial.begin(115200);
    while(!eunihiker.begin()){
      Serial.println("NO Deivces !");
      delay(1000);
    } Serial.println("Device connected !");
  }
  
  void loop()
  {
    eunihiker.setServoAngle(eServo0, 0);
    eunihiker.setServoAngle(eServo1, 0);
    eunihiker.setServoAngle(eServo2, 0);
    eunihiker.setServoAngle(eServo3, 0);
    eunihiker.setServoAngle(eServo4, 0);
    eunihiker.setServoAngle(eServo5, 0);
    delay(1000);
    eunihiker.setServoAngle(eServo0, 30);
    eunihiker.setServoAngle(eServo1, 60);
    eunihiker.setServoAngle(eServo2, 90);
    eunihiker.setServoAngle(eServo3, 120);
    eunihiker.setServoAngle(eServo4, 150);
    eunihiker.setServoAngle(eServo5, 180);
    delay(1000);
  }