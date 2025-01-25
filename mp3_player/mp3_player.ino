#include "async_mp3.h"

AsyncMP3Player mp3Player;

void setup() {
    Serial.begin(115200);
    if (!mp3Player.begin("/sdcard/song.mp3")) {
        Serial.println("Failed to open MP3 file!");
        return;
    }

    mp3Player.play();
}

void loop() {
    // Main loop remains free for other tasks
    delay(1000);
}
