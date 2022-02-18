const int padPin = 5; // Pin for the heating pad
const int TEMP_ON = 255;
const int TEMP_OFF = 0;

void setup() {
  Serial.begin(9600);
  pinMode(padPin, OUTPUT);

  analogWrite(padPin, TEMP_ON); // Turn on the heating pad indefinitely
}

void loop() {
}
