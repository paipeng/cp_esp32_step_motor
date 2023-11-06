#include "key.h"


//端口初始化
void key_init(void) {
  pinMode(key1_pin, INPUT_PULLUP);//设置引脚为输入上拉模式
  pinMode(key2_pin, INPUT_PULLUP);
  pinMode(key3_pin, INPUT_PULLUP);
}

int key_scan(int mode) {
  static int key = 1;

  if (mode)
    key = 1;//连续扫描按键
  if (key == 1 && (digitalRead(key1_pin)==0||digitalRead(key2_pin)==0||digitalRead(key3_pin)==0)) {
    Serial.println("key pressed");
    delay(10);
    key=0;
    if(digitalRead(key1_pin)==0)
      return KEY1_PRESS;
    else if(digitalRead(key2_pin)==0)
      return KEY2_PRESS;
    else if(digitalRead(key3_pin)==0)
      return KEY3_PRESS;
  } else if(digitalRead(key1_pin)==1&&digitalRead(key2_pin)==1&&digitalRead(key3_pin)==1) {
    key=1;
  }
  return KEY_UNPRESS;   
}
