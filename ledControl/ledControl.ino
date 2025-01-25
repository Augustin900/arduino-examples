#include <DHT.h>
#include <Servo.h>

#define DHTPIN 2     
#define DHTTYPE DHT11   
#define LEDPIN 13
#define SERVOPIN 8
#define TRIGPIN 10
#define ECHOPIN 11
#define JOYX A0
#define JOYY A1

DHT dht(DHTPIN, DHTTYPE);
Servo myServo;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LEDPIN, OUTPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  myServo.attach(SERVOPIN);
}

float readDistance() {
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  long duration = pulseIn(ECHOPIN, HIGH);
  float distance = (duration * 0.034) / 2;
  return distance;
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    if (command == "READ") {
      float h = dht.readHumidity();
      float t = dht.readTemperature();
      float d = readDistance();
      int joyX = analogRead(JOYX);
      int joyY = analogRead(JOYY);
      Serial.print(h);
      Serial.print(",");
      Serial.print(t);
      Serial.print(",");
      Serial.print(d);
      Serial.print(",");
      Serial.print(joyX);
      Serial.print(",");
      Serial.println(joyY);
    } else if (command.startsWith("LED")) {
      int state = command.substring(4).toInt();
      digitalWrite(LEDPIN, state);
    } else if (command.startsWith("SERVO")) {
      int angle = command.substring(6).toInt();
      myServo.write(angle);
    }
  }
}
