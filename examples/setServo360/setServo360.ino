 /*!
  * @file  setServo360.ino
  * @brief drive servo360 
  * @copyright Copyright (c) 2025 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @license The MIT License (MIT)
  * @author ZhixinLiu(zhixin.liu@dfrobot.com)
  * @version V1.0.0
  * @date 2025-04-28
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
    eunihiker.setServo360(eServo0, eForward, 10);
    eunihiker.setServo360(eServo1, eForward, 50);
    eunihiker.setServo360(eServo2, eForward, 100);
    eunihiker.setServo360(eServo3, eForward, 0);
    eunihiker.setServo360(eServo4, eStop, 0);
    eunihiker.setServo360(eServo5, eForward, 100);
    delay(2000);
    eunihiker.setServo360(eServo0, eBackward, 10);
    eunihiker.setServo360(eServo1, eForward, 50);
    eunihiker.setServo360(eServo2, eBackward, 100);
    eunihiker.setServo360(eServo3, eBackward, 0);
    eunihiker.setServo360(eServo4, eStop, 0);
    eunihiker.setServo360(eServo5, eBackward, 10);
    delay(2000);
  }