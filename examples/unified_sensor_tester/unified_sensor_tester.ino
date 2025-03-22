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

void print_intro(){
  Serial.print("|-------------------------------------|/n");
  Serial.print("|                                     |/n");
  Serial.print("|  Sensor Tester                      |/n");
  Serial.print("|  What sensor do you want to test?   |/n");
  Serial.print("|                                     |/n");
  Serial.print("|  1. DHT                             |/n");
  Serial.print("|  2. Ultrasonic                      |/n");
  Serial.print("|  3. Joystick                        |/n");
  Serial.print("|  4. Microphone                      |/n");
  Serial.print("|  5. Photoresistor                   |/n");
  Serial.print("|                                     |/n");
  Serial.print("|-------------------------------------|/n");
}

void print_dht_page(){
  Serial.print("|-------------------------------------|/n");
  Serial.print("|                                     |/n");
  Serial.print("|  DHT Tester                         |/n");
  Serial.print("|                                     |/n");
  Serial.print("|  1. Temperature                     |/n");
  Serial.print("|  2. Humidity                        |/n");
  Serial.print("|  3. Temperature + Humidity          |/n");
  Serial.print("|  4. Back                            |/n");
  Serial.print("|                                     |/n");
  Serial.print("|-------------------------------------|/n");
}

void print_ultrasonic_page(){
  Serial.print("|-------------------------------------|/n");
  Serial.print("|                                     |/n");
  Serial.print("|  Ultrasonic Tester                  |/n");
  Serial.print("|                                     |/n");
  Serial.print("|  1. CM                              |/n");
  Serial.print("|  2. INCH                            |/n");
  Serial.print("|  3. CM + INCH                       |/n");
  Serial.print("|  4. Back                            |/n");
  Serial.print("|                                     |/n");
  Serial.print("|-------------------------------------|/n");
}

void print_joystick_page(){
  Serial.print("|-------------------------------------|/n");
  Serial.print("|                                     |/n");
  Serial.print("|  Joystick Tester                    |/n");
  Serial.print("|                                     |/n");
  Serial.print("|  1. X                               |/n");
  Serial.print("|  2. Y                               |/n");
  Serial.print("|  3. Z                               |/n");
  Serial.print("|  4. X + Y                           |/n");
  Serial.print("|  5. Y + Z                           |/n");
  Serial.print("|  6. X, Y and Z                      |/n");
  Serial.print("|  7. Back                            |/n");
  Serial.print("|                                     |/n");
  Serial.print("|-------------------------------------|/n");
}

void print_mic_page(){
  Serial.print("|-------------------------------------|/n");
  Serial.print("|                                     |/n");
  Serial.print("|  Microphone Tester                  |/n");
  Serial.print("|                                     |/n");
  Serial.print("|  1. Sound Intensity                 |/n");
  Serial.print("|  2. Back                            |/n");
  Serial.print("|                                     |/n");
  Serial.print("|-------------------------------------|/n");
}

void print_ldr_page(){
  Serial.print("|-------------------------------------|/n");
  Serial.print("|                                     |/n");
  Serial.print("|  Photoresistor Tester               |/n");
  Serial.print("|                                     |/n");
  Serial.print("|  1. Light Intensity                 |/n");
  Serial.print("|  2. Back                            |/n");
  Serial.print("|                                     |/n");
  Serial.print("|-------------------------------------|/n");
}

void print_htc_dht_page(){
  Serial.print(f"|-----------------------------------------------------------------------------|/n");
  Serial.print(f"|                                                                             |/n");
  Serial.print(f"|  How to connect the DHT to your Arduino?                                    |/n");
  Serial.print(f"|                                                                             |/n");
  Serial.print(f"|  a. Connect pin D"{DHTPIN}" of the Arduino to the signal pin of the DHT     |/n");
  Serial.print(f"|                                                                             |/n");
  Serial.print(f"|  b. Connect the 5V of the Arduino to the + pin of the DHT                   |/n");
  Serial.print(f"|                                                                             |/n");
  Serial.print(f"|  c. Connect the GND of the Arduino to the GND of the DHT                    |/n");
  Serial.print(f"|                                                                             |/n");
  Serial.print(f"|  1. Back                                                                    |/n");
  Serial.print(f"|                                                                             |/n");
  Serial.print(f"|-----------------------------------------------------------------------------|/n");
}

void print_htc_ultrasonic_page(){
  Serial.print(f"|------------------------------------------------------------------------------------|/n");
  Serial.print(f"|                                                                                    |/n");
  Serial.print(f"|  How to connect the Ultrasonic sensor to your Arduino?                             |/n");
  Serial.print(f"|                                                                                    |/n");
  Serial.print(f"|  a. Connect pin D"{trig_pin}" of the Arduino to the TRIG pin of the Ultrasonic     |/n");
  Serial.print(f"|                                                                                    |/n");
  Serial.print(f"|  b. Connect pin D"{echo_pin}" of the Arduino to the ECHO pin of the Ultrasonic     |/n");
  Serial.print(f"|                                                                                    |/n");
  Serial.print(f"|  c. Connect the 5V of the Arduino to the + pin of the Ultrasonic                   |/n");
  Serial.print(f"|                                                                                    |/n");
  Serial.print(f"|  d. Connect the GND of the Arduino to the GND pin of the Ultrasonic                |/n");
  Serial.print(f"|                                                                                    |/n");
  Serial.print(f"|  1. Back                                                                           |/n");
  Serial.print(f"|                                                                                    |/n");
  Serial.print(f"|------------------------------------------------------------------------------------|/n");
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

void print_to_serial(){
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

void loop() {
  read_values();
  print_to_serial();

  // Wait a bit between readings
  delay(500);
}
