cmake_minimum_required(VERSION 3.21)
project(Lab5_dsa)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab5_dsa
        ExtendedTest.cpp
        ExtendedTest.h
        main.cpp
        ShortTest.cpp
        ShortTest.h
        SortedBag.cpp
        SortedBag.h
        SortedBagIterator.cpp
        SortedBagIterator.h)
