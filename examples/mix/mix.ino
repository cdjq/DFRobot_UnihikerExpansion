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
  eunihiker.setMode(eC1, eDHT11);
  eunihiker.setMode(eC2, eDHT22);
  eunihiker.setMode(eC3, eDS18B20);
  eunihiker.setMode(eC4, eWriteGpio);
  eunihiker.setMode(eC5, eReadGpio);

  eunihiker.setMotorPeriod(eMotor1_2, 60000);
  eunihiker.setMotorPeriod(eMotor3_4, 20000);

  uint8_t battery = eunihiker.getBattery();
  Serial.print("Battery: = ");
  Serial.print(battery);
  Serial.println("%");
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
  
  Serial.print("C0 ADC is  = ");
  Serial.println(eunihiker.getADCValue(eC0));

  sDhtData_t dhtData;
  dhtData = eunihiker.getDHTValue(eC1);
  if(dhtData.state == DATA_ENABLE){
    Serial.print("C1 DHT11 humidity is ");
    Serial.print(dhtData.humidity);
    Serial.print(" temperature is ");
    Serial.println(dhtData.temperature);
  } Serial.println();
  
  dhtData = eunihiker.getDHTValue(eC2);
  if(dhtData.state == DATA_ENABLE){
    Serial.print("C2 DHT22 humidity is ");
    Serial.print(dhtData.humidity);
    Serial.print(" temperature is ");
    Serial.println(dhtData.temperature);
  } Serial.println();


  float data3 = eunihiker.get18b20Value(eC3);
  Serial.print("C3 DS18B20 temperature is ");
  Serial.println(data3);

  eunihiker.setGpioState(eC4, eHIGH);
  delay(100);
  Serial.print("C4 gpio state is ");
  Serial.println(eunihiker.getGpioState(eC4));
  eunihiker.setGpioState(eC4, eLOW);
  delay(100);
  Serial.print("C4 gpio state is ");
  Serial.println(eunihiker.getGpioState(eC4));

  Serial.print("C5 gpio state is ");
  Serial.println(eunihiker.getGpioState(eC5));

  int distance = eunihiker.getSr04Distance();
  Serial.print("distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  static uint32_t led[2] = {0xff0000, 0x00FF00};
  uint8_t bright = 10;
  led[0] += 0x10;
  led[1] += 0x10;
  eunihiker.setWS2812((uint32_t*)led, bright);

  eunihiker.setMotorDuty(eMotor1_A, 60000);
  eunihiker.setMotorDuty(eMotor1_B, 0);
  eunihiker.setMotorDuty(eMotor2_A, 0);
  eunihiker.setMotorDuty(eMotor2_B, 3000);
  eunihiker.setMotorDuty(eMotor3_A, 20000);
  eunihiker.setMotorDuty(eMotor3_B, 0);
  eunihiker.setMotorDuty(eMotor4_A, 0);
  eunihiker.setMotorDuty(eMotor4_B, 10);
  
  eunihiker.setServoAngle(eServo0, 0);
  eunihiker.setServoAngle(eServo1, 0);
  eunihiker.setServoAngle(eServo2, 0);
  eunihiker.setServoAngle(eServo3, 0);
  eunihiker.setServoAngle(eServo4, 0);
  eunihiker.setServoAngle(eServo5, 0);
  delay(1000);
  eunihiker.setServoAngle(eServo0, 30);
  eunihiker.setServoAngle(eServo1, 60);
  eunihiker.setServoAngle(eServo2, 90);
  eunihiker.setServoAngle(eServo3, 120);
  eunihiker.setServoAngle(eServo4, 150);
  eunihiker.setServoAngle(eServo5, 180);
  delay(1000);

  
}