#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 6     // Digital pin connected to the DHT sensor

// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11
//#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

const int rs = 11, en = 8, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Generally, you should use "unsigned long" for variables that hold time,
// as the value will quickly become too large for an int to store
unsigned long previousMillis = 0;    // will store last time DHT was updated

// Updates DHT readings every 2 seconds
const long interval = 2000;  

void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  dht.begin();
  lcd.begin(16, 2);
}

void loop(){  
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    lcd.clear();
           
    // save the last time you updated the DHT values
    previousMillis = currentMillis;
    // Read temperature as Celsius (the default)
    float t = dht.readTemperature();
    float h = dht.readHumidity();
    // if temperature read failed, don't change t value
    if (isnan(t) || isnan(h)) {
      Serial.println("Failed to read!");
      lcd.print("Failed to read!");
    }
    else {
      Serial.println(t);
      Serial.println(h);
      lcd.setCursor(0, 0);
      lcd.print(t);
      lcd.print("C");
      lcd.print(" / ");
      lcd.print(h);
      lcd.print("%");
      lcd.setCursor(0, 1);
    }
  }
}