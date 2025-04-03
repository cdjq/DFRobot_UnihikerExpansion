 /*!
  * @file  get18b20.ino
  * @brief get DS18b20 temp data
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
  eunihiker.setMode(eC0, eDS18B20);
  eunihiker.setMode(eC1, eDS18B20);
  eunihiker.setMode(eC2, eDS18B20);
  eunihiker.setMode(eC3, eDS18B20);
  eunihiker.setMode(eC4, eDS18B20);
  eunihiker.setMode(eC5, eDS18B20);
}

void loop()
{
  float data0 = 0.0f;
  float data1 = 0.0f;
  float data2 = 0.0f;
  float data3 = 0.0f;
  float data4 = 0.0f;
  float data5 = 0.0f;
  data0 = eunihiker.get18b20Value(eC0);
  data1 = eunihiker.get18b20Value(eC1);
  data2 = eunihiker.get18b20Value(eC2);
  data3 = eunihiker.get18b20Value(eC3);
  data4 = eunihiker.get18b20Value(eC4);
  data5 = eunihiker.get18b20Value(eC5);
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