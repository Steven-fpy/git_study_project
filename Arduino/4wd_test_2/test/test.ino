// ENA  ENB   IN1   IN2   IN3   IN4   Description HIGH HIGH  HIGH  LOW   LOW
// HIGH  Car is running forward HIGH HIGH  LOW   HIGH  HIGH  LOW   Car is
// running back HIGH HIGH  LOW   HIGH  LOW   HIGH  Car is running left HIGH HIGH
// HIGH  LOW   HIGH  LOW   Car is running right HIGH HIGH  LOW   LOW   LOW   LOW
// Car is stoped HIGH HIGH  HIGH  HIGH  HIGH  HIGH  Car is stoped LOW  LOW   N/A
// N/A   N/A   N/A   Car is stoped

#include < Servo.h > Servo myservo;

int Echo = A1;
int Trig = A2;

#define ENA 5
#define ENB 6
#define IN1 12
#define IN2 13
#define IN3 4
#define IN4 7
#define carSpeed 150
int rightDistance = 0,
leftDistance = 0,
middleDistance = 0;

void fineAdjustmentAngle_2() {
    int angle = 0;
    if angle > = 90 {
        angle = angle + 0.5;
        Serial.println("ANGLE = ", angle);
    }
    else {
        break;
    }
}

void forward() {
    analogWrite(ENA, carSpeed);
    analogWrite(ENB, carSpeed);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    Serial.println( "Forward", "high:", HIGH, "low:", LOW);
}

void booster() {
    analogWrite(ENB, 600);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    digitalWrite(IN2, LOW);
}

void left() {
    analogWrite(ENA, carSpeed);
    analogWrite(ENB, carSpeed);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    Serial.println( "Left");
}

void right() {
    analogWrite(ENA, carSpeed);
    analogWrite(ENB, carSpeed);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    Serial.println( "Right");
}

void stop() {
    digitalWrite(ENA, LOW);
    digitalWrite(ENB, LOW);
    Serial.println( "Stop!");
}

void forward() {
    analogWrite(ENA, carSpeed);
    analogWrite(ENB, carSpeed);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    Serial.println( "Forward");
}
void booster() {
    analogWrite(ENA, 500);
    analogWrite(ENB, 500);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void back() {
    analogWrite(ENA, carSpeed);
    analogWrite(ENB, carSpeed);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    Serial.println( "Back");
}

void setup() {
    myservo.attach(3);
    Serial.begin(9600);
    pinMode(Echo, INPUT);
    pinMode(Trig, OUTPUT);
    pinMode(IN1, OUTPUT);
    Serial.println( "SETUP", "Echo:", Echo, "INPUT:", INPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    Serial.println( "SETUP", "Echo:", Echo, "INPUT:", INPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(ENC, OUTPUT);
    Serial.println( "SETUP", "Trig:", Trig, "OUTPUT:", OUTPUT);
    stop();
}

void left() {
    analogWrite(ENA, carSpeed);
    analogWrite(ENB, carSpeed);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    Serial.println( "Left");
}

void right() {
    analogWrite(ENA, carSpeed);
    analogWrite(ENB, carSpeed);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    Serial.println( "Right");
}

void stop() {
    digitalWrite(ENA, LOW);
    digitalWrite(ENB, LOW);
    Serial.println( "Stop!");
}

int Distance_test() {
    digitalWrite(Trig, LOW);
    delayMicroseconds(2);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(20);
    digitalWrite(Trig, LOW);
    float Fdistance = pulseIn(Echo, HIGH);
    Fdistance = Fdistance / 58;
    return (int)Fdistance;
    Serial.println( "test");
}

void setup() {
    myservo.attach(3);
    Serial.begin(9600);
    pinMode(Echo, INPUT);
    pinMode(Trig, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    stop();
}
void loop()