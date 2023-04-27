#
/*
 * 测速实现:
 *  阶段1:脉冲数统计
 *  阶段2:速度计算
 * 
 * 阶段1:
 *  1.定义所使用的中断引脚,以及计数器(使用 volatile 修饰)
 *  2.setup 中设置波特率，将引脚设置为输入模式
 *  3.使用 attachInterupt() 函数为引脚添加中断出发时机以及中断函数
 *  4.中断函数编写计算算法，并打印
 *    A.单频统计只需要统计单相上升沿或下降沿
 *    B.2倍频统计需要统计单相的上升沿和下降沿
 *    C.4倍频统计需要统计两相的上升沿和下降沿
 *  5.上传并查看结果
 *  
 * 
 */
int motor_A = 3;//中端口是1
int motor_B = 2;//中断口是0
volatile int count = 0;//如果是正转，那么每计数一次自增1，如果是反转，那么每计数一次自减1 

void CountDoubleFreq() {
  //单频计数实现
  //手动旋转电机一圈，输出结果为 一圈脉冲数 * 减速比
  /*if(digitalRead(motor_A) == HIGH){
    if(digitalRead(motor_B) == LOW){//A 高 B 低
      count++;  
    } else {//A 高 B 高
      count--;  
    }
  }*/

  //2倍频计数实现
  //手动旋转电机一圈，输出结果为 一圈脉冲数 * 减速比 * 2
  if(digitalRead(motor_A) == HIGH) {
    if(digitalRead(motor_B) == HIGH) {  //A 高 B 高
      count++;  
    } else {  //A 高 B 低
      count--;  
    }
  } else {
    if(digitalRead(motor_B) == LOW){  //A 低 B 低
      count++;  
    } else {  //A 低 B 高
      count--;  
    }  
  }

}

//与A实现类似
//4倍频计数实现
//手动旋转电机一圈，输出结果为 一圈脉冲数 * 减速比 * 4
void CountQuadFreq(){
  if(digitalRead(motor_B) == HIGH){
    if(digitalRead(motor_A) == LOW){//B 高 A 低
      count++;
    } else {//B 高 A 高
      count--;
    }
  } else {
    if(digitalRead(motor_A) == HIGH){//B 低 A 高
      count++;
    } else {//B 低 A 低
      count--;
    }
  }
}

int reducation = 50;//减速比，根据电机参数设置，比如 15 | 30 | 60
int pulse = 7; //编码器旋转一圈产生的脉冲数该值需要参考商家电机参数
int per_round = pulse * reducation * 4;//车轮旋转一圈产生的脉冲数 
long start_time = millis();//一个计算周期的开始时刻，初始值为 millis();
long interval_time = 50;//一个计算周期 50ms
double current_vel;

//获取当前转速的函数
void get_current_vel(){
  long right_now = millis();  
  long past_time = right_now - start_time;//计算逝去的时间
  if(past_time >= interval_time){//如果逝去时间大于等于一个计算周期
    //1.禁止中断
    noInterrupts();
    //2.计算转速 转速单位可以是秒，也可以是分钟... 自定义即可
    current_vel = (double)count / per_round / past_time * 1000 * 60;
    //3.重置计数器
    count = 0;
    //4.重置开始时间
    start_time = right_now;
    //5.重启中断
    interrupts();

    Serial.println(current_vel);

  }
}
void setup() {
  Serial.begin(57600);//设置波特率  
  pinMode(motor_A,INPUT);
  pinMode(motor_B,INPUT);
  
  attachInterrupt(0,CountDoubleFreq,CHANGE);  // 当电平发生改变时触发中断函数
  attachInterrupt(1,CountQuadFreq,CHANGE);  // 四倍频统计需要为B相也添加中断
}

void loop() {
  //测试计数器输出
  delay(10);
//  Serial.println(count);

}
