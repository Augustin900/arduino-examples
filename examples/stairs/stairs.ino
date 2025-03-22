#include <Ultrasonic.h>

const int trigPin = 12;
const int echoPin = 13;

Ultrasonic ultrasonic(trigPin, echoPin);
long duration, distance;

int pins[3] = {2, 3, 4};

void setup() {
  Serial.begin(9600);

  for(int i = 0; i < sizeof(pins); i++){
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  // Pass INC as a parameter to get the distance in inches
  distance = ultrasonic.read();

  Serial.print("Distance: ");
  Serial.println(distance);

  for(int i = 0; i < sizeof(pins); i++){
    if(distance < (i * 50)){
      digitalWrite(pins[i], HIGH);
    }else{
      digitalWrite(pins[i], LOW);
    }
  }

  delay(1000);
}
