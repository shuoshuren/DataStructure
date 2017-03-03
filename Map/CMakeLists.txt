cmake_minimum_required(VERSION 3.6)
project(Map)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Node.cpp Node.h CMap.cpp CMap.h Edge.cpp Edge.h)
add_executable(Map ${SOURCE_FILES})