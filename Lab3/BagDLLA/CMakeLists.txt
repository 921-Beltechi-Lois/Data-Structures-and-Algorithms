cmake_minimum_required(VERSION 3.22)
project(Lab3_BagDLLA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab3_BagDLLA
        App.cpp
        Bag.cpp
        Bag.h
        BagIterator.cpp
        BagIterator.h
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h)
