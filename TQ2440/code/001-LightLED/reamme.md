# 根据原理图得到LED相关引脚 #
nLED_1：GP B5

nLED_2：GP B6

nLED_3：GP B7

nLED_4：GP B8


# 根据S3C2440找到GP B 引脚的配置寄存器地址 #

GPBCON 0x56000010

GPBDAT 0x56000014

GPBUP 0x56000014


# 可知配置为输出模式、DAT寄存器控制输入输出的高低 #

