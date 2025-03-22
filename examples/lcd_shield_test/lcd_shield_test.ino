#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // Interfacing pins

int x, y;

byte inverted_circle[] = {
  0x11, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x11, 0x00
};
byte normal_circle[] = {
  0x0e, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e, 0x00
};

void setup() {
  lcd.begin(16, 2); // Set up the LCD's number of columns and rows

  // custom shapes
  lcd.createChar(0, normal_circle);
  lcd.createChar(1, inverted_circle);
}

void loop() {
  // clear the screen
  lcd.clear();

  // button variable
  int button_x = analogRead(0);

  // circle style
  int circle = 0;

  // move circle according to input
  if (button_x < 60) {
    x++;
  } else if (button_x < 200) {
    y++;
  } else if (button_x < 400) {
    y--;
  } else if (button_x < 600) {
    x--;
  } else if (button_x < 800) {
    circle = 1;
  }

  // print to display
  lcd.setCursor(x, y);
  lcd.write(circle);

  // add delay to solve input bouncing
  delay(200);
}