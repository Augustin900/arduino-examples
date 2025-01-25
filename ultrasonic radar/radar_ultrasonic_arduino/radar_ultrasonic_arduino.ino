#include<Servo.h>

//  Definition of constants
#define beep_start 100
#define min_distance  5
#define trigger 2
#define echo 3
#define servo 4

// Definition of sound speed (centimetres / microsecond)
#define c 0.034

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

void setup(){
  // Definition of input and output
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  myservo.attach(servo);
  Serial.begin(9600);
}
void spinSensor(){
for (int i = 0; i <= 181; i++){
  myservo.write(i);
  printToSerial(i);
  delay(15);
 }
 for(int i = 180; i >= 1; i--){
  myservo.write(i);
  printToSerial(i);
  delay(15); 
 }  
}
void printToSerial(int angle){
  Serial.print(angle);
  Serial.print(",");
  Serial.print(calcDist());
  Serial.print(".");
}
void loop(){
  spinSensor();
  // Waits  50 milliseconds before another measurement
  delay(150);
}
