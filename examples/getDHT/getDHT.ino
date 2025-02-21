 /*!
  * @file  getDHT.ino
  * @brief get DHT data
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
    k10.setMode(eC0, eDHT11);
    k10.setMode(eC1, eDHT22);
    k10.setMode(eC2, eDHT11);
    k10.setMode(eC3, eDHT11);
    k10.setMode(eC4, eDHT11);
    k10.setMode(eC5, eDHT11);
  }
  
  void loop()
  {
    sDhtData_t dhtData;
    dhtData = k10.getDHTValue(eC0);
    if(dhtData.state == DATA_ENABLE){
      Serial.print("C0 DHT11 humidity is ");
      Serial.print(dhtData.humidity);
      Serial.print(" temperature is ");
      Serial.println(dhtData.temperature);
    } Serial.println();
    
    dhtData = k10.getDHTValue(eC1);
    if(dhtData.state == DATA_ENABLE){
      Serial.print("C1 DHT22 humidity is ");
      Serial.print(dhtData.humidity);
      Serial.print(" temperature is ");
      Serial.println(dhtData.temperature);
    } Serial.println();
    
    delay(1000);
  }