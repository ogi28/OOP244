cmake_minimum_required(VERSION 3.17)
project(lab)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(lab
        cstring.cpp
        cstring.h
        TextFile.cpp
        TextFile.h
        w6p1_tester.cpp)
