 /*!
  * @file  setServo.ino
  * @brief set Servo
  * @copyright Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @license The MIT License (MIT)
  * @author ZhixinLiu(zhixin.liu@dfrobot.com)
  * @version V0.1.0
  * @date 2025-02-13
  * @url https://github.com/DFRobot/DFRobot_K10_Expansion
  */

  #include "DFRobot_K10_Expansion.h"

  
  DFRobot_K10_Expansion_I2C k10(&Wire);
  void setup()
  {
    Serial.begin(115200);
    while(!k10.begin()){
      Serial.println("NO Deivces !");
      delay(1000);
    }
    Serial.println("Device connected !");
  
  }
  
  void loop()
  {
    k10.setServoAngle(eServo0, 0);
    k10.setServoAngle(eServo1, 0);
    k10.setServoAngle(eServo2, 0);
    k10.setServoAngle(eServo3, 0);
    k10.setServoAngle(eServo4, 0);
    k10.setServoAngle(eServo5, 0);
    delay(1000);
    k10.setServoAngle(eServo0, 30);
    k10.setServoAngle(eServo1, 60);
    k10.setServoAngle(eServo2, 90);
    k10.setServoAngle(eServo3, 120);
    k10.setServoAngle(eServo4, 150);
    k10.setServoAngle(eServo5, 180);
    delay(1000);
  }