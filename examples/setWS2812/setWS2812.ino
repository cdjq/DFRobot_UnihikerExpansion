 /*!
  * @file  setWS2812.ino
  * @brief set WS2812
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
  
  }
  
  void loop()
  {
    uint8_t result = 0;
    uint32_t led[2] = {0xff0000, 0x0000ff};
    uint8_t bright = 10;
    result  = k10.setWS2812((uint32_t*)led, bright);
    if(result == 0){
      Serial.println("set WS2812 success");
    }
    delay(1000);
  }