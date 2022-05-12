cmake_minimum_required(VERSION 3.13)

set(NAME pico_neotrellis)
set(URL "https://github.com/dcooperdalrymple/pico-neotrellis")

add_library(${NAME} INTERFACE)

target_sources(${NAME} INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/src/seesaw.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/keypad.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/neopixel.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/neotrellis.cpp
)

target_include_directories(${NAME} INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)

# Pull in pico libraries that we need
target_link_libraries(${NAME} INTERFACE pico_stdlib hardware_i2c)
