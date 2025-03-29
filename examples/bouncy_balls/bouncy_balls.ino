#include <PxMatrix.h>

// Pins for LED MATRIX
#define A 2
#define B 3
#define C 4
#define D 5
#define LAT 7
#define OE 8

#define COLOR_DEPTH 8
#define MATRIX_WIDTH 64
#define MATRIX_HEIGHT 32

PxMATRIX display(MATRIX_WIDTH, MATRIX_HEIGHT, LAT, OE, A, B, C, D);

// Animation settings
#define BALL_COUNT 3

struct Ball{
  int x, y;
  int vx, vy;
  uint16_t color;
};

Ball balls[BALL_COUNT];

void setup() {
  // Initialize the matrix
  display.begin(COLOR_DEPTH);

  // Initialize balls
  for (int i = 0; i < BALL_COUNT; i++) {
    balls[i] = {random(MATRIX_WIDTH), random(MATRIX_HEIGHT), random(1, 3), random(1, 3), random(0xFFFF)};
  }

  randomSeed(analogRead(0));
}

void loop() {
  display.clearDisplay();

  drawBouncingBalls();

  display.showBuffer();
  delay(50);
}

void drawBouncingBalls() {
  for (int i = 0; i < BALL_COUNT; i++) {
    // Draw ball
    display.fillCircle(balls[i].x, balls[i].y, 2, balls[i].color);

    // Update position
    balls[i].x += balls[i].vx;
    balls[i].y += balls[i].vy;

    // Bounce off walls
    if (balls[i].x <= 0 || balls[i].x >= MATRIX_WIDTH - 1) balls[i].vx *= -1;
    if (balls[i].y <= 0 || balls[i].y >= MATRIX_HEIGHT - 1) balls[i].vy *= -1;
  }
}