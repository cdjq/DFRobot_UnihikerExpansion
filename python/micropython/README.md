# DFRobot_unihiker_expansion
- [中文版](./README_CN.md)

This is a device library that controls the k10 expansion board.

![](./resources/images/xxx.png)

## Product link(https://www.dfrobot.com)

    SKU：DFR1216

## Catalogue

* [Overview](#Overview)
* [Installation](#Installation)
* [Methods](#Methods)
* [Compatibility](#Compatibility)
* [History](#History)
* [Credits](#Credits)

## Overview
  This is a device library that controls the k10 expansion board.

## Installation

Before using this library, first download the library file, paste it into the file system of your micropython device, then open the examples folder and run the demo in it.

## Methods

```python
def set_motor_period(self, period_type, motor_period):
    '''!
        @brief Set PWM period for motor groups
        @param period_type Motor group selection (MOTOR1_2/MOTOR3_4)
        @param motor_period PWM period value (0-0xFFFF)
        @throws ValueError If invalid period_type or out-of-range period
    '''

def set_motor_duty(self, motor, duty):
    '''!
        @brief Set duty cycle for specific motor channel
        @param motor Motor channel selection (MOTOR1_A to MOTOR4_B)
        @param duty Duty cycle value (0-0xFFFF)
        @throws ValueError If invalid motor or out-of-range duty
    '''

def set_servo360(self, servo, direction, speed):
    '''!
        @brief Set servo motor360
        @param servo Servo channel selection (SERVO0-SERVO5)
        @param direction "FORWARD"/"BACKWARD"/"STOP"
        @Param speed (0-100)
        @throws ValueError If invalid servo channel
    '''

def set_servo_angle(self, servo, angle):
    '''!
        @brief Set servo motor rotation angle
        @param servo Servo channel selection (SERVO0-SERVO5)
        @param angle Target angle (0-180 degrees)
        @throws ValueError If invalid servo channel
    '''

def get_battery(self):
    '''!
        @brief Read battery voltage level
        @return Battery level (0-255 scale)
    '''

def get_dht_value(self, pin):
    '''!
        @brief Read DHT temperature/humidity sensor data
        @param pin Connected pin (C0-C5)
        @return DHTData object containing measurements
        @throws ValueError If invalid pin
    '''

def get_18b20_value(self, pin):
    '''!
        @brief Read DS18B20 temperature sensor
        @param pin Connected pin (C0-C5)
        @return Temperature in Celsius
        @throws ValueError If invalid pin
    '''

def get_sr04_distance(self):
    '''!
        @brief Measure distance with ultrasonic sensor
        @return Distance in cm (-1 if error)
    '''

def set_mode(self, pin, mode):
    '''!
        @brief Set IO pin working mode
        @param pin Target pin (C0-C5)
        @param mode Operation mode (ADC/DHT11/DHT22/DS18B20/GPIO_OUT/GPIO_IN)
        @throws ValueError If invalid parameters
    '''

def set_gpio_state(self, pin, state):
    '''!
        @brief Set GPIO output state
        @param pin Target pin (C0-C5)
        @param state Output state (HIGH/LOW)
        @throws ValueError If invalid parameters
    '''

def get_gpio_state(self, pin):
    '''!
        @brief Read GPIO input state
        @param pin Target pin (C0-C5)
        @return Current pin state (0/1)
        @throws ValueError If invalid pin
    '''

def get_adc_value(self, pin):
    '''!
        @brief Read analog input value
        @param pin Target pin (C0-C5)
        @return ADC value (0-4095)
        @throws ValueError If invalid pin
    '''

def send_ir(self, data):
    '''!
        @brief Send infrared signal
        @param data 32-bit IR command data
    '''

def get_ir_data(self):
    '''!
        @brief Receive infrared signal
        @return 32-bit received IR data (0 if no data)
    '''

def get_bright(self):
    '''!
        @brief Get current WS2812 LED brightness
        @return Brightness value (0-255)
    '''

def set_bright(self, brightness):
    '''!
        @brief Set WS2812 LED brightness
        @param brightness Target brightness (0-255)
    '''

def set_ws2812(self, num, color):
    '''!
        @brief Set WS2812 LED color
        @param num LED index (RGB0/RGB1)
        @param color 24-bit RGB color (0xRRGGBB)
        @throws ValueError If invalid LED index
    '''
```

## Compatibility

* Micropython Version

| Board        | Work Well | Work Wrong | Untested | Remarks |
| ------------ | :-------: | :--------: | :------: | ------- |
| k10          |    √      |            |          |         |

## History

- 2025-04-16 - Version 1.0.0 released.

## Credits

Written by ZhixinLiu(zhixin.liu@dfrobot.com), 2025. (Welcome to our [website](https://www.dfrobot.com/))