// ENA  ENB   IN1   IN2   IN3   IN4   Description
// HIGH HIGH  HIGH  LOW   LOW   HIGH  Car is running forward
// HIGH HIGH  LOW   HIGH  HIGH  LOW   Car is running back
// HIGH HIGH  LOW   HIGH  LOW   HIGH  Car is running left
// HIGH HIGH  HIGH  LOW   HIGH  LOW   Car is running right
// HIGH HIGH  LOW   LOW   LOW   LOW   Car is stoped
// HIGH HIGH  HIGH  HIGH  HIGH  HIGH  Car is stoped
// LOW  LOW   N/A   N/A   N/A   N/A   Car is stoped

//---test bluetooth---
// #define LED 13    // define 13 pin for LED
// bool state = LOW; // The initial state of the function is defined as a low level
// char getstr;      // Defines a function that receives the Bluetooth character

// void setup() {
//   pinMode(LED, OUTPUT);
//   Serial.begin(9600);
// }

// // Control LED sub function
// void stateChange(){
//   state = !state;
//   digitalWrite(LED, state);
// }

// void loop(){
//   // The Bluetooth serial port to receive the data in the function
//   getstr = Serial.read();
//   if (getstr == 'a'){
//     stateChange();
//   }
// }
//---test bluetooth---

// #define ENA 5
// #define ENB 6
// #define IN1 3
// #define IN2 4
// #define IN3 2
// #define IN4 7
// #define LED 13

// unsigned char carSpeed = 150;
// bool state = LOW;
// char getstr;

// void forward(){
//   digitalWrite(ENA, HIGH);
//   digitalWrite(ENB, HIGH);
//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2,  LOW);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, HIGH);
//   Serial.println("Forward");
//   }

// void back(){
//   digitalWrite(ENA, HIGH);
//   digitalWrite(ENB, HIGH);
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, HIGH);
//   digitalWrite(IN3, HIGH);
//   digitalWrite(IN4, LOW);
//   Serial.println("Back");  
//   }

// void left(){
//   digitalWrite(ENA, HIGH);
//   digitalWrite(ENB, HIGH);
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, HIGH);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, HIGH);
//   Serial.println("Left");  
//   }

// void right(){
//   digitalWrite(ENA, HIGH);
//   digitalWrite(ENB, HIGH);
//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, HIGH);
//   digitalWrite(IN4, LOW);
//   Serial.println("Right");  
//   }

// void stop(){
//  digitalWrite(ENA, LOW);
//  digitalWrite(ENB, LOW);
//  Serial.println("Stop!");  
// }

// void stateChange(){
//   state = !state;
//   digitalWrite(LED, state)
//   Serial.println("Light");
// }

// void setup(){
//   myservo.attach(A0);
//   Serial.begin(9600);
//   // pinMode(Echo, INPUT);
//   // pinMode(Trig, OUTPUT);
//   pinMode(LED, OUTPUT);
//   pinMode(IN1,OUTPUT);
//   pinMode(IN2,OUTPUT);
//   pinMode(IN3,OUTPUT);
//   pinMode(IN4,OUTPUT);
//   pinMode(ENA,OUTPUT);
//   pinMode(ENB,OUTPUT);
//   stop();
// }

// void loop() {
//   getstr = Serial.read();
//   switch(getstr){
//     case 'w' : forward();
//     break;

//     case 's' : back();
//     break;
    
//     case 'a' : left();
//     break;
    
//     case 'd' : right();
//     break;
    
//     case 'f' : stop();
//     break;
    
//     case 'c' : stateChange();
//     break;

//     default : break;
    
//   }
// }

//---test bluetooth---



// // ----part1--- // 
#include <Servo.h>
Servo myservo;

int Echo = A4;
int Trig = A5;

#define ENA 5
#define ENB 6
#define IN1 3
#define IN2 4
#define IN3 2
#define IN4 7
#define carSpeed 150
int rightDistance = 0, leftDistance = 0, middleDistance = 0;

void forward(){
  digitalWrite(ENA, carSpeed);
  digitalWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2,  LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Forward");
  }

void back(){
  digitalWrite(ENA, carSpeed);
  digitalWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Back");  
  }

void left(){
  digitalWrite(ENA, carSpeed);
  digitalWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Left");  
  }

void right(){
  digitalWrite(ENA, carSpeed);
  digitalWrite(ENB, carSpeed);
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
  myservo.attach(12);
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
  // forward();
  // delay(1000);
  // back();
  // delay(1000);
  // left();
  // delay(1000);
  // right();
  // delay(1000);
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


// ----part1--- //