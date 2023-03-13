cmake_minimum_required(VERSION 3.22)
project(LinkedListEx)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(LinkedListEx
        List.cpp
        List.h
        main.cpp)
