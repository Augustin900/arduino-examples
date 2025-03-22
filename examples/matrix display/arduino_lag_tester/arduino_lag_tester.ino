#include <RGBmatrixPanel.h>

#define CLK 8 
#define OE 9
#define LAT A3
#define A A0
#define B A1
#define C A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

float angle1, angle2, angle3, angle4;
long hueShift = 0;

#define F2(progmem_ptr) (const __FlashStringHelper *)progmem_ptr

const char str[] PROGMEM = "Arduino Lag Tester";
int textX = matrix.width(),
    textMin = sizeof(str) * -12,
    hue;

static const int8_t PROGMEM sinetab[256] = {
     0,   2,   5,   8,  11,  15,  18,  21,
    24,  27,  30,  33,  36,  39,  42,  45,
    48,  51,  54,  56,  59,  62,  65,  67,
    70,  72,  75,  77,  80,  82,  85,  87,
    89,  91,  93,  96,  98, 100, 101, 103,
   105, 107, 108, 110, 111, 113, 114, 116,
   117, 118, 119, 120, 121, 122, 123, 123,
   124, 125, 125, 126, 126, 126, 126, 126,
   127, 126, 126, 126, 126, 126, 125, 125,
   124, 123, 123, 122, 121, 120, 119, 118,
   117, 116, 114, 113, 111, 110, 108, 107,
   105, 103, 101, 100,  98,  96,  93,  91,
    89,  87,  85,  82,  80,  77,  75,  72,
    70,  67,  65,  62,  59,  56,  54,  51,
    48,  45,  42,  39,  36,  33,  30,  27,
    24,  21,  18,  15,  11,   8,   5,   2,
     0,  -3,  -6,  -9, -12, -16, -19, -22,
   -25, -28, -31, -34, -37, -40, -43, -46,
   -49, -52, -55, -57, -60, -63, -66, -68,
   -71, -73, -76, -78, -81, -83, -86, -88,
   -90, -92, -94, -97, -99,-101,-102,-104,
  -106,-108,-109,-111,-112,-114,-115,-117,
  -118,-119,-120,-121,-122,-123,-124,-124,
  -125,-126,-126,-127,-127,-127,-127,-127,
  -128,-127,-127,-127,-127,-127,-126,-126,
  -125,-124,-124,-123,-122,-121,-120,-119,
  -118,-117,-115,-114,-112,-111,-109,-108,
  -106,-104,-102,-101, -99, -97, -94, -92,
   -90, -88, -86, -83, -81, -78, -76, -73,
   -71, -68, -66, -63, -60, -57, -55, -52,
   -49, -46, -43, -40, -37, -34, -31, -28,
   -25, -22, -19, -16, -12,  -9,  -6,  -3
};

const float radiuses[4] = {
65.2, 92.0, 163.2, 176.8
};

const float center_xs[4] = {
64.4, 46.4, 93.6, 16.4
}; 

const float center_ys[4] = {
34.8, 26.0, 56.0, -11.6
}; 

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
}

void loop() {
  int sx1 = (int)(cos(angle1) * radiuses[1] + center_xs[1]);
  int sx2 = (int)(cos(angle2) * radiuses[2] + center_xs[2]);
  int sx3 = (int)(cos(angle3) * radiuses[3] + center_xs[3]);
  int sx4 = (int)(cos(angle4) * radiuses[4] + center_xs[4]);
  int y1 = (int)(sin(angle1) * radiuses[1] + center_ys[1]);
  int y2 = (int)(sin(angle2) * radiuses[2] + center_ys[2]);
  int y3 = (int)(sin(angle3) * radiuses[3] + center_ys[3]);
  int y4 = (int)(sin(angle4) * radiuses[4] + center_ys[4]);

  for(int y = 0; y < matrix.height(); y++) {
    int x1 = sx1; 
    int x2 = sx2; 
    int x3 = sx3; 
    int x4 = sx4;
    for(int x = 0; x < matrix.width(); x++) {
      long value = hueShift
        + (int8_t)pgm_read_byte(sinetab + (uint8_t)((x1 * x1 + y1 * y1) >> 4))
        + (int8_t)pgm_read_byte(sinetab + (uint8_t)((x2 * x2 + y2 * y2) >> 4))
        + (int8_t)pgm_read_byte(sinetab + (uint8_t)((x3 * x3 + y3 * y3) >> 5))
        + (int8_t)pgm_read_byte(sinetab + (uint8_t)((x4 * x4 + y4 * y4) >> 5));
      matrix.drawPixel(x, y, matrix.ColorHSV(value * 3, 255, 75, true));
      x1--; x2--; x3--; x4--;
    }
    y1--; y2--; y3--; y4--;
  }

  angle1   += 0.03;
  angle2   -= 0.07;
  angle3   += 0.13;
  angle4   -= 0.15;
  if (hueShift > 360){hueShift = 0;} else {hueShift += 2;}

  matrix.setTextColor(matrix.Color333(255, 255, 255));
  matrix.setCursor(textX, 1);
  matrix.print(F2(str));

  if((--textX) < textMin) textX = matrix.width();

  delay(20);
}