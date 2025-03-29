#include <Ultrasonic.h>

const int trigPin = 12;
const int echoPin = 13;

Ultrasonic ultrasonic(trigPin, echoPin);
long duration, distance;

int pins[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

void setup() {
  Serial.begin(9600);

  for(int i = 0; i < sizeof(pins); i++){
    pinMode(pins[i], OUTPUT);
  }
}

void sense_distance() {
  // Pass INC as a parameter to get the distance in inches
  distance = ultrasonic.read();

  Serial.print("Distance: ");
  Serial.println(distance);

  for(int i = 0; i < sizeof(pins); i++){
    if(distance > (i * 10)){
      digitalWrite(pins[i], HIGH);
    }else{
      digitalWrite(pins[i], LOW);
    }
  }

  delay(250);
}

void led_pulse(){
    for(int i = 0; i < sizeof(pins); i++){
      digitalWrite(pins[i], HIGH);
      delay(25);
    }
    for(int i = 0; i < sizeof(pins); i++){
      digitalWrite(pins[i], LOW);
      delay(25);
    }
}

void loop(){
  //led_pulse();
  sense_distance();
}
