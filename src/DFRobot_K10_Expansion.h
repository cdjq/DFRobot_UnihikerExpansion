/*!
 * @file DFRobot_K10_Expansion.h
 * @brief Define the basic structure of the DFRobot_K10_Expansion class, the implementation of the basic methods
 * @copyright	Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author [ZhixinLiu](zhixin.liu@dfrobot.com)
 * @version V1.0
 * @date 2023-03-07
 * @url https://github.com/DFRobot/DFRobot_K10_Expansion
 */
#ifndef __DFRobot_K10_Expansion__
#define __DFRobot_K10_Expansion__

#include <Arduino.h>
#include <Wire.h>

//#define ENABLE_DBG  1 ///> Open this macro and you can see the details of the program
#ifdef ENABLE_DBG
  #define DBG(...) {Serial.print("[");Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
#else
  #define DBG(...)
#endif

typedef enum {
  eMotor1_2,
  eMotor3_4,
  eServo0_1,
  eServo2_5,
}ePeriod_t;

typedef enum {
  eServo0,
  eServo1,
  eServo2,
  eServo3,
  eServo4,
  eServo5,
}eServoNumber_t;

typedef enum {
  eMotor1_A,
  eMotor1_B,
  eMotor2_A,
  eMotor2_B,
  eMotor3_A,
  eMotor3_B,
  eMotor4_A,
  eMotor4_B,
}eMotorNumber_t;

typedef enum {
  eADC,
  eDHT11,
  eDHT22,
  eDS18B20,
  eWriteGpio,
  eReadGpio,
}eMode_t;

typedef enum {
  eC0,
  eC1,
  eC2,
  eC3,
  eC4,
  eC5,
}eNumber_t;

typedef enum {
  eLOW,
  eHIGH,
}eIOState_t;

typedef enum {
  eTypeDHT11,
  eTypeDHT22,
}eDhtType_t;

typedef struct{
  float temperature;
  float humidity;
  uint8_t state;
}sDhtData_t;

class DFRobot_K10_Expansion{
public:
#define I2C_MOTOR12_PERIOD_H  0X00 
#define I2C_MOTOR12_PERIOD_L  0X01
#define I2C_MOTOR34_PERIOD_H  0x02
#define I2C_MOTOR34_PERIOD_L  0x03
#define I2C_MOTOR1_Z_DUTY_H   0X04
#define I2C_MOTOR1_Z_DUTY_L   0X05
#define I2C_MOTOR1_F_DUTY_H   0X06
#define I2C_MOTOR1_F_DUTY_L   0X07
#define I2C_MOTOR2_Z_DUTY_H   0X08
#define I2C_MOTOR2_Z_DUTY_L   0X09
#define I2C_MOTOR2_F_DUTY_H   0X0a
#define I2C_MOTOR2_F_DUTY_L   0X0b
#define I2C_MOTOR3_Z_DUTY_H   0x0c
#define I2C_MOTOR3_Z_DUTY_L   0x0D
#define I2C_MOTOR3_F_DUTY_H   0x0E
#define I2C_MOTOR3_F_DUTY_L   0x0F
#define I2C_MOTOR4_Z_DUTY_H   0x10
#define I2C_MOTOR4_Z_DUTY_L   0x11
#define I2C_MOTOR4_F_DUTY_H   0x12
#define I2C_MOTOR4_F_DUTY_L   0x13
#define I2C_SERVO01_PERIOD_H  0x14
#define I2C_SERVO01_PERIOD_L  0x15
#define I2C_SERVO25_PERIOD_H  0x16
#define I2C_SERVO25_PERIOD_L  0x17
#define I2C_SERVO0_DUTY_H     0x18
#define I2C_SERVO0_DUTY_L     0x19
#define I2C_SERVO1_DUTY_H     0x1a
#define I2C_SERVO1_DUTY_L     0x1b
#define I2C_SERVO2_DUTY_H     0x1c
#define I2C_SERVO2_DUTY_L     0x1d
#define I2C_SERVO3_DUTY_H     0x1e
#define I2C_SERVO3_DUTY_L     0x1f
#define I2C_SERVO4_DUTY_H     0x20
#define I2C_SERVO4_DUTY_L     0x21
#define I2C_SERVO5_DUTY_H     0x22
#define I2C_SERVO5_DUTY_L     0x23


// 红外发送数据
#define I2C_IR_S_STATE 				0x24
#define I2C_IR_S_DATA0				0x25
#define I2C_IR_S_DATA1				0x26
#define I2C_IR_S_DATA2				0x27
#define I2C_IR_S_DATA3				0x28


// 读 sr04 数据
#define I2C_SR04_STATE 				0x29
	#define SR04_FREE     	0x00
	#define SR04_COLLECT  	0x01
	#define SR04_COMPLETE 	0x02
#define I2C_SR04_DATA0 				0x2a
#define I2C_SR04_DATA1 				0x2b

// 控制 IO MODE 数据
#define I2C_IO_MODE_C0				0x2c
#define I2C_IO_MODE_C1				0x2d
#define I2C_IO_MODE_C2				0x2e
#define I2C_IO_MODE_C3				0x2f
#define I2C_IO_MODE_C4				0x30
#define I2C_IO_MODE_C5				0x31
/**************************
  *#define ADC_MODE     0x00
	*#define DHT11_MODE   0x01
	*#define DHT22_MODE   0x02
	*#define DS18B20_MODE 0x03
	*#define GPIO_W_MODE  0x04
	*#define GPIO_R_MODE  0x05
	*/

/* gpio BIT
 * HIGH OR LOW
 * c7 c6 c5 c4 c3 c2 c1 c0
 * I2C_R_VOLTAGE_S  BIT 位置为1 数据有效
 * I2C_R_VOLTAGE    BIT 1为high 0为low
 */
#define I2C_W_C0		          0x39
#define I2C_W_C1		          0x3a
#define I2C_W_C2		          0x3b
#define I2C_W_C3		          0x3c
#define I2C_W_C4		          0x3d
#define I2C_W_C5		          0x3e

/* 读取 gpio 数据 */
#define I2C_R_C0 			        0x3f
#define I2C_R_C1      			  0x40
#define I2C_R_C2		          0x41
#define I2C_R_C3		          0x42
#define I2C_R_C4		          0x43
#define I2C_R_C5		          0x44

/* 读取 adc 数据 */
#define I2C_ADC_C0_S					0x45
#define I2C_ADC_C0_H					0x46
#define I2C_ADC_C0_L					0x47
#define I2C_ADC_C1_S					0x48
#define I2C_ADC_C1_H					0x49
#define I2C_ADC_C1_L					0x4a
#define I2C_ADC_C2_S					0x4b
#define I2C_ADC_C2_H					0x4c
#define I2C_ADC_C2_L					0x4d
#define I2C_ADC_C3_S					0x4e
#define I2C_ADC_C3_H					0x4f
#define I2C_ADC_C3_L					0x50
#define I2C_ADC_C4_S					0x51
#define I2C_ADC_C4_H					0x52
#define I2C_ADC_C4_L					0x53
#define I2C_ADC_C5_S					0x54
#define I2C_ADC_C5_H					0x55
#define I2C_ADC_C5_L					0x56
// dht data
#define I2C_DHT_C0_S				0x57
#define I2C_DHT_C0_TH				0x58
#define I2C_DHT_C0_TL				0x59
#define I2C_DHT_C0_HH				0x5a
#define I2C_DHT_C0_HL				0x5b
#define I2C_DHT_C1_S				0x5c
#define I2C_DHT_C1_TH				0x5d
#define I2C_DHT_C1_TL				0x5e
#define I2C_DHT_C1_HH				0x5f
#define I2C_DHT_C1_HL				0x60
#define I2C_DHT_C2_S				0x61
#define I2C_DHT_C2_TH				0x62
#define I2C_DHT_C2_TL				0x63
#define I2C_DHT_C2_HH				0x64
#define I2C_DHT_C2_HL				0x65
#define I2C_DHT_C3_S				0x66
#define I2C_DHT_C3_TH				0x67
#define I2C_DHT_C3_TL				0x68
#define I2C_DHT_C3_HH				0x69
#define I2C_DHT_C3_HL				0x6a
#define I2C_DHT_C4_S				0x6b
#define I2C_DHT_C4_TH				0x6c
#define I2C_DHT_C4_TL				0x6d
#define I2C_DHT_C4_HH				0x6e
#define I2C_DHT_C4_HL				0x6f
#define I2C_DHT_C5_S				0x70
#define I2C_DHT_C5_TH				0x71
#define I2C_DHT_C5_TL				0x72
#define I2C_DHT_C5_HH				0x73
#define I2C_DHT_C5_HL				0x74
/* 读取 18b20 数据 */
#define I2C_18B20_C0_S				0x75
#define I2C_18B20_C0_H				0x76
#define I2C_18B20_C0_L				0x77
#define I2C_18B20_C1_S				0x78
#define I2C_18B20_C1_H				0x79
#define I2C_18B20_C1_L				0x7a
#define I2C_18B20_C2_S				0x7b
#define I2C_18B20_C2_H				0x7c
#define I2C_18B20_C2_L				0x7d
#define I2C_18B20_C3_S				0x7e
#define I2C_18B20_C3_H				0x7f
#define I2C_18B20_C3_L				0x80
#define I2C_18B20_C4_S				0x81
#define I2C_18B20_C4_H				0x82
#define I2C_18B20_C4_L				0x83
#define I2C_18B20_C5_S				0x84
#define I2C_18B20_C5_H				0x85
#define I2C_18B20_C5_L				0x86

// 电池电量数据 0-100
#define I2C_BATTERY						0x87

// 红外接收数据
#define I2C_IR_R_STATE 				0x88
#define I2C_IR_R_DATA0  			0x89
#define I2C_IR_R_DATA1  			0x8a
#define I2C_IR_R_DATA2  			0x8b
#define I2C_IR_R_DATA3  			0x8c


// ws2812 设置亮度，设置rgb 状态
#define I2C_WS2812_STATE			0x90
#define I2C_WS2812_BRIGHT			0x91
#define I2C_WS2812_R1   			0x92
#define I2C_WS2812_G1   			0x93
#define I2C_WS2812_B1   			0x94
#define I2C_WS2812_R2   			0x95
#define I2C_WS2812_G2   			0x96
#define I2C_WS2812_B2   			0x97

#define DATA_ENABLE  0x01     ///> enable
#define DATA_DISABLE 0x00     ///> disable
#define MODE_ERROR   0x02

#define RETRY_COUNT    10
#define TEMP_LEN       32



  DFRobot_K10_Expansion();
  ~DFRobot_K10_Expansion();
  uint8_t getBattery(void);
  uint32_t getIRData(void);
  uint8_t sendIR(uint32_t data);
  uint8_t setWS2812(uint32_t *data, uint8_t bright);
  uint8_t setMode(eNumber_t number, eMode_t mode);
  uint8_t setGpioState(eNumber_t number, eIOState_t state);
  uint8_t getGpioState(eNumber_t number);
  uint16_t getADCValue(eNumber_t number);
  sDhtData_t getDHTValue(eNumber_t number);
  float get18b20Value(eNumber_t number);
  void setMotorPeriod(ePeriod_t number ,uint16_t motorPeriod);
  void setMotorDuty(eMotorNumber_t number, uint16_t duty);
  void setServoAngle(eServoNumber_t number, uint16_t angle);
  int getSr04Distance(void);

private:
  virtual uint8_t writeReg(uint8_t reg, uint8_t *data, uint8_t len) = 0;
  virtual int16_t readReg(uint8_t reg, uint8_t *data, uint8_t len) = 0;
};

class DFRobot_K10_Expansion_I2C:public DFRobot_K10_Expansion{
public:
  DFRobot_K10_Expansion_I2C(TwoWire *pWire=&Wire, uint8_t addr = 0x33);
  bool begin(void);
protected:
  virtual uint8_t writeReg(uint8_t reg, uint8_t *data, uint8_t len);
  virtual int16_t readReg(uint8_t reg, uint8_t *data, uint8_t len);
private:
  TwoWire *__pWire;
  uint8_t __I2C_addr;
};

#endif