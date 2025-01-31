#include <IRremote.h>

// Define the pin connected to the IR receiver
#define IR_RECEIVE_PIN 2

void setup() {
  Serial.begin(9600);
  // Set up the IR receiver pin
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("IR Receiver is ready.");
}

void loop() {
  // Check if a signal is received
  if (IrReceiver.decode()) {
    // Print the received IR code in HEX format
    Serial.print("IR Code: ");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.resume();  // Prepare to receive the next signal
  }
}
