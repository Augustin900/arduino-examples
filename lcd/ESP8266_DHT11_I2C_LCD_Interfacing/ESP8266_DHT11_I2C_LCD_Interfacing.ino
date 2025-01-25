#include "DHT.h"
#include "Wire.h"
#include <LiquidCrystal.h>

#define DHTPIN D3
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int rs = 11, en = 8, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(115200);
  dht.begin();
  lcdSetup();
}
void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print((String) t + " " + (char)223 + "C");
  lcd.setCursor(6,2);
  lcd.print((String) h + " %");
  delay(2000);
}
void lcdSetup(){
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(0,2);
  lcd.print("Humi:");
}