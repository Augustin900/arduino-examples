#include <RGBmatrixPanel.h>

#define CLK 8
#define OE 9
#define LAT A3
#define A A0
#define B A1
#define C A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

#define F2(progmem_ptr) (const __FlashStringHelper *)progmem_ptr

const char str[] PROGMEM = "POWER GEN";
int textX = matrix.width(),
    textMin = sizeof(str) * -12,
    hue;

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setTextSize(2);
}

void loop() {
  matrix.fillScreen(0);

  matrix.setTextColor(matrix.ColorHSV(hue, 255, 255, true));
  matrix.setCursor(textX, 1);
  matrix.print(F2(str));

  if((--textX) < textMin) textX = matrix.width();
  hue += 7;
  if(hue >= 1536) hue -= 1536;

  #if !defined(__AVR__)
    delay(20);
  #endif
}