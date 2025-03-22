#include "Servo.h"

#define beep_start 100
#define min_distance  5
#define trigger 5
#define echo 6
#define buzzer 7
#define c 0.034

bool relayState = false;
int pos;

Servo myservo;

int calcDist(){
  // Before measurement,  the trigger is set to low level
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);

  // Send one pulse (trigger goes high level for 10 microseconds)
  digitalWrite(trigger,  HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  return  pulseIn(echo, HIGH) / 2 * c;
}

void setup() {
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  myservo.attach(9);
}

void loop() {
  int distance = calcDist();

  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance < min_distance){
      myservo.write(10);              
      delay(5);
      myservo.write(20);              
      delay(5);
      myservo.write(30);
      delay(5);
      myservo.write(40);              
      delay(5);
      myservo.write(50);              
      delay(5);
      myservo.write(60);              
      delay(5);
      myservo.write(70);              
      delay(5);
      myservo.write(80);              
      delay(5);
      myservo.write(90);              
      delay(500);
      myservo.write(80);              
      delay(5);
      myservo.write(70);              
      delay(5);
      myservo.write(60);              
      delay(5);
      myservo.write(50);              
      delay(5);
      myservo.write(40);              
      delay(5);
      myservo.write(30);              
      delay(5);
      myservo.write(20);              
      delay(5);
      myservo.write(10);              
      delay(5);                         
  }
}