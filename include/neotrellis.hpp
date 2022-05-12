#pragma once

#include "hardware/i2c.h"

#include "seesaw.hpp"
#include "neopixel.hpp"
#include "keypad.hpp"

class NeoTrellis {
    private:

        static const int32_t NEOTRELLIS_DEFAULT_SPEED = 100 * 1000;
        static const uint8_t NEOTRELLIS_DEFAULT_ADDR = 0x2E;
        static const uint8_t NEOPIXEL_PIN = 3;
        static const uint8_t NEOPIXEL_LENGTH = 16;

        Seesaw seesaw;

    public:

        NeoTrellis(i2c_inst_t * pI2C, int sda, int scl, int32_t speed, uint8_t address);
        NeoTrellis(i2c_inst_t * pI2C, int sda, int scl, int32_t speed);
        NeoTrellis(i2c_inst_t * pI2C, int sda, int scl);
        NeoTrellis(i2c_inst_t * pI2C, uint8_t address);
        NeoTrellis(i2c_inst_t * pI2C);

        void init();

        NeoPixel pixels;
        Keypad keypad;

};
