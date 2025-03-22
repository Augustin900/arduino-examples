#include <Wire.h>
#include <LiquidCrystal.h>

// Create an LCD object (update the address and dimensions for your LCD)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // select the pins used on the LCD panel

// define collumns and rows
const int cols = 16;
const int rows = 2;

// Ball struct to hold the properties of each ball
struct Ball {
  int x, y;      // Position
  int dx, dy;    // Velocity
  char symbol;   // Symbol representing the ball
};

// Define the number of balls
const int numBalls = 3;
Ball balls[numBalls];

// Setup function
void setup() {
  // Initialize the LCD
  lcd.begin(cols, rows);
  lcd.clear();
  
  // Initialize the balls
  for (int i = 0; i < numBalls; i++) {
    balls[i].x = random(0, cols);  // Random starting x-position
    balls[i].y = random(0, rows);     // Random starting y-position
    balls[i].dx = random(0, 2) == 0 ? 1 : -1;  // Random x-direction
    balls[i].dy = random(0, 2) == 0 ? 1 : -1;  // Random y-direction
    balls[i].symbol = 'o';                // Unique character for each ball
  }
}

// Loop function
void loop() {
  // Clear the screen
  lcd.clear();

  // Update each ball's position
  for (int i = 0; i < numBalls; i++) {
    // Erase the ball's current position (handled by lcd.clear())
    
    // Update position
    balls[i].x += balls[i].dx;
    balls[i].y += balls[i].dy;

    // Check for collisions with walls
    if (balls[i].x >= cols || balls[i].x < 0) {
      balls[i].dx = -balls[i].dx;  // Reverse x direction
      balls[i].x = constrain(balls[i].x, 0, cols - 1);
    }
    if (balls[i].y >= rows || balls[i].y < 0) {
      balls[i].dy = -balls[i].dy;  // Reverse y direction
      balls[i].y = constrain(balls[i].y, 0, rows);
    }

    // Draw the ball in its new position
    lcd.setCursor(balls[i].x, balls[i].y);
    lcd.print(balls[i].symbol);
  }

  // Delay for smooth animation
  delay(200);
}
