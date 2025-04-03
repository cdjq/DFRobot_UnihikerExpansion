 /*!
  * @file  getBattery.ino
  * @brief get battery
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
  uint8_t result = 0;
  result = eunihiker.sendIR(0x12345678);
  if(result == 0){
    Serial.println("send IR data success");
  }
  uint32_t irData = eunihiker.getIRData();
  Serial.print("IR Data: = ");
  Serial.println(irData, HEX);    
  delay(1000);
}