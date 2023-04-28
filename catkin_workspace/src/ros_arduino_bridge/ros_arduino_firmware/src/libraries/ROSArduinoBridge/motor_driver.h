/***************************************************************
   Motor driver function definitions - by James Nugen
   *************************************************************/

#ifdef L298_MOTOR_DRIVER
  #define RIGHT_MOTOR_BACKWARD 5
  #define LEFT_MOTOR_BACKWARD  6
  #define RIGHT_MOTOR_FORWARD  9
  #define LEFT_MOTOR_FORWARD   10
  #define RIGHT_MOTOR_ENABLE 12
  #define LEFT_MOTOR_ENABLE 13
#elif defined AT8236_MOTOR_DRIVER
  // digitalWrite(DIRA,LOW); alogWrite(PWMA,pwm); 前进
  //
  #define LEFT_FORWARD_DIR  9
  #define LEFT_FORWARD_PWM  8
  #define LEFT_BACK_DIR  8
  #define LEFT_BACK_PWM  9
  
  #define RIGHT_FORWARD_DIR 5
  #define RIGHT_FORWARD_PWM 4
  #define RIGHT_BACK_DIR  4
  #define RIGHT_BACK_PWM  5

#endif

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);
