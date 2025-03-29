#include <Adafruit_GFX.h>
#include <RGBmatrixPanel.h>

#define CLK 8
#define OE 9
#define LAT A3
#define A A0
#define B A1
#define C A2
#define button 12

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

const int blue = matrix.Color333(0, 0, 5);
const int yellow = matrix.Color333(5, 5, 0);
const int red = matrix.Color333(5, 0, 0);
const int black = matrix.Color333(0, 0, 0);

const int center_y = 0;
const int width = matrix.width() / 3;
const int height = matrix.height();

void setup() {
  matrix.begin();
  //Serial.begin(9600);
  // we draw the flag 
  matrix.fillRect(0, center_y, width, height, blue);
  matrix.fillRect(width, center_y, (width * 2), height, yellow);
  matrix.fillRect((width * 2), center_y, (width * 3), height, red);

  //Serial.println("|--- Matrix Display Tester ---|");
  //delay(2500);
}

void loop() {
  /*for(int r = 0; r < 9; r++){
    for(int g = 0; g < 9; g++){
      for(int b = 0; b < 9; b++){
          Serial.print("|-- Button: ");
          Serial.println(digitalRead(button));
          if(digitalRead(button) == 0){
            matrix.fillScreen(matrix.Color333(r, g, b));

            Serial.print("|-- R: ");
            Serial.println(r);
            Serial.print("|-- G: ");
            Serial.println(g);
            Serial.print("|-- B: ");
            Serial.println(b);
          }else{
            matrix.fillScreen(black);
          }
        delay(100);
      }
    }
  }*/
}