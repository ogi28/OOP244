cmake_minimum_required(VERSION 3.17)
project(DIY_lab4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(DIY_lab4
        cstring.cpp
        cstring.h
        Label.cpp
        Label.h
        LabelMaker.cpp
        LabelMaker.h
        w4_tester.cpp)
