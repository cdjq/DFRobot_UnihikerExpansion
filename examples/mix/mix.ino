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
    k10.setMode(eC1, eDHT11);
    k10.setMode(eC2, eDHT22);
    k10.setMode(eC3, eDS18B20);
    k10.setMode(eC4, eWriteGpio);
    k10.setMode(eC5, eReadGpio);

    k10.setMotorPeriod(eMotor1_2, 60000);
    k10.setMotorPeriod(eMotor3_4, 20000);

    uint8_t battery = k10.getBattery();
    Serial.print("Battery: = ");
    Serial.print(battery);
    Serial.println("%");

  }
  
  void loop()
  {

    uint8_t result = 0;
    result = k10.sendIR(0x12345678);
    if(result == 0){
      Serial.println("send IR data success");
    }
    uint32_t irData = k10.getIRData();
    Serial.print("IR Data: = ");
    Serial.println(irData, HEX);    
    
    Serial.print("C0 ADC is  = ");
    Serial.println(k10.getADCValue(eC0));

    sDhtData_t dhtData;
    dhtData = k10.getDHTValue(eC1);
    if(dhtData.state == DATA_ENABLE){
      Serial.print("C1 DHT11 humidity is ");
      Serial.print(dhtData.humidity);
      Serial.print(" temperature is ");
      Serial.println(dhtData.temperature);
    } Serial.println();
    
    dhtData = k10.getDHTValue(eC2);
    if(dhtData.state == DATA_ENABLE){
      Serial.print("C2 DHT22 humidity is ");
      Serial.print(dhtData.humidity);
      Serial.print(" temperature is ");
      Serial.println(dhtData.temperature);
    } Serial.println();


    float data3 = k10.get18b20Value(eC3);
    Serial.print("C3 DS18B20 temperature is ");
    Serial.println(data3);

    k10.setGpioState(eC4, eHIGH);
    delay(100);
    Serial.print("C4 gpio state is ");
    Serial.println(k10.getGpioState(eC4));
    k10.setGpioState(eC4, eLOW);
    delay(100);
    Serial.print("C4 gpio state is ");
    Serial.println(k10.getGpioState(eC4));

    Serial.print("C5 gpio state is ");
    Serial.println(k10.getGpioState(eC5));

    int distance = k10.getSr04Distance();
    Serial.print("distance = ");
    Serial.print(distance);
    Serial.println(" cm");

    static uint32_t led[2] = {0xff0000, 0x00FF00};
    uint8_t bright = 10;
    led[0] += 0x10;
    led[1] += 0x10;
    k10.setWS2812((uint32_t*)led, bright);

    k10.setMotorDuty(eMotor1_A, 60000);
    k10.setMotorDuty(eMotor1_B, 0);
    k10.setMotorDuty(eMotor2_A, 0);
    k10.setMotorDuty(eMotor2_B, 3000);
    k10.setMotorDuty(eMotor3_A, 20000);
    k10.setMotorDuty(eMotor3_B, 0);
    k10.setMotorDuty(eMotor4_A, 0);
    k10.setMotorDuty(eMotor4_B, 10);
    
    k10.setServoAngle(eServo0, 0);
    k10.setServoAngle(eServo1, 0);
    k10.setServoAngle(eServo2, 0);
    k10.setServoAngle(eServo3, 0);
    k10.setServoAngle(eServo4, 0);
    k10.setServoAngle(eServo5, 0);
    delay(1000);
    k10.setServoAngle(eServo0, 30);
    k10.setServoAngle(eServo1, 60);
    k10.setServoAngle(eServo2, 90);
    k10.setServoAngle(eServo3, 120);
    k10.setServoAngle(eServo4, 150);
    k10.setServoAngle(eServo5, 180);
    delay(1000);

    
  }