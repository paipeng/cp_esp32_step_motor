#ifndef _key_H
#define _key_H

#include <Arduino.h>

//定义按键控制管脚
#define key1_pin  25
#define key2_pin  26
#define key3_pin  27

//使用宏定义独立按键按下的键值
#define KEY1_PRESS  1
#define KEY2_PRESS  2
#define KEY3_PRESS  3

#define KEY_UNPRESS 0 

//函数声明
void key_init(void);
int key_scan(int mode);

#endif
