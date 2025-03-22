#include <Adafruit_GFX.h>
#include <RGBmatrixPanel.h>

#define CLK 2   // Clock pin
#define OE  8   // Output Enable pin
#define LAT 9  // Latch pin
#define A   A0  // Address pin A
#define B   A1  // Address pin B
#define C   A2  // Address pin C
#define D   A3  // Address pin D

// Create RGB Matrix Panel object
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

void setup() {
  matrix.begin();
  matrix.fillScreen(matrix.Color333(255, 255, 255));
  matrix.setTextSize(1);          // Set text size
  matrix.setTextColor(matrix.Color333(0, 0, 0)); // Red color
  matrix.setCursor(1, 0);         // Start position
  matrix.print("Hello!");         // Display text
}

void loop() {
  // Add animations or effects here if needed
}
