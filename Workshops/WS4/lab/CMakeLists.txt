cmake_minimum_required(VERSION 3.16)
project(vivian)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(vivian canisterMain.cpp cstring.cpp Canister.cpp)
