
#include "key.h"
#include "step_motor.h"


//定义全局变量
int motor_dir = 0;//默认逆时针方向
int motor_speed = STEPMOTOR_MAXSPEED;//默认最大速度旋转
int motor_step = 0;

void setup() {

  Serial.begin(115200);
  Serial.setDebugOutput(true);
  
  delay(2000);
  Serial.println("key init...");
  key_init();
  
  Serial.println("step motor init...");
  step_motor_init();
}

void loop() {
  int key = key_scan(0);
  //Serial.printf("key scan: %d\n", key);
  if (key == KEY1_PRESS) {
    motor_dir = !motor_dir;    
  } else if (key == KEY2_PRESS) {
    if(motor_speed > STEPMOTOR_MAXSPEED)
      motor_speed -= 1;     
  } else if (key == KEY3_PRESS) {
    if(motor_speed < STEPMOTOR_MINSPEED)
      motor_speed += 1;     
  }
  step_motor_28BYJ48_send_pulse(motor_step++, motor_dir);
  if (motor_step == 8)
    motor_step = 0;    
  delay(motor_speed);
}
