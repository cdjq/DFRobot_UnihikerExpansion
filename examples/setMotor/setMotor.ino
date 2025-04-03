 /*!
  * @file  setMotor.ino
  * @brief set motor duty
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
  eunihiker.setMotorPeriod(eMotor1_2, 60000);
  eunihiker.setMotorPeriod(eMotor3_4, 20000);
}

void loop()
{
  eunihiker.setMotorDuty(eMotor1_A, 60000);
  eunihiker.setMotorDuty(eMotor1_B, 0);

  eunihiker.setMotorDuty(eMotor2_A, 0);
  eunihiker.setMotorDuty(eMotor2_B, 3000);


  eunihiker.setMotorDuty(eMotor3_A, 20000);
  eunihiker.setMotorDuty(eMotor3_B, 0);
  
  eunihiker.setMotorDuty(eMotor4_A, 0);
  eunihiker.setMotorDuty(eMotor4_B, 10);
  delay(1000);
}