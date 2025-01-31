#include <RGBmatrixPanel.h>

#define CLK 8
#define OE 9
#define LAT 10
#define A A0
#define B A1
#define C A2
#define D A3

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

const int width = matrix.width();
const int height = matrix.height();

void setup(){
  matrix.begin();
}

void draw_bg(){
  for(int x = 0; x < width; x++){
    for(int y = 0; y < height; y++){
      matrix.drawPixel(x, y, matrix.Color333(random(255), random(255), random(255)));
    }
  }
}

void loop(){
  draw_bg();

  delay(20);
}