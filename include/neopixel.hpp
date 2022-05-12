#pragma once

#include "seesaw.hpp"

#define COLOR_BLACK     0x000000
#define COLOR_GRAY      0x969696
#define COLOR_WHITE     0xffffff
#define COLOR_RED       0xff0000
#define COLOR_ORANGE    0xff9600
#define COLOR_YELLOW    0xffff00
#define COLOR_GREEN     0x00ff00
#define COLOR_SEAFOAM   0x00ff96
#define COLOR_CYAN      0x00ffff
#define COLOR_BLUE      0x0000ff
#define COLOR_PURPLE    0xb400ff
#define COLOR_PINK      0xff00ff

class NeoPixel {
    private:

        static const int MODULE_BASE = 0x0E;

        enum Functions {
            PIN = 0x01,
            SPEED = 0x02,
            BUF_LENGTH = 0x03,
            BUF = 0x04,
            SHOW = 0x05
        };

        uint8_t pin;
        uint16_t strand_length;

        Seesaw& seesaw;

    public:
        
        NeoPixel(Seesaw& seesaw, uint8_t pin, uint16_t strand_length);

        void init();
        void set(uint16_t number, uint8_t r, uint8_t g, uint8_t b);
        void set(uint16_t number, uint32_t rgb);
        void show();

};
