// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  // print from 0 to 9:
  for (int thisChar = 0; thisChar < 10; thisChar++) {
    lcd.setCursor(thisChar, 0);
    lcd.print(thisChar);
    lcd.setCursor(thisChar, 1);
    lcd.print(thisChar);
    delay(150);
  }

  // clear screen for the next loop:
  lcd.clear();
}
