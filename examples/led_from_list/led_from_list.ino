int pins[3] = {2, 3, 4};

void setup() {
  for(int i = 0; i < sizeof(pins); i++){
    pinMode(pins[i], OUTPUT);
  }

}

void loop() {
  for(int i = 0; i < sizeof(pins); i++){
    digitalWrite(pins[i], HIGH);
    delay(330);
  }
  for(int i = 0; i < sizeof(pins); i++){
    digitalWrite(pins[i], LOW);
    delay(330);
  }
}
