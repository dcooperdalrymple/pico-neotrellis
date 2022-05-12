# pico-neotrellis
Adafruit NeoTrellis Driver for Raspberry Pi Pico C/C++ SDK.

## Installation

Make sure that [Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk) is installed correctly before following the instructions below.

### Example Compilation
Clone the library using `git clone https://github.com/dcooperdalrymple/pico-neotrellis` into a suitable location. Run the following commands to build the library example and ensure that your machine is capable of building this software.

````
cd pico-neotrellis/example
mkdir build && cd build
cmake ..
make
````

### Install Extension into Your Project
In order to add this library as an extension of your project, insert it as a submodule using `git submodule add https://github.com/dcooperdalrymple/pico-neotrellis.git` into the desired location. In the `CMakeLists.txt` file, insert `add_subdirectory(./{PATH_TO_SUBMODULE}/pico-neotrellis)` below your source files (ie: `add_executable(...)`). Then add `pico_neotrellis` to your list of _target_link_libraries_ such as `target_link_libraries(... pico_neotrellis ...)`.

## Usage
See `./example/pico-neotrellis-example.cpp` for full implementation.

### Initialization
#### Setup I2C within Instance
Speed and address parameters default to `100000` and `0x2E` and are not needed in constructor.

````
#include "neotrellis.hpp"
int main() {
    NeoTrellis trellis(i2c0, 4, 5);
    trellis.init();
    return 0;
}
````

#### Setup I2C outside of NeoTrellis
Address defaults to `0x2E` and is not needed in constructor.

````
#include "pico/stdlib.h"
#include "neotrellis.hpp"
int main() {
    i2c_init(i2c0, 100000);
    gpio_set_function(4, GPIO_FUNC_I2C);
    gpio_pull_up(4);
    gpio_set_function(5, GPIO_FUNC_I2C);
    gpio_pull_up(5);
    NeoTrellis trellis(i2c0);
    trellis.init();
    return 0;
}
````

### NeoPixels
A number of color presets are provided. See `neopixel.hpp` for reference. Make sure to call `.pixels.show()` after all of your desired pixel colors have been set to push any updates to the neopixels.

````
...
for (uint8_t i = 0; i < 16; i++) {
    trellis.pixels[i].set(i, COLOR_WHITE);
    //trellis.pixels[i].set(i, 255, 255, 255);
}
trellis.pixels.show();
...
````

### Keypad
Keypad events can be accessed manually and handled in bulk, but a simple callback is provided to handle each event in sequential order.

````
void keypad_handler(uint8_t key, Keypad::Edge edge) {
    switch (edge) {
        case Keypad::Edge::RISING:
            break;
        case Keypad::Edge::FALLING:
            break;
    }
}
...
trellis.keypad.set_callback(keypad_handler);
while (true) {
    trellis.keypad.update();
    sleep_ms(20); // Update delay is arbitrary
}
...
````

## Citations

* [Breq16/pocketdeck](https://github.com/Breq16/pocketdeck) _- Most of the NeoTrellis/Seesaw implementation, library is modified this source_
* [martinkooij/pi-pico-ss-oled](https://github.com/martinkooij/pi-pico-ss-oled) _- Used for Pico SDK library extension compilation reference_
