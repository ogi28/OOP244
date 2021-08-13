cmake_minimum_required(VERSION 3.17)
project(DIY)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(DIY
        Mark.cpp
        Mark.h
        markMain.cpp)
