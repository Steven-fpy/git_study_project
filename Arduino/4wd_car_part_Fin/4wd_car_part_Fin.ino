// ENA  ENB   IN1   IN2   IN3   IN4   Description
// HIGH HIGH  HIGH  LOW   LOW   HIGH  Car is running forward
// HIGH HIGH  LOW   HIGH  HIGH  LOW   Car is running back
// HIGH HIGH  LOW   HIGH  LOW   HIGH  Car is running left
// HIGH HIGH  HIGH  LOW   HIGH  LOW   Car is running right
// HIGH HIGH  LOW   LOW   LOW   LOW   Car is stoped
// HIGH HIGH  HIGH  HIGH  HIGH  HIGH  Car is stoped
// LOW  LOW   N/A   N/A   N/A   N/A   Car is stoped

#include <Servo.h>
Servo myservo;

int Echo = A1;
int Trig = A2;

#define ENA 5
#define ENB 6
#define IN1 11
#define IN2 12
#define IN3 4
#define IN4 7
#define carSpeed 150
int rightDistance = 0, leftDistance = 0, middleDistance = 0;

void forward(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Forward");
  }

void back(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Back");  
  }

void left(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Left");  
  }

void right(){
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Right");  
  }

void stop(){
 digitalWrite(ENA, LOW);
 digitalWrite(ENB, LOW);
 Serial.println("Stop!");  
}

int Distance_test(){
 digitalWrite(Trig, LOW);
 delayMicroseconds(2);
 digitalWrite(Trig, HIGH);
 delayMicroseconds(20);
 digitalWrite(Trig, LOW);
 float Fdistance = pulseIn(Echo, HIGH);
 Fdistance = Fdistance / 58;
 return (int)Fdistance;  
}


void setup(){
  myservo.attach(3);
  Serial.begin(9600);
  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  stop();
}

void loop(){
  
 myservo.write(90);
 delay(500);
 middleDistance = Distance_test();
 if(middleDistance <= 20){
   stop();
   delay(500);
   myservo.write(10);
   delay(1000);
   rightDistance = Distance_test();
   
   delay(500);
   myservo.write(90);
   delay(1000);
   myservo.write(180);
   delay(1000);
   leftDistance = Distance_test();

   delay(500);
   myservo.write(90);
   delay(1000);
   if(rightDistance > leftDistance) {
     right();
     delay(360);
   }
   else if (rightDistance < leftDistance){
     left();
     delay(360);
     }
   else if ((rightDistance <= 20) || (leftDistance <= 20)) {
     back();
     delay(180);
     }
   else {
     forward();
   }
 }
 else{
    forward(); 
  }
}