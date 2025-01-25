#include <RGBmatrixPanel.h>

#define CLK 8
#define OE 9
#define LAT A3
#define A A0
#define B A1
#define C A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

void setup() {
  matrix.begin();

  matrix.fillScreen(matrix.Color333(0, 7, 0));

  matrix.drawRect(0, 0, 32, 16, matrix.Color333(7, 7, 0));

  matrix.drawLine(0, 0, 31, 15, matrix.Color333(7, 0, 0));
  matrix.drawLine(15, 0, 15, 15, matrix.Color333(7, 0, 7));
  matrix.drawLine(31, 0, 0, 15, matrix.Color333(7, 0, 0));
  matrix.drawLine(0, 7.5, 31, 7.5, matrix.Color333(7, 0, 7));
}

void loop() {}
