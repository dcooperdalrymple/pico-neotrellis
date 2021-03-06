cmake_minimum_required(VERSION 3.13)

set(NAME pico-neotrellis-example)
set(URL "https://github.com/dcooperdalrymple/pico-neotrellis/main/example")

# initialize pico-sdk from GIT
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_FETCH_FROM_GIT on)

# pico_sdk_import.cmake is a single file copied from this SDK
# note: this must happen before project()
include(pico_sdk_import.cmake)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

project(${NAME} C CXX ASM)

# Add executable. Default name is the project name,
add_executable(${NAME} pico-neotrellis-example.cpp)
add_subdirectory(../ build)

pico_add_extra_outputs(${NAME})
target_link_libraries(${NAME} pico_stdlib pico_neotrellis)

pico_set_program_url(${NAME} ${URL})
