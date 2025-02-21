 /*!
  * @file  setGpio.ino
  * @brief set gpio
  * @copyright Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @license The MIT License (MIT)
  * @author ZhixinLiu(zhixin.liu@dfrobot.com)
  * @version V0.1.0
  * @date 2025-02-13
  * @url https://github.com/DFRobot/DFRobot_K10_Expansion
  */

  #include "DFRobot_K10_Expansion.h"

  // must use iic config parameter
  DFRobot_K10_Expansion_I2C k10(&Wire);
  void setup()
  {
    Serial.begin(115200);
    while(!k10.begin()){
      Serial.println("NO Deivces !");
      delay(1000);
    }
    Serial.println("Device connected !");
    k10.setMode(eC0, eWriteGpio);
    k10.setMode(eC1, eWriteGpio);
    k10.setMode(eC2, eWriteGpio);
    k10.setMode(eC3, eWriteGpio);
    k10.setMode(eC4, eWriteGpio);
    k10.setMode(eC5, eWriteGpio);
  }
  
  void loop()
  {
    k10.setGpioState(eC0, eHIGH);
    k10.setGpioState(eC1, eHIGH);
    k10.setGpioState(eC2, eHIGH);
    k10.setGpioState(eC3, eHIGH);
    k10.setGpioState(eC4, eHIGH);
    k10.setGpioState(eC5, eHIGH);
    for(uint8_t i = 0; i < 6; i++){
      Serial.print("C");
      Serial.print(i);
      Serial.print(" state is ");
      Serial.println(k10.getGpioState((eNumber_t)i));
    }
    delay(1000);
    k10.setGpioState(eC0, eLOW);
    k10.setGpioState(eC1, eLOW);
    k10.setGpioState(eC2, eLOW);
    k10.setGpioState(eC3, eLOW);
    k10.setGpioState(eC4, eLOW);
    k10.setGpioState(eC5, eLOW);
    for(uint8_t i = 0; i < 6; i++){
      Serial.print("C");
      Serial.print(i);
      Serial.print(" state is ");
      Serial.println(k10.getGpioState((eNumber_t)i));
    }
    delay(1000);
  }