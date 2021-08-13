cmake_minimum_required(VERSION 3.17)
project(DIY)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(DIY
        cstring.cpp
        cstring.h
        Stats.cpp
        Stats.h
        w6p2_tester.cpp
        numbersLtlOriginal.csv
        numbersOriginal.csv)
