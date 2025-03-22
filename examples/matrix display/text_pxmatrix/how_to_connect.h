/*
|--- Connecting the Matrix
|- First, connect the two halves of the matrix like this:

PI (input)    PO (output)
Red 1         Red 0
Green 0       Red 1
Green 1       Green 0
Blue 0        Green 1
Blue 1        Blue 0

|- then connect the Arduino like this:

PI (input)        Arduino Pin
Input A           D2
Input B           D3
Input C           D4
Input D           D5
Input E           D6
Latch             D7
Output Enable     D8
Clock             D13 (for 168 or 328)
Red 0             D11 (for 168 or 328)

|--- Connecting the DHT
|- Connect the DHT to the Arduino like this:

DHT Pin     Arduino Pin
1           GND
2           5V
3           D9
4           GND (if your sensor has 4 pins)

|--- Connecting the Ultrasonic
|- Connect the Ultrasonic to the Arduino like this:

Ultrasonic Pin    Arduino Pin
1                 GND
2                 5V
3                 D10
4                 D11

|--- Connecting the Joystick
|- Connect the Joystick to the Arduino like this:

Joystick Pin     Arduino Pin
1                GND
2                5V
3                A0
4                A1
5                D12

|--- Connecting the Microphone
|- Connect the Microphone to the Arduino like this:

Microphone Pin     Arduino Pin
1                  GND
2                  5V
3                  A2

|--- Connecting the Photoresistor
|- Connect the Photoresistor to the Arduino like this:

Photoresistor Pin     Arduino Pin
1                     GND
2                     5V
3                     A3
*/