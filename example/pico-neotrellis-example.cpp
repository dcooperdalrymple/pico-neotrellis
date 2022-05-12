#include "pico/stdlib.h"
#include "neotrellis.hpp"

#define PICO_I2C i2c0
#define PICO_SDA 4
#define PICO_SCL 5

static NeoTrellis trellis(PICO_I2C, PICO_SDA, PICO_SCL);
void keypad_handler(uint8_t key, Keypad::Edge edge);

int main() {
    stdio_init_all();

    sleep_ms(3000);

    trellis.init();

    // Test NeoPixels
    for (uint8_t i = 0; i < 16; i++) {
        trellis.pixels.set(i, COLOR_WHITE);
        trellis.pixels.show();
        sleep_ms(50);
    }
    for (uint8_t i = 0; i < 16; i++) {
        trellis.pixels.set(i, COLOR_BLACK);
        trellis.pixels.show();
        sleep_ms(50);
    }

    // Test Keypad
    trellis.keypad.set_callback(keypad_handler);
    while (true) {
        trellis.keypad.update();
        trellis.pixels.show();
        sleep_ms(20);
    }

    return 0;
}

void keypad_handler(uint8_t key, Keypad::Edge edge) {
    if (edge == Keypad::Edge::RISING) {
        trellis.pixels.set(key, COLOR_WHITE);
    } else {
        trellis.pixels.set(key, COLOR_BLACK);
    }
}
