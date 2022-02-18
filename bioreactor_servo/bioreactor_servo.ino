#include <Servo.h>

#define servoPin 11

const float RPM = 16.0f;

Servo servo;

void setup() {
  // put your setup code here, to run once:
  pinMode(servoPin, OUTPUT);
  Serial.begin(9600);
  servo.attach(servoPin);

  servo.writeMicroseconds(RPMtoDelay(RPM));
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
