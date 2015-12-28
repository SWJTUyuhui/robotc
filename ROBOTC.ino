#include <Servo.h>  
Servo armServo[4]; // 声明四个舵机的数组
int servoPins[4]; // 定义四个舵机的引脚变量
int servopwm[4]={90,90,90,90}; // 定义四个舵机的角度
String command;
char charreceive;
int mark,flag,len;
//小电机请将数值调小
int speed1=200;//小车速度控制0~255，数值越大，速度越快
int speed3=60;//电机3电压调节，0~255，数值越大，电压越高
int speed4=60;//电机4电压调节，0~255，数值越大，电压越高
int speed5=60;//电机5电压调节，0~255，数值越大，电压越高
int speed6=60;//电机6电压调节，0~255，数值越大，电压越高

int pwm1 = 8;
int pwm2 = 9;
int pwm3 = 10;
int pwm4 = 11;
int pwm5 = 12;
int pwm6 = 13;

int dir1 = 4;
int dir2 = 5;
int dir3 = 2;
int dir4 = 1;
int dir5 = 6;
int dir6 = 7;
void goforward();
void goleft();
void goright();
void goback();
void stopcommand();
void moto31();//motor3 rotation
void moto32();//motor3 rollback
void moto41();//motor4 rotation
void moto42();//motor4 rollback
void moto51();//motor4 rotation
void moto52();//motor4 rollback
void moto6();//motor5 

void setup() {
  // put your setup code here, to run once: 
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(dir3,OUTPUT);
  pinMode(dir4,OUTPUT);
  pinMode(dir5,OUTPUT);
  pinMode(dir6,OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);   
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
   digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
   digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
   //闪三次灯，表示程序开始运行
  Serial.begin(9600);
  Serial.println("mega2560begin...");
  Serial3.begin(9600);
  Serial3.println("mega2560begin...");
delay(500);

  servoPins[0] = 31;//设置舵机1的引脚
  servoPins[1] = 33; //设置舵机2的引脚
  servoPins[2] = 35; //设置舵机3的引脚
  servoPins[3] = 37; //设置舵机4的引脚
  armServo[0].attach(servoPins[0]); //舵机1数组绑定对应的的引脚
  armServo[1].attach(servoPins[1]); //舵机2数组绑定对应的的引脚
  armServo[2].attach(servoPins[2]); //舵机3数组绑定对应的的引脚
  armServo[3].attach(servoPins[3]); //舵机4数组绑定对应的的引脚
  armServo[0].write(servopwm[0]); //设置舵机1的初始角度90度
  armServo[1].write(servopwm[1]); //设置舵机1的初始角度90度
  armServo[2].write(servopwm[2]); //设置舵机1的初始角度90度
  armServo[3].write(servopwm[3]); //设置舵机1的初始角度90度
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);   
  while(Serial3.available())
   {
     charreceive=char(Serial3.read());
     command+=charreceive;
    delay(2);
    mark=1;
   }
if(sensorValue < 900)
  {
   digitalWrite(13, HIGH);  
   delay(300);         
   digitalWrite(13, LOW);  
   delay(300);  
  }
  else 
  {
    digitalWrite(13,LOW);  
   delay(1000);
}
    if (mark == 1) {
      Serial.println("get:"+command);
      len=command.length();
      delayMicroseconds(10);
      if(charreceive=='8')goforward();
      if(charreceive=='4')goleft();
      if(charreceive=='6')goright();
      if(charreceive=='2')goback();
      if(charreceive=='5')stopcommand();
      if(charreceive=='7')moto51();
      if(charreceive=='1')moto32();
      if(charreceive=='9')moto41();
      if(charreceive=='3')moto42();
      if(charreceive=='a')moto51();
      if(charreceive=='b')stopcommand();
      if(charreceive=='c')moto52();
      if(charreceive=='d')moto61();
      if(charreceive=='e')stopcommand();
      if(charreceive=='f')moto62();
         charreceive=' ';
         command="";
         mark=0;
    }

}
void goforward(){
 digitalWrite(dir1,1);
 digitalWrite(dir2,1);
 analogWrite(pwm1,speed1);
 analogWrite(pwm2,speed1);
 digitalWrite(dir3,1);
 digitalWrite(dir4,1);
 analogWrite(pwm3,speed1);
 analogWrite(pwm4,speed1);
}
void goback(){
 digitalWrite(dir1,0);
 digitalWrite(dir2,0);
 analogWrite(pwm1,speed1);
 analogWrite(pwm2,speed1);
 digitalWrite(dir3,0);
 digitalWrite(dir4,0);
 analogWrite(pwm3,speed1);
 analogWrite(pwm4,speed1);
}
void goleft(){
 digitalWrite(dir1,1);
 digitalWrite(dir2,0);
 analogWrite(pwm1,speed1);
 analogWrite(pwm2,speed1);
 digitalWrite(dir3,1);
 digitalWrite(dir4,0);
 analogWrite(pwm3,speed1);
 analogWrite(pwm4,speed1);
}
void goright(){
 digitalWrite(dir1,0);
 digitalWrite(dir2,1);
 analogWrite(pwm1,speed1);
 analogWrite(pwm2,speed1);
 digitalWrite(dir3,0);
 digitalWrite(dir4,1);
 analogWrite(pwm3,speed1);
 analogWrite(pwm4,speed1);
}

void stopcommand(){

 analogWrite(pwm1,0);
 analogWrite(pwm2,0);
 analogWrite(pwm3,0);
 analogWrite(pwm4,0);
 analogWrite(pwm5,0);
 analogWrite(pwm6,0);
}

void moto31()
{
  digitalWrite(dir3,1);
  analogWrite(pwm3,speed3);
}
void moto32()
{
  digitalWrite(dir3,0);
  analogWrite(pwm3,speed3);
}
void moto41()
{
  digitalWrite(dir4,1);
  analogWrite(pwm4,speed4);

}
void moto42()
{
  digitalWrite(dir4,0);
  analogWrite(pwm4,speed4);
 
}
void moto51()
{
  digitalWrite(dir5,1);
  analogWrite(pwm5, speed5);
  armServo[0].write(50); //设置角度
  armServo[1].write(50); //设置角度
}
void moto52()
{
  digitalWrite(dir5,0);
  analogWrite(pwm5, speed5);
  armServo[0].write(150); //设置角度
  armServo[1].write(150); //设置角度
}

void moto61()
{
  digitalWrite(dir6,1);
  analogWrite(pwm6, speed6);
  armServo[2].write(50); //设置角度
  armServo[3].write(50); //设置角度
}
void moto62()
{
  digitalWrite(dir6,0);
  analogWrite(pwm6, speed6);
  armServo[2].write(150); //设置角度
  armServo[3].write(150); //设置角度
}

