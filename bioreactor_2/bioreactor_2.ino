// Adapted from makerguides.com and circuitbasics.com (3/12/21)
// Uses a DS18B20 temperature sensor and DHT11 humidity sensor to find the temperature/humidity

// Include the Arduino libraries
#include <OneWire.h>
#include <DallasTemperature.h>
#include <dht.h>

// Instantiate OneWire and DallasTemperature for the DS18B20
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Instantiate a DHT object for the DHT11
dht DHT;
#define DHT11_PIN 3

void setup() {
  Serial.begin(9600);
  
  // Start up DallasTemperature
  sensors.begin();
}
void loop() {
  // Find temperature
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0); // the index 0 refers to the first device
  // Print the temperature
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print(" \xC2\xB0"); // shows degree symbol
  Serial.print("C  |  ");
  
  // Find humidity
  int chk = DHT.read11(DHT11_PIN);
  // Print the humidity
  Serial.print("Humidity: ");
  Serial.print(DHT.humidity);
  Serial.println("%");
  
  // Wait 1 second
  delay(1000);
}
