#include "neotrellis.hpp"

NeoTrellis::NeoTrellis(i2c_inst_t * pI2C, int sda, int scl, int32_t speed, uint8_t address) :
    seesaw(pI2C, sda, scl, speed, address),
    pixels(seesaw, NEOPIXEL_PIN, NEOPIXEL_LENGTH), keypad(seesaw) {

};
NeoTrellis::NeoTrellis(i2c_inst_t * pI2C, int sda, int scl, int32_t speed) :
    seesaw(pI2C, sda, scl, speed, NEOTRELLIS_DEFAULT_ADDR),
    pixels(seesaw, NEOPIXEL_PIN, NEOPIXEL_LENGTH), keypad(seesaw) {

};
NeoTrellis::NeoTrellis(i2c_inst_t * pI2C, int sda, int scl) :
    seesaw(pI2C, sda, scl, NEOTRELLIS_DEFAULT_SPEED, NEOTRELLIS_DEFAULT_ADDR),
    pixels(seesaw, NEOPIXEL_PIN, NEOPIXEL_LENGTH), keypad(seesaw) {

};
NeoTrellis::NeoTrellis(i2c_inst_t * pI2C, uint8_t address) :
    seesaw(pI2C, address),
    pixels(seesaw, NEOPIXEL_PIN, NEOPIXEL_LENGTH), keypad(seesaw) {

};
NeoTrellis::NeoTrellis(i2c_inst_t * pI2C) :
    seesaw(pI2C, NEOTRELLIS_DEFAULT_ADDR),
    pixels(seesaw, NEOPIXEL_PIN, NEOPIXEL_LENGTH), keypad(seesaw) {

};

void NeoTrellis::init() {
    pixels.init();
    keypad.init();
}
