cmake_minimum_required(VERSION 3.17)
project(MS4)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(MS4
        CovidPatient.cpp
        CovidPatient.h
        IOAble.cpp
        IOAble.h
        Menu.cpp
        Menu.h
        Patient.cpp
        Patient.h
        Ticket.cpp
        Ticket.h
        Time.cpp
        Time.h
        TPTester.cpp
        TriagePatient.cpp
        TriagePatient.h
        utils.cpp
        utils.h)
