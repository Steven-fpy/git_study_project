#include <Servo.h>
Servo myservo;
const int LED = 10;
int Echo = A1;
int Trig = A2;

#define ENA 5
#define ENB 6
#define IN1 12
#define IN2 13
#define IN3 4
#define IN4 7
#define carSpeed 100
int rightDistance = 0, leftDistance = 0, middleDistance = 0;

void light(){
 digitalWrite(ENA, LOW);
 digitalWrite(ENB, LOW);
 Serial.println("Stop!");
}

int Distance_test(){
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, LOW);
  float Fdistance = pulseIn(Echo, HIGH);
  Fdistance = Fdistance / 58;
  return (int)Fdistance;
}

void setup() {
  pinMode(LED, OUTPUT);
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
  light();
}

void loop() {    // 1초 간격으로 LED가 깜빡임 
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
}
