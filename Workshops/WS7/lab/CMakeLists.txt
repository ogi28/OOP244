cmake_minimum_required(VERSION 3.17)
project(lab)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(lab
        cstring.cpp
        cstring.h
        main.cpp
        MotorVehicle.cpp
        MotorVehicle.h
        Truck.cpp
        Truck.h)
