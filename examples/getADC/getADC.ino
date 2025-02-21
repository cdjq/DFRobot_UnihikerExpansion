 /*!
  * @file  getADC.ino
  * @brief get adc value
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
    k10.setMode(eC0, eADC);
    k10.setMode(eC1, eADC);
    k10.setMode(eC2, eADC);
    k10.setMode(eC3, eADC);
    k10.setMode(eC4, eADC);
    k10.setMode(eC5, eADC);
  }
  
  void loop()
  {
    for(uint8_t i = 0; i < 6; i++){
      Serial.print("C");
      Serial.print(i);
      Serial.print(" ADC is ");
      Serial.println(k10.getADCValue((eNumber_t)i));
    } Serial.println();
    delay(100);
  }