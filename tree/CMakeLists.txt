cmake_minimum_required(VERSION 3.6)
project(tree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Tree.cpp Tree.h LinkedTree.cpp LinkedTree.h Node.cpp Node.h)
add_executable(tree ${SOURCE_FILES})