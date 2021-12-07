#include <Adafruit_PWMServoDriver.h>
#include<Wire.h>
Adafruit_PWMServoDriver servo=Adafruit_PWMServoDriver();
#define Servomin 150
#define Servomax 640
void servowrite(int channel,int angle);
void zeroset();
int flag=0;
void setup() 
{
servo.begin();
servo.setPWMFreq(60);
Serial.begin(9600);
delay(20);
zeroset();
} 
void loop()
 {
// step 1
//left ankle=90 -> 45
//right ankle=90 -> 70
for(int i=0;i<4;i++)
{
servowrite(0,90-15*i);
delay(100);
if(i<3)
{
servowrite(10,90-10*i);
delay(100);
}
}
//step 2
//left hip=90 -> 105
//right hip=90 -> 105
//left knee=90 -> 105
//right knee=90 -> 105
if(flag==0)
{
for(int i=0;i<4;i++)
{
servowrite(4,90+5*i);
servowrite(2,90+5*i);
servowrite(6,90+5*i);
servowrite(8,90+5*i);
delay(100);
}
}
else
{
for(int i=0;i<7;i++)
{
servowrite(4,75+5*i);
servowrite(2,75+5*i);
servowrite(6,75+5*i);
servowrite(8,75+5*i);
delay(100);
}
}

  //setp 3
   //left ankle=45 -> 90
  //right ankle=70 -> 90
  for(int i=0;i<4;i++)
  {
    servowrite(0,45+15*i);
    delay(100);
    if(i<3)
    {
      servowrite(10,70+10*i);
      delay(100);
    }
  }
   // step 4
  //left ankle=90 -> 110
  //right ankle=90 -> 135
  for(int i=0;i<4;i++)
  {
    servowrite(10,90+15*i);
    delay(100);
    if(i<3)
    {
      servowrite(0,90+10*i);
      delay(100);
    }
  }
   //step 5
  //left hip=105 -> 75
  //right hip=105 -> 75
  //left knee=105 -> 75
  //right knee=105 -> 75
    {
      for(int i=0;i<7;i++)
      {
        servowrite(4,105-5*i);
         servowrite(2,105-5*i);
          servowrite(6,105-5*i);
           servowrite(8,105-5*i);
           delay(100);
      }
    }
     // step 6
  //left ankle=110 -> 90
  //right ankle=135 -> 90
  for(int i=0;i<4;i++)
  {
    servowrite(10,135-15*i);
    delay(100);
    if(i<3)
    {
      servowrite(0,110-10*i);
      delay(100);
    }
  }
  flag=1;
}
void servowrite(int channel,int angle)
{
  
  int pos=map(angle,0,180,Servomin,Servomax);
  servo.setPWM(channel,0,pos);
}
void zeroset()
{ 
  for(int j=0;j<=5;j++)
{
    servowrite(2*j,90);
    delay(2000);
}
}
