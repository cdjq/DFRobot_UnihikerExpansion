 /*!
  * @file  get18b20.ino
  * @brief get DS18b20 data
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
    k10.setMode(eC0, eDS18B20);
    k10.setMode(eC1, eDS18B20);
    k10.setMode(eC2, eDS18B20);
    k10.setMode(eC3, eDS18B20);
    k10.setMode(eC4, eDS18B20);
    k10.setMode(eC5, eDS18B20);
  }
  
  void loop()
  {
    float data0 = 0.0f;
    float data1 = 0.0f;
    float data2 = 0.0f;
    float data3 = 0.0f;
    float data4 = 0.0f;
    float data5 = 0.0f;
    data0 = k10.get18b20Value(eC0);
    data1 = k10.get18b20Value(eC1);
    data2 = k10.get18b20Value(eC2);
    data3 = k10.get18b20Value(eC3);
    data4 = k10.get18b20Value(eC4);
    data5 = k10.get18b20Value(eC5);
    Serial.print("C0 DS18B20 temperature is ");
    Serial.println(data0);
    Serial.print("C1 DS18B20 temperature is ");
    Serial.println(data1);
    Serial.print("C2 DS18B20 temperature is ");
    Serial.println(data2);
    Serial.print("C3 DS18B20 temperature is ");
    Serial.println(data3);
    Serial.print("C4 DS18B20 temperature is ");
    Serial.println(data4);
    Serial.print("C5 DS18B20 temperature is ");
    Serial.println(data5);
    Serial.println();
    delay(1000);
  }