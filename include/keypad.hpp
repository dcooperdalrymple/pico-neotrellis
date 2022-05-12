#pragma once

#include "seesaw.hpp"

enum KeyEdge {
    HIGH = 0,
    LOW,
    FALLING,
    RISING
};

typedef void(* keypad_callback_t) (uint8_t key, KeyEdge edge);

class Keypad {
    private:

        static const int MODULE_BASE = 0x10;

        enum Functions {
            STATUS = 0x00,
            EVENT = 0x01,
            INTENSET = 0x02,
            INTENCLR = 0x03,
            COUNT = 0x04,
            FIFO = 0x10
        };

        Seesaw& seesaw;

        keypad_callback_t cb = NULL;

        constexpr uint8_t key_trellis_to_seesaw(uint8_t key) {
            return (key % 4) + (key / 4) * 8;
        };
        constexpr uint8_t key_seesaw_to_trellis(uint8_t key) {
            return (key % 8) + (key / 8) * 4;
        };

    public:

        Keypad(Seesaw& seesaw);

        void init();
        void update();

        uint8_t* events(uint8_t& count);

        void set_callback(keypad_callback_t callback);
        void clear_callback(void);
        
};
