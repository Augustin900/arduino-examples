// Unified Sensor Tester - too big for an Uno or Nano.
// Please use a Mega, ESP8266 or ESP32 so that the sketch would fit.

#include <PxMatrix.h>
#include <DHT.h>
#include <NewPing.h>
#include <Encoder.h>

// Matrix display
#define P_A 2
#define P_B 3
#define P_C 4
#define P_D 5
#define P_E 6
#define P_LAT 7
#define P_OE 8
PxMATRIX display(64, 32, P_LAT, P_OE, P_A, P_B, P_C, P_D, P_E);

// DHT sensor
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Ultrasonic Sensor
#define TRIG_PIN 12
#define ECHO_PIN 13
NewPing sonar(TRIG_PIN, ECHO_PIN);

// Joystick
#define JOY_X A0
#define JOY_Y A1
#define JOY_BTN 9

// Microphone
#define MIC_PIN A2

// Photoresistor
#define LDR_PIN A3

// Rotary Encoder
#define ENC_A 9
#define ENC_B 10
Encoder rotaryEncoder(ENC_A, ENC_B);

void setup() {
  Serial.begin(9600);
  
  // Initialize display
  display.begin(16);

  // Initialize sensors
  dht.begin();
  pinMode(JOY_BTN, INPUT_PULLUP);
  pinMode(MIC_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);
}

void loop() {
  display.clearDisplay();
  
  // Read sensors
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();
  unsigned int distance = sonar.ping_cm();
  int joyX = analogRead(JOY_X);
  int joyY = analogRead(JOY_Y);
  bool joyPressed = !digitalRead(JOY_BTN);
  int micValue = analogRead(MIC_PIN);
  int ldrValue = analogRead(LDR_PIN);
  long encoderValue = rotaryEncoder.read();

  // Display data
  display.setCursor(0, 0);

  // DHT
  display.print("Temp: "); 
  display.print(temp); 
  display.println("C");
  display.print("Hum: "); 
  display.print(humidity); 
  display.println("%");
  Serial.print("Temp: "); 
  Serial.print(temp); 
  Serial.print(" *C, Hum: "); 
  Serial.print(humidity); 
  Serial.println("%");

  // Ultrasonic
  display.print("Dist: "); 
  display.print(distance); 
  display.println("cm");
  Serial.print("Dist: "); 
  Serial.print(distance); 
  Serial.println(" cm");

  // Joystick
  display.print("JoyX: ");
  display.print(joyX); 
  display.print(", Y: "); 
  display.println(joyY);
  Serial.print("JoyX: ");
  Serial.print(joyX); 
  Serial.print(", Y: "); 
  Serial.println(joyY);
  if (joyPressed) display.println(" Pressed");
  if (joyPressed) Serial.println(" Pressed");

  // Microphone
  display.print("Mic: "); 
  display.print(micValue);
  Serial.print("Mic: "); 
  Serial.println(micValue);

  // Photoresistor
  display.print("LDR: "); 
  display.print(ldrValue);
  Serial.print("LDR: "); 
  Serial.println(ldrValue);

  // Encoder
  display.print("Enc: "); 
  display.print(encoderValue);
  Serial.print("Enc: "); 
  Serial.println(encoderValue);

  long start_time = millis();
  while((millis() - start_time) < 500)
    display.display(500);

  //delay(500);
}
