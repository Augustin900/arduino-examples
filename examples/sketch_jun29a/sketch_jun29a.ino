#include <DHT.h>
#include <Ultrasonic.h>
#include <Joystick.h>

#define DHTPIN 2      // Pin where DHT is connected
#define DHTTYPE DHT11 // DHT 11 or DHT22
#define trig_pin 7
#define echo_pin 6
#define joy_x_pin A0
#define joy_y_pin A1
#define joy_sw_pin 3
#define mic_pin A2
#define ldr_pin A3
#define delay_time 2000

void print_home_text(){
  Serial.println("|-------------------------------------|");
  Serial.println("|                                     |");
  Serial.println("|  Augustin's Menu Test               |");
  Serial.println("|                                     |");
  Serial.println("|  1. Sensor Tester                   |");
  Serial.println("|  2. Help                            |");
  Serial.println("|                                     |");
  Serial.println("|-------------------------------------|");
}

void print_help_text(){
  Serial.println("|-------------------------------------|");
  Serial.println("|                                     |");
  Serial.println("|  Help                               |");
  Serial.println("|                                     |");
  Serial.println("|  1. How to connect DHT?             |");
  Serial.println("|  2. How to connect Ultrasonic?      |");
  Serial.println("|  3. How to connect Joystick?        |");
  Serial.println("|  4. How to connect Microphone?      |");
  Serial.println("|  5. How to connect Photoresistor?   |");
  Serial.println("|  6. Back                            |");
  Serial.println("|                                     |");
  Serial.println("|-------------------------------------|");
}

void print_sensor_test_text(){
  Serial.println("|-------------------------------------|");
  Serial.println("|                                     |");
  Serial.println("|  Sensor Tester                      |");
  Serial.println("|                                     |");
  Serial.println("|  1. DHT                             |");
  Serial.println("|  2. Ultrasonic                      |");
  Serial.println("|  3. Joystick                        |");
  Serial.println("|  4. Microphone                      |");
  Serial.println("|  5. Photoresistor                   |");
  Serial.println("|  6. Back                            |");
  Serial.println("|                                     |");
  Serial.println("|-------------------------------------|");
}

void print_htc_dht_text(){
  Serial.println("|---------------------------------------------------------------------------------------|");
  Serial.println("|                                                                                       |");
  Serial.println("|  How to connect the DHT to your Arduino?                                              |");
  Serial.println("|                                                                                       |");
  Serial.println("|  a. Connect pin D2 (or any other pin) of the Arduino to the signal pin of the DHT     |");
  Serial.println("|                                                                                       |");
  Serial.println("|  b. Connect the 5V of the Arduino to the + pin of the DHT                             |");
  Serial.println("|                                                                                       |");
  Serial.println("|  c. Connect the GND of the Arduino to the GND of the DHT                              |");
  Serial.println("|                                                                                       |");
  Serial.println("|  1. Back                                                                              |");
  Serial.println("|                                                                                       |");
  Serial.println("|---------------------------------------------------------------------------------------|");
}

void print_htc_ultrasonic_text(){
  Serial.println("|-------------------------------------------------------------------------------------------------------|");
  Serial.println("|                                                                                                       |");
  Serial.println("|  How to connect the Ultrasonic sensor to your Arduino?                                                |");
  Serial.println("|                                                                                                       |");
  Serial.println("|  a. Connect pin D7 (or any other pin) of the Arduino to the TRIG pin of the Ultrasonic                |");
  Serial.println("|                                                                                                       |");
  Serial.println("|  b. Connect pin D6 (or any other pin) of the Arduino to the ECHO pin of the Ultrasonic                |");
  Serial.println("|                                                                                                       |");
  Serial.println("|  c. Connect the 5V of the Arduino to the + pin of the Ultrasonic                                      |");
  Serial.println("|                                                                                                       |");
  Serial.println("|  d. Connect the GND of the Arduino to the GND pin of the Ultrasonic                                   |");
  Serial.println("|                                                                                                       |");
  Serial.println("|  1. Back                                                                                              |");
  Serial.println("|                                                                                                       |");
  Serial.println("|-------------------------------------------------------------------------------------------------------|");
}

void print_htc_joystick_text(){
  Serial.println("|-------------------------------------------------------------------------------------------------------|");
  Serial.println("|                                                                                                       |");
  Serial.println("|  How to connect the Joystick to your Arduino?                                                         |");
  Serial.println("|                                                                                                       |");
  Serial.println("|  a. Connect pin A0 (or any other pin) of the Arduino to the X pin of the Joystick                     |");
  Serial.println("|                                                                                                       |");
  Serial.println("|  b. Connect pin A1 (or any other pin) of the Arduino to the Y pin of the Joystick                     |");
  Serial.println("|                                                                                                       |");
  Serial.println("|  c. Connect the 5V of the Arduino to the + pin of the Joystick                                        |");
  Serial.println("|                                                                                                       |");
  Serial.println("|  d. Connect the GND of the Arduino to the GND pin of the Joystick                                     |");
  Serial.println("|                                                                                                       |");
  Serial.println("|  1. Back                                                                                              |");
  Serial.println("|                                                                                                       |");
  Serial.println("|-------------------------------------------------------------------------------------------------------|");
}

// variable to save the last executed time
unsigned long lastMillis, currentMillis;

float h, t;
int distancec, distancei, mic_value, ldr_value;

DHT dht(DHTPIN, DHTTYPE);
Ultrasonic ultrasonic(trig_pin, echo_pin);
Joystick joystick(joy_x_pin, joy_y_pin, joy_sw_pin);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void read_values(){
  unsigned long currentMillis = millis();

  if (currentMillis - lastMillis >= delay_time) {
    // save the last executed time
    lastMillis = currentMillis;

    // Read temperature and humidity
    h = dht.readHumidity();
    t = dht.readTemperature();
  }

  // Read distance in CM
  distancec = ultrasonic.read();

  // Read distance in INCH
  distancei = ultrasonic.read(INC);

  // Read microphone value
  mic_value = analogRead(mic_pin);

  // Read photoresistor value
  ldr_value = analogRead(ldr_pin);
}

void print_to_serial(sensor_choice){
  // Print the data to the serial monitor
  Serial.print("DHT: \n");
  Serial.print("|--- Humidity: ");
  Serial.print(h);
  Serial.println(" %");
  Serial.print("|--- Temperature: ");
  Serial.print(t);
  Serial.println(" *C");
  Serial.print("Ultrasonic: \n");
  Serial.print("|--- Distance (CM): ");
  Serial.println(distancec);
  Serial.print("|--- Distance (INCH): ");
  Serial.println(distancei);
  Serial.print("Joystick: \n");
  joystick.print("|--- X: ", "\n|--- Y: ", "\n|--- Z: ", 0, 100);
  Serial.println("");
  Serial.print("Microphone: ");
  Serial.println(mic_value);
  Serial.print("Photoresistor: ");
  Serial.println(ldr_value);
}

void loop(){
  print_home_text();
  while (Serial.available() == 0){}

  int main_choice = Serial.parseInt();

  switch(main_choice){
    case 1:
      print_sensor_test_text();

      while (Serial.available() == 0){}

      int sensor_choice = Serial.parseInt();

      print_to_serial(sensor_choice);
  }
}