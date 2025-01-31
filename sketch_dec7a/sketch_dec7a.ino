#include <Adafruit_GFX.h>
#include <RGBmatrixPanel.h>

#define CLK 8
#define OE 9
#define LAT A3
#define A A0
#define B A1
#define C A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

const int red = matrix.Color333(7, 0, 0); // red
const int black = matrix.Color333(0, 0, 0); // black
const int white = matrix.Color333(7, 7, 7); // white

const int ball_size = 2;

const int width = matrix.width();
const int height = matrix.height();

int ball_x = width / 2;
int ball_y = height / 2;

int hue;

long random_number(int range){
  return random((0 - range), range);
}

int get_out_of_zero(int number){
  int i = random_number(number);
  while(i != 0){
    i = random_number(number);
  }
  return i;
}

int x_mod = get_out_of_zero(1);
int y_mod = get_out_of_zero(1);

const int top_bound = 0;
const int bottom_bound = height;
const int left_bound = 0;
const int right_bound = width;

bool print_text = false;

void setup(){
  Serial.begin(9600);

  // Initialize matrix...
  matrix.begin();

  if(print_text){
    // Print text
    Serial.println("|--- Bouncing Balls Debug Console ---|");
  }
}

void print_to_serial(){
  // Prints data to serial monitor
  Serial.print("|- Ball X: ");
  Serial.print(ball_x);
  Serial.print(", Y: ");
  Serial.println(ball_y);
}

void loop(){
  matrix.fillScreen(black);

  // Moves the ball on the X axis
  ball_x + x_mod;
  if(ball_x > right_bound || ball_x < left_bound){
    x_mod - x_mod * 2;
  }

  // Moves the ball on the Y axis
  ball_y + y_mod;
  if(ball_y > bottom_bound || ball_y < top_bound){
    y_mod - y_mod * 2;
  }

  // Draws ball using fillCircle
  matrix.fillCircle(ball_x, ball_y, ball_size, matrix.ColorHSV(hue, 255, 255, false));

  if(print_text){
    print_to_serial();
  }

  // Change hue
  if(hue > 1536) hue = 0; else hue += 7;

  delay(25);
}