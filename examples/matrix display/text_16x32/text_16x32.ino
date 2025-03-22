#include <RGBmatrixPanel.h>

#define CLK 8
#define OE 9
#define LAT 10
#define A A0
#define B A1
#define C A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

const char str[] = "deschis";

const int black = matrix.Color333(0, 0, 0);
const int white = matrix.Color333(255, 255, 255);

void setup() {
  matrix.begin();
}

void loop() {
  matrix.fillScreen(black);

  matrix.setTextColor(white);
  matrix.setCursor(0, 1);
  matrix.print(str);

  delay(20);
}