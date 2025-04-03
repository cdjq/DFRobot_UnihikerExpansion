 /*!
  * @file  setGpio.ino
  * @brief set gpio
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
    eunihiker.setMode(eC0, eWriteGpio);
    eunihiker.setMode(eC1, eWriteGpio);
    eunihiker.setMode(eC2, eWriteGpio);
    eunihiker.setMode(eC3, eWriteGpio);
    eunihiker.setMode(eC4, eWriteGpio);
    eunihiker.setMode(eC5, eWriteGpio);
  }
  
  void loop()
  {
    eunihiker.setGpioState(eC0, eHIGH);
    eunihiker.setGpioState(eC1, eHIGH);
    eunihiker.setGpioState(eC2, eHIGH);
    eunihiker.setGpioState(eC3, eHIGH);
    eunihiker.setGpioState(eC4, eHIGH);
    eunihiker.setGpioState(eC5, eHIGH);
    for(uint8_t i = 0; i < 6; i++){
      Serial.print("C");
      Serial.print(i);
      Serial.print(" state is ");
      Serial.println(eunihiker.getGpioState((eIONumber_t)i));
    }
    delay(1000);
    eunihiker.setGpioState(eC0, eLOW);
    eunihiker.setGpioState(eC1, eLOW);
    eunihiker.setGpioState(eC2, eLOW);
    eunihiker.setGpioState(eC3, eLOW);
    eunihiker.setGpioState(eC4, eLOW);
    eunihiker.setGpioState(eC5, eLOW);
    for(uint8_t i = 0; i < 6; i++){
      Serial.print("C");
      Serial.print(i);
      Serial.print(" state is ");
      Serial.println(eunihiker.getGpioState((eIONumber_t)i));
    }
    delay(1000);
  }