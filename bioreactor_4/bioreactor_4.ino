#include <Servo.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <dht.h>

#define tempPin 2
#define humidityPin 3
#define servoPin 4
#define padPin 5

const int servoDelay = 1620; // Results in about 16 rpm for our servo

OneWire oneWire(tempPin);
DallasTemperature tempSensor(&oneWire);
dht DHT;
Servo servo;

void setup() {
  pinMode(servoPin, OUTPUT);
  pinMode(padPin, OUTPUT);
    
  Serial.begin(9600);
  servo.attach(servoPin);
  tempSensor.begin();

  digitalWrite(padPin, HIGH); // Turns the heating pad on

  // Servo speed
  servo.writeMicroseconds(servoDelay);
}

void loop() {
  tempSensor.requestTemperatures();
  float tempC = tempSensor.getTempCByIndex(0);
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print(" \xC2\xB0"); // Degree symbol
  Serial.print("C | ");

  DHT.read11(humidityPin);
  Serial.print("Humidity: ");
  Serial.print(DHT.humidity);
  Serial.print("%");

  Serial.print(" | Heating Pad: ON");
  

  Serial.println();

  delay(1000);
}
