#pragma once

#include <algorithm>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

class Seesaw {
    private:

        static const uint8_t HEADER_LENGTH = 2;

        i2c_inst_t * picoI2C;
        uint8_t address;

        uint8_t* add_header(uint8_t module_base, uint8_t module_function, uint8_t* data, size_t length);

    public:
        
        Seesaw(i2c_inst_t * pI2C, int sda, int scl, int32_t speed, uint8_t address);
        Seesaw(i2c_inst_t * pI2C, uint8_t address);

        void write(uint8_t module_base, uint8_t module_function, uint8_t* data, size_t length);
        void read(uint8_t module_base, uint8_t module_function, uint8_t* data, size_t length, uint16_t delay);

};
