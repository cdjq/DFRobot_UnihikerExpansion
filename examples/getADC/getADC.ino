 /*!
  * @file  getADC.ino
  * @brief get adc value
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
  eunihiker.setMode(eC0, eADC);
  eunihiker.setMode(eC1, eADC);
  eunihiker.setMode(eC2, eADC);
  eunihiker.setMode(eC3, eADC);
  eunihiker.setMode(eC4, eADC);
  eunihiker.setMode(eC5, eADC);
}

void loop()
{
  for(uint8_t i = 0; i < 6; i++){
    Serial.print("C");
    Serial.print(i);
    Serial.print(" ADC value = ");
    Serial.println(eunihiker.getADCValue((eIONumber_t)i));
  } Serial.println();
  delay(100);
}