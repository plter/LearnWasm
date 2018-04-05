cmake_minimum_required(VERSION 3.10)
project(Lambda)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        /Work/gitroot/github/juj/emsdk/emscripten/1.37.34/system/include
)

add_executable(HelloWasm main.cpp)