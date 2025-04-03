# DFRobot_UnihikerExpansion
- [English Version](./README.md)
这是一款K10 扩展板

![正反面svg效果图](/resources/images/xxx.jpg) 

## 产品链接(https://www.dfrobot.com.cn)

    SKU：DFR12016

## 目录

* [概述](#概述)
* [库安装](#库安装)
* [方法](#方法)
* [兼容性](#兼容性y)
* [历史](#历史)
* [创作者](#创作者)

## 概述

提供一个Arduino库给k10扩展模块，此库具有以下功能：
  获取 gpio、dht11、dht22、ds18b20、adc、battery、sr04、ir数据
  设置 ws2812、gpio、servo、motor
  发送 红外

## 库安装
这里提供两种使用本库的方法：<br>
1.打开Arduino IDE,在状态栏中的Tools--->Manager Libraries 搜索"DFRobot_UnihikerExpansion"并安装本库.<br>
2.首先下载库文件,将其粘贴到\Arduino\libraries目录中,然后打开examples文件夹并在该文件夹中运行演示.<br>

## 方法

```C++
/**
   * @fn: getBattery
   * @brief: 获取电池电量
   * @return: uint8_t 0-100 的百分比
   */
  uint8_t getBattery(void);

  /**
   * @fn: getIRData
   * @brief: 获取红外数据
   * @return uint32_t 红外数据的编码
   */
  uint32_t getIRData(void);

  /**
   * @fn: sendIR
   * @brief: 发送红外数据
   * @param data: 红外数据
   * @return: uint8_t 返回结果
   * @retval: 0x00 发送成功
   * @retval: 0xff 发送失败
   */
  uint8_t sendIR(uint32_t data);

  /**
   * @fn: setWS2812
   * @brief: 设置ws2812
   * @param data: 数据
   * @param bright: 亮度 0-255
   * @return: uint8_t 返回结果
   * @retval: 0x00 发送成功
   * @retval: 0xff 发送失败
   */  
  uint8_t setWS2812(uint32_t *data, uint8_t bright);
  
  /**
   * @fn: setMode
   * @brief: 设置io口模式
   * @return: uint8_t 返回结果
   * @retval: 0x00 发送成功
   * @retval: 0xff 发送失败
   */
  uint8_t setMode(eIONumber_t number, eIOType_t mode);

  /**
   * @fn: setGpioState
   * @brief: 设置gpio电平
   * @param number: io号
   * @param state: 高低电平
   * @return: uint8_t 返回结果
   * @retval: 0x00 发送成功
   * @retval: 0xff 发送失败
   */
  uint8_t setGpioState(eIONumber_t number, eGpioState_t state);

  /**
   * @fn: getGpioState
   * @brief: 获取gpio电平
   * @param number: io号
   * @return: uint8_t io口电平
   */
  uint8_t getGpioState(eIONumber_t number);

  /**
   * @fn: getADCValue
   * @brief: 获取adc的值
   * @param number: io号
   * @return: uint16_t adc值
   */
  uint16_t getADCValue(eIONumber_t number);

  /**
   * @fn: getDHTValue
   * @brief: 获取dht 数据
   * @param number: io号
   * @return: sDhtData_t dhtData
   * @retval: 温度 dhtData.temperature
   * @retval: 湿度 dhtData.humidity
   */
  sDhtData_t getDHTValue(eIONumber_t number);

  /**
   * @fn: get18b20Value
   * @brief: 获取18b20的数值
   * @param number: io号
   * @return: 温度
   */
  float get18b20Value(eIONumber_t number);

  /**
   * @fn: setMotorPeriod
   * @brief: 设置电机的周期
   * @param number: 电机号
   * @param motorPeriod:周期 
   * @return: NULL
   */
  void setMotorPeriod(ePeriod_t number ,uint16_t motorPeriod);

  /**
   * @fn: setMotorDuty
   * @brief: 设置电机占空比
   * @param number: 电机号
   * @param duty: 占空比数值
   * @return: NULL
   */
  void setMotorDuty(eMotorNumber_t number, uint16_t duty);

  /**
   * @fn: setServoAngle
   * @brief: 设置舵机角度
   * @param number: 舵机号
   * @param angle: 舵机角度 (0-180)
   * @return: NULL
   */
  void setServoAngle(eServoNumber_t number, uint8_t angle);

  /**
   * @fn: getSr04Distance
   * @brief: 获取sr04距离
   * @return: 距离
   * @retval: -1 is 超时
   * @retval: -2 is 超时
   * @retval: -3 is 超出测量范围
   */
  int16_t getSr04Distance(void);
```
## 兼容性

MCU                | Work Well    |   Work Wrong    | Untested    | Remarks
------------------ | :----------: | :-------------: | :---------: | :----:
Arduino Uno        |      √       |                 |             |
ESP32-S3           |      √       |                 |             |


## 历史
- 2025/04/03 - V1.0.0 版本

## 创作者

Written by ZhixinLiu(zhixin.liu@dfrobot.com), 2025. (Welcome to our website)