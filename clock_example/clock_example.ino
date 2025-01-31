// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // Interfacing pins

int wrapValue(int value, int minVal, int maxVal) {
    int range = maxVal - minVal + 1;
    if (range <= 0) return minVal;  // Prevent division by zero or invalid range
    return ((value - minVal) % range + range) % range + minVal;
}

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);

  // get second count since reset
  long seconds = millis() / 1000;

  // get millisecond count
  int ms = millis() % 1000;
  
  // print the number of seconds since reset:
  lcd.print(wrapValue(seconds / 3600, 0, 24));
  lcd.print(":");
  lcd.print(wrapValue(seconds / 60, 0, 60));
  lcd.print(":");  
  lcd.print(wrapValue(seconds, 0, 60));
  lcd.print(":");
  lcd.print(ms);
}
