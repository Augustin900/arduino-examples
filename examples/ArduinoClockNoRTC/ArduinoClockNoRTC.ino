#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // Interfacing pins

int h, m, s, flag, TIME;
const int hs = 0;
const int ms = 1;
int state1, state2;

char hour_string;
char min_string;
char sec_string;
char output_string;

void setup(){
  lcd.begin(16, 2);
  pinMode(hs, INPUT_PULLUP);
  pinMode(ms, INPUT_PULLUP);
}

int addto(int number, char extra_chars){
  return number += extra_chars;
}

void loop(){
  lcd.clear();

  lcd.setCursor(0, 0);
  s++;

  if (h < 10){
    hour_string = "0";
  }else{
    hour_string = "";
  }
  output_string = addto(h, hour_string);
  lcd.print(output_string);

  lcd.print(":");

  if (m < 10){
    min_string = "0";
  }else{
    min_string = "";
  }
  output_string = addto(h, min_string);
  lcd.print(output_string);

  lcd.print(":");

  if (s < 10){
    sec_string = "0";
  }else{
    sec_string = "";
  }
  output_string = addto(h, sec_string);
  lcd.print(output_string);

  if (s == 60){
    s = 0;
    m = m + 1;
  }
  if (m == 60){
    m = 0;
    h++;
    flag++;
  }
  if (h == 13){
    h = 1;
  }

  lcd.setCursor(0, 1);
  
  state1 = digitalRead(hs);
  if (state1 == 0){
    h++;
    flag++;
    if (flag == 24) flag = 0;
    if (h == 24) h = 0;
  }

  state2 = digitalRead(ms);
  if (state2 == 0){
    s = 0;
    m = m + 1;
  }

  delay(1000);
}