#include "MiniMP3.h"
#include <driver/i2s.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

class AsyncMP3Player {
private:
    mp3dec_ex_t mp3Decoder;
    uint8_t* audioBuffer;
    size_t bufferSize;
    bool isPlaying;
    TaskHandle_t playbackTaskHandle;

    static void playbackTask(void* arg) {
        AsyncMP3Player* player = static_cast<AsyncMP3Player*>(arg);

        while (player->isPlaying) {
            int samplesDecoded = mp3dec_ex_read(&player->mp3Decoder, player->audioBuffer, player->bufferSize);
            if (samplesDecoded <= 0) {
                player->stop();
                break;
            }

            // Output audio data via I2S
            size_t bytesWritten = 0;
            i2s_write(I2S_NUM_0, player->audioBuffer, samplesDecoded, &bytesWritten, portMAX_DELAY);
        }

        vTaskDelete(NULL);
    }

public:
    AsyncMP3Player(size_t bufferSize = 2048)
        : bufferSize(bufferSize), isPlaying(false), playbackTaskHandle(nullptr) {
        audioBuffer = (uint8_t*)malloc(bufferSize);
    }

    ~AsyncMP3Player() {
        free(audioBuffer);
        mp3dec_ex_close(&mp3Decoder);
    }

    bool begin(const char* filename) {
        if (mp3dec_ex_open(&mp3Decoder, filename, MP3D_SEEK_TO_SAMPLE) != 0) {
            return false;
        }

        // Initialize I2S for audio output
        i2s_config_t i2sConfig = {
            .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
            .sample_rate = 44100,
            .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
            .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
            .communication_format = I2S_COMM_FORMAT_I2S,
            .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
            .dma_buf_count = 8,
            .dma_buf_len = 512,
            .use_apll = false,
        };
        i2s_driver_install(I2S_NUM_0, &i2sConfig, 0, NULL);

        i2s_pin_config_t pinConfig = {
            .bck_io_num = 26,
            .ws_io_num = 25,
            .data_out_num = 22,
            .data_in_num = I2S_PIN_NO_CHANGE,
        };
        i2s_set_pin(I2S_NUM_0, &pinConfig);

        return true;
    }

    void play() {
        if (isPlaying) return;
        isPlaying = true;
        xTaskCreate(playbackTask, "MP3 Playback", 4096, this, 1, &playbackTaskHandle);
    }

    void pause() {
        isPlaying = false;
        if (playbackTaskHandle) {
            vTaskDelete(playbackTaskHandle);
            playbackTaskHandle = nullptr;
        }
    }

    void stop() {
        pause();
        mp3dec_ex_seek(&mp3Decoder, 0);
    }
};
