 /*!
  * @file  setMotor.ino
  * @brief set Motor
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
    k10.setMotorPeriod(eMotor1_2, 60000);
    k10.setMotorPeriod(eMotor3_4, 20000);
  }
  
  void loop()
  {
    k10.setMotorDuty(eMotor1_A, 60000);
    k10.setMotorDuty(eMotor1_B, 0);

    k10.setMotorDuty(eMotor2_A, 0);
    k10.setMotorDuty(eMotor2_B, 3000);


    k10.setMotorDuty(eMotor3_A, 20000);
    k10.setMotorDuty(eMotor3_B, 0);
    
    k10.setMotorDuty(eMotor4_A, 0);
    k10.setMotorDuty(eMotor4_B, 10);
    
    delay(1000);
  }