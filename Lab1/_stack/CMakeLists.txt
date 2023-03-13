cmake_minimum_required(VERSION 3.21)
project(_stack)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(_stack
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        Stack.cpp
        Stack.h)
