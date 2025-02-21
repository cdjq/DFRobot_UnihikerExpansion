/*!
 * @file DFRobot_K10_Expansion.cpp
 * @brief Define the basic structure of the DFRobot_K10_Expansion class, the implementation of the basic methods
 * @copyright	Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author [ZhixinLiu](zhixin.liu@dfrobot.com)
 * @version V0.5.0
 * @date 2024-04-23
 * @url https://github.com/DFRobot/DFRobot_K10_Expansion
 */
#include "DFRobot_K10_Expansion.h"

DFRobot_K10_Expansion::DFRobot_K10_Expansion(){}
DFRobot_K10_Expansion::~DFRobot_K10_Expansion(){}


void DFRobot_K10_Expansion::setMotorPeriod(ePeriod_t number ,uint16_t motorPeriod)
{
  uint8_t reg = 0;
  uint8_t result = 0;
  uint8_t _tempData[TEMP_LEN] = {0};
  if(number == eMotor1_2){
    reg = I2C_MOTOR12_PERIOD_H;
  }else if(number == eMotor3_4){
    reg = I2C_MOTOR34_PERIOD_H;
  }else if (number == eServo0_1){
    reg = I2C_SERVO01_PERIOD_H;
  }else if (number == eServo2_5){
    reg = I2C_SERVO25_PERIOD_H;
  }
  _tempData[0] = (motorPeriod >> 8)& 0xFF;
  _tempData[1] = (motorPeriod >> 0)& 0xFF;
  for(uint8_t i = 0; i < RETRY_COUNT; i++){
    result = writeReg(reg, _tempData, 2);
    if(result == 0){
      return;
    }else{
      DBG("i2c write error ");
    }
    delay(20);
  }
  return;
}

void DFRobot_K10_Expansion::setMotorDuty(eMotorNumber_t number, uint16_t duty)
{
  uint8_t reg = 0;
  uint8_t result = 0;
  uint8_t _tempData[TEMP_LEN] = {0};
  reg = I2C_MOTOR1_Z_DUTY_H + number*2;
  _tempData[0] = (duty >> 8)& 0xFF;
  _tempData[1] = (duty >> 0)& 0xFF;
  for(uint8_t i = 0; i < RETRY_COUNT; i++){
    result = writeReg(reg, _tempData, 2);
    if(result == 0){
      return;
    }else{
      DBG("i2c write error ");
    }
    delay(20);
  }
  return;
}


void DFRobot_K10_Expansion::setServoAngle(eServoNumber_t number, uint16_t angle)
{
  uint8_t reg = 0;
  uint16_t period = 0;
  uint8_t result = 0;
  uint8_t _tempData[TEMP_LEN] = {0};
  if(angle > 180){
    angle = 180;
  }
  period = 500 + angle * 11;
  reg = number*2+I2C_SERVO0_DUTY_H;
  _tempData[0] = (period >> 8)& 0xFF;
  _tempData[1] = (period >> 0)& 0xFF;
  
  for(uint8_t i = 0; i < RETRY_COUNT; i++){
    result = writeReg(reg, _tempData, 2);
    if(result == 0){
      return;
    }else{
      DBG("i2c write error ");
    }
    delay(20);
  }
  return;
}

uint8_t DFRobot_K10_Expansion::getBattery(void)
{
  uint8_t result = 0;
  uint8_t _tempData[TEMP_LEN] = {0};
  for (uint8_t i = 0; i < RETRY_COUNT; i++) {
    result = readReg(I2C_BATTERY, _tempData, 1);
    if (result == 0) {
      return _tempData[0];
    }else{
      DBG("i2c read error, please wait !");
    }
    delay(20);
  }
  return 0xFF;
}

uint32_t DFRobot_K10_Expansion::getIRData(void)
{
  uint8_t result = 0;
  uint8_t _tempData[TEMP_LEN] = {0};
  for (uint8_t i = 0; i < RETRY_COUNT; i++) {
    result = readReg(I2C_IR_R_STATE, _tempData, 5);
    if (result == 0) {
      if(_tempData[0] == DATA_DISABLE){
        return 0x00000000;
      }else{
        return ((uint32_t)_tempData[1] << 24) | ((uint32_t)_tempData[2] << 16) | ((uint32_t)_tempData[3] << 8) | _tempData[4];
      }
    }else{
      DBG("i2c read error, please wait !");
    }
    delay(20);
  }
  return 0xFFFFFFFF;
}

uint8_t DFRobot_K10_Expansion::sendIR(uint32_t data)
{
  uint8_t result = 0;
  uint8_t _tempData[TEMP_LEN] = {0};
  _tempData[0] = DATA_ENABLE;
  _tempData[1] = (data >> 24) & 0xFF;
  _tempData[2] = (data >> 16) & 0xFF;
  _tempData[3] = (data >> 8) & 0xFF;
  _tempData[4] = data & 0xFF;
  
  for(uint8_t i = 0; i < RETRY_COUNT; i++){
    result = writeReg(I2C_IR_S_STATE, _tempData, 5);
    if(result == 0){
      return 0;
    }else{
      DBG("i2c write error ");
    }
    delay(20);
  }
  return 0xff;
}

uint8_t DFRobot_K10_Expansion::setWS2812(uint32_t *data, uint8_t bright)
{
  uint8_t result = 0;
  uint8_t _tempData[TEMP_LEN] = {0};
  _tempData[0] = DATA_ENABLE;
  _tempData[1] = bright;
  _tempData[2] = (data[0] >> 16) & 0xFF;
  _tempData[3] = (data[0] >> 8)  & 0xFF;
  _tempData[4] = (data[0] >> 0)  & 0xFF;
  _tempData[5] = (data[1] >> 16) & 0xFF;
  _tempData[6] = (data[1] >> 8)  & 0xFF;
  _tempData[7] = (data[1] >> 0)  & 0xFF;
  
  for(uint8_t i = 0; i < RETRY_COUNT; i++){
    uint8_t result = writeReg(I2C_WS2812_STATE, _tempData, 8);
    if(result == 0){
      return 0;
    }else{
      DBG("i2c write error");
    }
    delay(20);
  }
  return 0xff;
}


uint8_t DFRobot_K10_Expansion::setMode(eNumber_t number, eMode_t mode)
{
  uint8_t result = 0;
  uint8_t reg = I2C_IO_MODE_C0+number;
  uint8_t _tempData[TEMP_LEN] = {0};
  _tempData[0] = mode;

  for(uint8_t i = 0; i < RETRY_COUNT; i++){
    uint8_t result = writeReg(reg, _tempData, 1);
    if(result == 0){
      return 0;
    }else{
      DBG("i2c write error ");
    }
    delay(20);
  }
  return 0xff;
}

uint8_t DFRobot_K10_Expansion::setGpioState(eNumber_t number, eIOState_t state)
{
  uint8_t result = 0;
  uint8_t _tempData[TEMP_LEN] = {0};
  uint8_t reg = I2C_W_C0+number;
  _tempData[0] = state;  
  for(uint8_t i = 0; i < RETRY_COUNT; i++){
    result = writeReg(reg, _tempData, 1);
    if(result == 0){
      return 0;
    }else{
      DBG("i2c write error ");
    }
    delay(20);
  }
  return 0xff;
}

uint8_t DFRobot_K10_Expansion::getGpioState(eNumber_t number)
{
  uint8_t result = 0;
  uint8_t _tempData[TEMP_LEN] = {0};
  uint8_t reg = I2C_R_C0+number;
  for (uint8_t i = 0; i < RETRY_COUNT; i++) {
    result = readReg(reg, _tempData, 1);
    if (result == 0) {
      return _tempData[0];
    }else{
      DBG("i2c read error, please wait !");
    }
    delay(20);
  }
  return 0xFF;
}

uint16_t DFRobot_K10_Expansion::getADCValue(eNumber_t number)
{
  uint8_t result = 0;
  uint8_t _tempData[TEMP_LEN] = {0};
  uint8_t reg = I2C_ADC_C0_S+number*3;
  for (uint8_t i = 0; i < RETRY_COUNT; i++) {
    result = readReg(reg, _tempData, 3);
    if (result == 0) {
      if(_tempData[0] == DATA_ENABLE){
        return ((uint16_t)_tempData[1] << 8) | _tempData[2];
      }else if(_tempData[0] == MODE_ERROR){
        DBG("gpio mode error!")
        return 0xffff;
      }else{
        DBG("data readly! please wait !");
      }
    }else{
      DBG("i2c read error! please wait !");
    }
    delay(20);
  }
  return 0xFFFF;
}

sDhtData_t DFRobot_K10_Expansion::getDHTValue(eNumber_t number)
{
  uint8_t result = 0;
  uint8_t _tempData[TEMP_LEN] = {0};
  uint8_t reg = 0;
  sDhtData_t dhtData;
  dhtData.humidity = 0.0;
  dhtData.temperature = 0.0;
  reg = I2C_DHT_C0_S+number*5;

  _tempData[0] = DATA_ENABLE;
  for(uint8_t i = 0; i < RETRY_COUNT; i++){
    uint8_t result = writeReg(reg, _tempData, 1);
    if(result == 0){
      break;
    }else{
      DBG("i2c write error ");
    }
    delay(20);
  }
  delay(30);
  for (uint8_t i = 0; i < RETRY_COUNT; i++) {
    result = readReg(reg, _tempData, 5);
    if (result == 0) {
      if(_tempData[0] == DATA_ENABLE){
        if (_tempData[1] & 0x80){
          dhtData.temperature  = ((float)(_tempData[1] & 0x7F) + (float)_tempData[2] * 0.01)*-1.0;
        }else{
          dhtData.temperature = (float)_tempData[1] + (float)_tempData[2] * 0.01;
        }
        dhtData.humidity = (float)_tempData[3] + (float)_tempData[4] * 0.01;
        dhtData.state = _tempData[0];
        return dhtData;
      }else if(_tempData[0] == MODE_ERROR){
        dhtData.state = MODE_ERROR;
        DBG("gpio mode error!")
        return dhtData;
      }else{
      }
    }else{
      DBG("i2c read error! please wait !");
    }
    delay(30);
  }
  return dhtData;
}

float DFRobot_K10_Expansion::get18b20Value(eNumber_t number)
{
  uint8_t result = 0;
  uint8_t _tempData[TEMP_LEN] = {0};
  uint8_t reg = 0;
  float temperature = 0.0;
  reg = I2C_18B20_C0_S+number*3;
  float sign = 1.0;
  _tempData[0] = DATA_ENABLE;
  for(uint8_t i = 0; i < RETRY_COUNT; i++){
    uint8_t result = writeReg(reg, _tempData, 1);
    if(result == 0){
      break;
    }else{
      DBG("i2c write error ");
    }
    delay(20);
  }
  delay(50);
  for (uint8_t i = 0; i < RETRY_COUNT; i++) {
    result = readReg(reg, _tempData, 3);
    if (result == 0) {
      if(_tempData[0] == DATA_ENABLE){
        if(_tempData[1] == 0xff && _tempData[2] == 0xff){
          return 0.0;
        }
        if(_tempData[1] & 0x80){
          _tempData[1] &= 0x7f;
          sign = -1.0;
        }else{
          sign = 1.0;
        }
        temperature = ((uint16_t)_tempData[1]*256 + (uint16_t)_tempData[2]) / 16.0;
        return temperature;
      }else if(_tempData[0] == MODE_ERROR){
        DBG("gpio mode error!")
        return 0.0;
      }else{
      }
    }else{
      DBG("i2c read error! please wait !");
    }
    delay(30);
  }
  return 0.0;  // 或者其他你定义的错误码
}

int  DFRobot_K10_Expansion::getSr04Distance(void)
{
  uint8_t result = 0;
  uint8_t _tempData[TEMP_LEN] = {0};
  uint8_t reg = 0;
  int distance = 0.0;
  reg = I2C_SR04_STATE;
  _tempData[0] = SR04_COLLECT;
  for(uint8_t i = 0; i < RETRY_COUNT; i++){
    uint8_t result = writeReg(reg, _tempData, 1);
    if(result == 0){
      break;
    }else{
      DBG("i2c write error ");
    }
    delay(20);
  }
  delay(30);
  for (uint8_t i = 0; i < RETRY_COUNT; i++) {
    result = readReg(reg, _tempData, 3);
    if (result == 0) {
      if(_tempData[0] == SR04_COMPLETE){
        distance = int(((uint16_t)_tempData[1])<<8 | _tempData[2]);
        return distance;
      }else{
        DBG("data readly! please wait !");
      }
    }else{
      DBG("i2c read error! please wait !");
    }
    delay(30);
  }
  return -1;
}


DFRobot_K10_Expansion_I2C::DFRobot_K10_Expansion_I2C(TwoWire *pWire, uint8_t addr)
{
  __pWire = pWire;
  this->__I2C_addr = addr;
}

bool DFRobot_K10_Expansion_I2C::begin()
{
  __pWire->begin();
  //__pWire->setClock(100000);
  __pWire->beginTransmission(__I2C_addr);
  if(__pWire->endTransmission() == 0){
    return true;
  }else{
    return false;
  }
}

uint8_t DFRobot_K10_Expansion_I2C::writeReg(uint8_t reg, uint8_t *data, uint8_t len)
{
  uint8_t result = 0;
  __pWire->beginTransmission(this->__I2C_addr);
  __pWire->write(reg);
  for(uint8_t i = 0; i < len; i++){
    __pWire->write(data[i]);
  }
  result = __pWire->endTransmission();
  return result;
}

int16_t DFRobot_K10_Expansion_I2C::readReg(uint8_t reg, uint8_t *data, uint8_t len)
{
  uint8_t result = 0;
  uint8_t i = 0;
  result = writeReg(reg, NULL, 0);
  if(result!= 0){
    return -1;
  }
  result = __pWire->requestFrom((uint8_t)this->__I2C_addr,(uint8_t)len);
  while (__pWire->available()){
    data[i++]=__pWire->read();
  }
  if(i == len){
    return 0;
  }else{
    DBG("read error");
    return -1;
  }

}

