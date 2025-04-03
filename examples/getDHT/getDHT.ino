 /*!
  * @file  getDHT.ino
  * @brief get DHT data
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
  eunihiker.setMode(eC0, eDHT11);
  eunihiker.setMode(eC1, eDHT22);
  eunihiker.setMode(eC2, eDHT11);
  eunihiker.setMode(eC3, eDHT11);
  eunihiker.setMode(eC4, eDHT11);
  eunihiker.setMode(eC5, eDHT11);
}

void loop()
{
  sDhtData_t dhtData;
  dhtData = eunihiker.getDHTValue(eC0);
  if(dhtData.state == DATA_ENABLE){
    Serial.print("C0 DHT11 humidity is ");
    Serial.print(dhtData.humidity);
    Serial.print(" temperature is ");
    Serial.println(dhtData.temperature);
  } Serial.println();
  
  dhtData = eunihiker.getDHTValue(eC1);
  if(dhtData.state == DATA_ENABLE){
    Serial.print("C1 DHT22 humidity is ");
    Serial.print(dhtData.humidity);
    Serial.print(" temperature is ");
    Serial.println(dhtData.temperature);
  } Serial.println();
  delay(1000);
}