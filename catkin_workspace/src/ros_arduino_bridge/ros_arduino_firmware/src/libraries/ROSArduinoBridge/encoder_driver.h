/* *************************************************************
   Encoder driver function definitions - by James Nugen
   ************************************************************ */
   
   
#ifdef ARDUINO_ENC_COUNTER
  //below can be changed, but should be PORTD pins; 
  //otherwise additional changes in the code are required
  #define LEFT_ENC_PIN_A PD2  //pin 2
  #define LEFT_ENC_PIN_B PD3  //pin 3
  
  //below can be changed, but should be PORTC pins
  #define RIGHT_ENC_PIN_A PC4  //pin A4
  #define RIGHT_ENC_PIN_B PC5   //pin A5

#elif defined MY_ENCODER
  // 定义编码器引脚
  #define LEFT_A 20   // 中端口2
  #define LEFT_B 21  // 中断口3
  #define RIGHT_A 2  // 中断口0
  #define RIGHT_B 3  // 中断口1
  // 声明函数
  // 1. 初始化函数： 设置引脚操作模式
  void initEncoder();

  void leftEncoderEventA();
  void leftEncoderEventB();
  void rightEncoderEventA();
  void rightEncoderEventB();

#endif
   
long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();

