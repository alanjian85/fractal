cmake_minimum_required(VERSION 3.12)
project(fractal)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(FRACTAL_SOURCES
    src/main.cpp
    src/color_hsv.cpp
    src/framebuffer.cpp)

add_executable(fractal ${FRACTAL_SOURCES})
target_include_directories(fractal PRIVATE include)