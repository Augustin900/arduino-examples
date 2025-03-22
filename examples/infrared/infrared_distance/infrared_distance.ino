int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

int sensorValue;        // value read from the pot
 
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}
 
void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
 
  Serial.print("sensor = ");
  Serial.println(sensorValue);
 
  delay(200);
}