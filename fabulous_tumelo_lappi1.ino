#include<Servo.h>
Servo myservo;
int ENA1= 10;
int IN1= 7;
int IN2 = 8;
int ENA2= 11;
int IN3= 12;
int IN4 = 13;
int trig=2;
int echo=3;


  void setup()
{
  myservo.attach(9);
  myservo.write(90);
  delay(2000);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
   

  Serial.begin(9600);
  pinMode(ENA1, OUTPUT); // Set ENA as OUTPUT
  pinMode(IN1, OUTPUT); // Set IN1 as OUTPUT
  pinMode(IN2, OUTPUT); // Set IN2 as OUTPUT
  pinMode(ENA2, OUTPUT); // Set ENA as OUTPUT
  pinMode(IN3, OUTPUT); // Set IN3 as OUTPUT
  pinMode(IN4, OUTPUT); // Set IN4 as OUTPUT

  digitalWrite(IN1, LOW); // Make the Arduino Pin 8 Low
  digitalWrite(IN2, LOW); // Make the Arduino Pin 7 Low
  digitalWrite(IN3, LOW); // Make the Arduino Pin 2 Low
  digitalWrite(IN4, LOW); // Make the Arduino Pin 4 Low
  analogWrite(ENA1,255);
  analogWrite(ENA2,255);
}
void loop()
{

  Serial.println(dis());
  Serial.println("\n");


 int front_Distance=dis();
 if(front_Distance<50)
 {
 Stop();
 Rotate_left();
 int left_Distance=dis();
 delay(1000);
 Rotate_right();
 
 int right_Distance=dis();
 delay(1000);
 myservo.write(90);
 
 
 Serial.print("left");
 Serial.println(left_Distance);
 Serial.print("right");
 Serial.println(right_Distance);

 if(left_Distance>right_Distance)
 {
 left_Rotate();
 Serial.println("Rotated left");
 start();
 }
 else
 {
 right_Rotate();Serial.println("Rotated right");
 start();}
 
  }
  
  
  else
  {start();}


 

  
  }

  int dis()
 {long duration;
  // digitalWrite(trig, LOW);
   //delayMicroseconds(4);
   digitalWrite(trig, HIGH);
   delayMicroseconds(15);
   digitalWrite(trig, LOW);
   
   duration = pulseIn(echo, HIGH);
   //Serial.println(duration);
   long distance =((duration*340)/(20000)) ;
   Serial.println(distance);
   return distance;
   
   }

   void Stop()
   {digitalWrite(IN1, LOW); // Make the Arduino Pin  Low
    digitalWrite(IN2, LOW); // Make the Arduino Pin  Low
    digitalWrite(IN3, LOW); // Make the Arduino Pin  Low
    digitalWrite(IN4, LOW); // Make the Arduino Pin  Low
    }
    void start()
    {digitalWrite(IN1, HIGH); // Make the Arduino Pin  Low
    digitalWrite(IN2, LOW); // Make the Arduino Pin  Low
    digitalWrite(IN3, HIGH); // Make the Arduino Pin  Low
    digitalWrite(IN4, LOW); // Make the Arduino Pin  Low
    }

   void Rotate_left()
   {myservo.write(180);
    delay(4000);
    
    }

   void Rotate_right()
   {myservo.write(0);
    delay(4000);}

   void left_Rotate()
   {digitalWrite(IN1,LOW);
   digitalWrite(IN2,HIGH);
   digitalWrite(IN3,HIGH);
   digitalWrite(IN4,LOW);
   delay(1000);
   
    }
    void right_Rotate()
   {digitalWrite(IN1,HIGH);
   digitalWrite(IN2,LOW);
   digitalWrite(IN3,LOW);
   digitalWrite(IN4,HIGH);
   delay(1000);
   
    }