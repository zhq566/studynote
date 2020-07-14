# 根据原理图得到LED相关引脚 #

![Image text](https://github.com/zhq566/studynote/blob/master/TQ2440/code/001-LightLED/001led%E5%BC%95%E8%84%9A%E5%88%86%E9%85%8D.png)

nLED_1：GP B5

nLED_2：GP B6

nLED_3：GP B7

nLED_4：GP B8


# 根据S3C2440找到GP B 引脚的配置寄存器地址 #

![Image text](https://github.com/zhq566/studynote/blob/master/TQ2440/code/001-LightLED/003GPB%E5%AF%84%E5%AD%98%E5%99%A8%E5%9C%B0%E5%9D%80.png)

GPBCON 0x56000010

GPBDAT 0x56000014

GPBUP 0x56000014


# 可知配置为输出模式、DAT寄存器控制输入输出的高低 #

![Image text](https://github.com/zhq566/studynote/blob/master/TQ2440/code/001-LightLED/004GPBCON%E5%AF%84%E5%AD%98%E5%99%A8%E6%8F%8F%E8%BF%B0.png)

![Image text](https://github.com/zhq566/studynote/blob/master/TQ2440/code/001-LightLED/005GPBDAT%E5%AF%84%E5%AD%98%E5%99%A8%E6%8F%8F%E8%BF%B0.png)

