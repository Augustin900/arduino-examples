#include <RGBmatrixPanel.h>

#define CLK 8
#define OE 9
#define LAT A3
#define A A0
#define B A1
#define C A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

int ball_x_1, ball_x_2, 
int ball_x_3 = 15;
int ball_x_4 = 15;
int ball_x_5 = 15;

int ball_y_1 = 7.5;
int ball_y_2 = 7.5;
int ball_y_3 = 7.5;
int ball_y_4 = 7.5;
int ball_y_5 = 7.5;

const int red = matrix.Color333(7, 0, 0);    // red
const int yellow = matrix.Color333(7, 7, 0); // yellow
const int purple = matrix.Color333(7, 0, 7); // purple
const int green = matrix.Color333(0, 7, 0);  // green
const int blue = matrix.Color333(0, 0, 7);   // blue

const int width = matrix.width();
const int height = matrix.height();

int x_mod_1, y_mod_1, x_mod_2, y_mod_2, x_mod_3, y_mod_3, x_mod_4, y_mod_4, x_mod_5, y_mod_5 = 1;

void setup(){
  matrix.begin();
}

void loop(){
  ball_x_1 += x_mod;
  if(ball_x_1 > width || ball_x_1 < 0){
    x_mod -= x_mod * 2;
  }
  ball_y_1 += y_mod;
  if(ball_y_1 > height || ball_y_1 < 0){
    y_mod -= y_mod * 2;
  }

}