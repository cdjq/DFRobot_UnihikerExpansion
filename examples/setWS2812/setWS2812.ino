 /*!
  * @file  setWS2812.ino
  * @brief set WS2812 color
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
  uint32_t led[2] = {0xff0000, 0x0000ff};
  uint8_t bright = 10;
  result  = eunihiker.setWS2812((uint32_t*)led, bright);
  if(result == 0){
    Serial.println("set WS2812 success");
  }
  delay(1000);
  uint32_t led1[2] = {0xffff00, 0xff00ff};
  result  = eunihiker.setWS2812((uint32_t*)led1, 100);
  if(result == 0){
    Serial.println("set WS2812 success");
  }
  delay(1000);  
}