#include "seesaw.hpp"

Seesaw::Seesaw(i2c_inst_t * pI2C, int sda, int scl, int32_t speed, uint8_t address) :
    picoI2C(pI2C),
    address(address) {
    // Setup I2C
    i2c_init(picoI2C, speed);
    gpio_set_function(sda, GPIO_FUNC_I2C);
    gpio_pull_up(sda);
    gpio_set_function(scl, GPIO_FUNC_I2C);
    gpio_pull_up(scl);
};
Seesaw::Seesaw(i2c_inst_t * pI2C, uint8_t address) :
    picoI2C(pI2C),
    address(address) {
    // Do nothing
}

uint8_t* Seesaw::add_header(uint8_t module_base, uint8_t module_function, uint8_t* data, size_t length) {
    size_t buflen = length + HEADER_LENGTH;
    uint8_t* buffer = new uint8_t[buflen];

    buffer[0] = module_base;
    buffer[1] = module_function;

    std::copy(data, data + length, buffer + HEADER_LENGTH);

    return buffer;
}

void Seesaw::write(uint8_t module_base, uint8_t module_function, uint8_t* data, size_t length) {
    uint8_t* buffer = add_header(module_base, module_function, data, length);

    i2c_write_blocking(
        picoI2C,
        address,
        buffer,
        length + HEADER_LENGTH,
        false
    );

    delete[] buffer;
}

void Seesaw::read(uint8_t module_base, uint8_t module_function, uint8_t* data, size_t length, uint16_t delay) {
    uint8_t header[] = {module_base, module_function};

    i2c_write_blocking(
        picoI2C,
        address,
        header,
        2,
        false
    );

    sleep_us(delay);

    i2c_read_blocking(
        picoI2C,
        address,
        data,
        length,
        false
    );
}
