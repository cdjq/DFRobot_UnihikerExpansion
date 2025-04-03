# DFRobot_UnihikerExpansion
- [中文版](./README_CN.md)


![效果图](resources/images/xxx.jpg)

## Product Link(https://www.dfrobot.com)

    SKU：DFR1216

## Table of Contents

* [Summary](#Summary)
* [Installation](#Installation)
* [Methods](#Methods)
* [Compatibility](#Compatibility)
* [History](#History)
* [Credits](#Credits)

## Summary

Provide an Arduino library for the k10 Expansion module with the following features:
    Obtain gpio, dht11, dht22, ds18b20, adc, battery, sr04, ir data
    Set ws2812, gpio, servo, motor
    Transmitting infrared

## Installation
There are two methods for using this library:<br>
1. Open Arduino IDE, search for "DFRobot_UnihikerExpansion" on the status bar in Tools ->Manager Libraries and install the library.<br>
2. Download the library file before use, paste it into \Arduino\libraries directory, then open the examples folder and run the demo in the folder.<br>

## Methods

```C++
/**
   * @fn: getBattery
   * @brief: Get the k10's power
   * @return: uint8_t 0-100 percentage
   */
  uint8_t getBattery(void);

  /**
   * @fn: getIRData
   * @brief: Get the IR data
   * @return uint32_t Infrared coding
   */
  uint32_t getIRData(void);

  /**
   * @fn: sendIR
   * @brief: Send the IR data
   * @param data: The infrared code to be sent
   * @return: uint8_t result
   * @retval: 0x00 is success
   * @retval: 0xff is failure
   */
  uint8_t sendIR(uint32_t data);

  /**
   * @fn: setWS2812
   * @brief: Set the WS2812 LED
   * @param data: The color of the LED
   * @param bright: Brightness 0-255
   * @return: uint8_t result
   * @retval: 0x00 is success
   * @retval: 0xff is failure
   */  
  uint8_t setWS2812(uint32_t *data, uint8_t bright);
  
  /**
   * @fn: setMode
   * @brief: set io port mode
   * @return: uint8_t result
   * @retval: 0x00 is success
   * @retval: 0xff is failure
   */
  uint8_t setMode(eIONumber_t number, eIOType_t mode);


  /**
   * @fn: setGpioState
   * @brief: Set the GPIO state
   * @param number: GPIO number
   * @param state: GPIO state
   * @return: uint8_t result
   * @retval: 0x00 is success
   * @retval: 0xff is failure
   */
  uint8_t setGpioState(eIONumber_t number, eGpioState_t state);

  /**
   * @fn: getGpioState
   * @brief: Get the io state
   * @param number: io number
   * @return: uint8_t Pin level 
   */
  uint8_t getGpioState(eIONumber_t number);

  /**
   * @fn: getADCValue
   * @brief: Get the ADC value
   * @param number: io number
   * @return: uint16_t adc value
   */
  uint16_t getADCValue(eIONumber_t number);

  /**
   * @fn: getDHTValue
   * @brief: Get the DHT value
   * @param number: io number
   * @return: sDhtData_t dhtData
   * @retval: temperature is dhtData.temperature
   * @retval: humidity is dhtData.humidity
   */
  sDhtData_t getDHTValue(eIONumber_t number);

  /**
   * @fn: get18b20Value
   * @brief: Get the ds18b20 value
   * @param number: io number
   * @return: temperature
   */
  float get18b20Value(eIONumber_t number);

  /**
   * @fn: setMotorPeriod
   * @brief: Set the motor period
   * @param number: motor number
   * @param motorPeriod: motor period
   * @return: NULL
   */
  void setMotorPeriod(ePeriod_t number ,uint16_t motorPeriod);

  /**
   * @fn: setMotorDuty
   * @brief: Set the motor duty
   * @param number: motor number
   * @param duty: motor duty
   * @return: NULL
   */
  void setMotorDuty(eMotorNumber_t number, uint16_t duty);

  /**
   * @fn: setServoAngle
   * @brief: Set the servo angle
   * @param number: servo number
   * @param angle: servo angle (0-180)
   * @return: NULL
   */
  void setServoAngle(eServoNumber_t number, uint8_t angle);

  /**
   * @fn: getSr04Distance
   * @brief: get sr04 distance
   * @return: distace
   * @retval: 0x00 is success
   * @retval: -1 is timerout error
   * @retval: -2 is timerout error
   * @retval: -3 is no to scale
   */
  int16_t getSr04Distance(void);
```

## Compatibility

MCU                | Work Well    |   Work Wrong    | Untested    | Remarks
------------------ | :----------: | :-------------: | :---------: | :----:
Arduino Uno        |      √       |                 |             |
ESP32-S3           |      √       |                 |             |



## History

- 2025/04/03 - Version V1.0.0 released.

## Credits

Written by ZhixinLiu(zhixin.liu@dfrobot.com), 2025. (Welcome to our website)
