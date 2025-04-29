# DFRobot_unihiker_expansion
- [English Version](./README.md)

这是一个控制 k10 扩展板的设备库。

![](./resources/images/xxx.png)

## 产品链接(https://www.dfrobot.com.cn)

    SKU：DFR1216

## 目录

* [概述](#概述)
* [库安装](#库安装)
* [方法](#方法)
* [兼容性](#兼容性)
* [历史](#历史)
* [创作者](#创作者)

## 概述
  这是一个控制 k10 扩展板的设备库。

## 库安装

使用此库前，请首先下载库文件，将其粘贴到micropython设备的文件系统中，然后打开examples文件夹并在该文件夹中运行演示。

## 方法

```python
def set_motor_period(self, period_type, motor_period):
    '''!
        @brief 设置电机组的PWM周期
        @param period_type 电机组选择（MOTOR1_2/MOTOR3_4）
        @param motor_period PWM周期值（0-0xFFFF）
        @throws ValueError 若period_type无效或周期超出范围
    '''

def set_motor_duty(self, motor, duty):
    '''!
        @brief 设置指定电机通道的占空比
        @param motor 电机通道选择（MOTOR1_A至MOTOR4_B）
        @param duty 占空比值（0-0xFFFF）
        @throws ValueError 若电机通道无效或占空比超出范围
    '''

def set_servo360(self, servo, direction, speed):
    '''!
        @brief 设置360°舵机
        @param servo 舵机通道选择（SERVO0-SERVO5）
        @param direction "FORWARD"/"BACKWARD"/"STOP" 正转/反转/停止
        @Param speed (0-100)
        @throws ValueError 若舵机通道无效或者方向无效
    '''

def set_servo_angle(self, servo, angle):
    '''!
        @brief 设置舵机旋转角度
        @param servo 舵机通道选择（SERVO0-SERVO5）
        @param angle 目标角度（0-180度）
        @throws ValueError 若舵机通道无效
    '''

def get_battery(self):
    '''!
        @brief 读取电池电压电量
        @return 电池电量（0-100）%
    '''

def get_dht_value(self, pin):
    '''!
        @brief 读取DHT温湿度传感器数据
        @param pin 连接的引脚（C0-C5）
        @return 包含测量值的DHTData对象
        @throws ValueError 若引脚无效
    '''

def get_18b20_value(self, pin):
    '''!
        @brief 读取DS18B20温度传感器
        @param pin 连接的引脚（C0-C5）
        @return 摄氏温度值
        @throws ValueError 若引脚无效
    '''

def get_sr04_distance(self):
    '''!
        @brief 用超声波传感器测量距离
        @return 距离（厘米，错误返回-1）
    '''

def set_mode(self, pin, mode):
    '''!
        @brief 设置IO引脚工作模式
        @param pin 目标引脚（C0-C5）
        @param mode 操作模式（ADC/DHT11/DHT22/DS18B20/GPIO_OUT/GPIO_IN）
        @throws ValueError 若参数无效
    '''

def set_gpio_state(self, pin, state):
    '''!
        @brief 设置GPIO输出状态
        @param pin 目标引脚（C0-C5）
        @param state 输出状态（HIGH/LOW）
        @throws ValueError 若参数无效
    '''

def get_gpio_state(self, pin):
    '''!
        @brief 读取GPIO输入状态
        @param pin 目标引脚（C0-C5）
        @return 当前引脚状态（0/1）
        @throws ValueError 若引脚无效
    '''

def get_adc_value(self, pin):
    '''!
        @brief 读取模拟输入值
        @param pin 目标引脚（C0-C5）
        @return ADC值（0-4095）
        @throws ValueError 若引脚无效
    '''

def send_ir(self, data):
    '''!
        @brief 发送红外信号
        @param data 32位IR命令数据
    '''

def get_ir_data(self):
    '''!
        @brief 接收红外信号
        @return 接收的32位IR数据（无数据返回0）
    '''

def get_bright(self):
    '''!
        @brief 获取WS2812 LED当前亮度
        @return 亮度值（0-255）
    '''

def set_bright(self, brightness):
    '''!
        @brief 设置WS2812 LED亮度
        @param brightness 目标亮度（0-255）
    '''

def set_ws2812(self, num, color):
    '''!
        @brief 设置WS2812 LED颜色
        @param num LED索引（RGB0/RGB1）
        @param color 24位RGB颜色（0xRRGGBB）
        @throws ValueError 若LED索引无效
    '''
``` 

## 兼容性

* Micropython Version

| Board        | Work Well | Work Wrong | Untested | Remarks |
| ------------ | :-------: | :--------: | :------: | ------- |
| k10          |    √      |            |          |         |

## 历史

- 2025-04-16 - 1.0.0 版本

## 创作者

作者：ZhixinLiu(zhixin.liu@dfrobot.com)， 2025年。（欢迎浏览我们的[网站](https://www.dfrobot.com.cn/)）





