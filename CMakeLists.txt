cmake_minimum_required(VERSION 3.10)
project(c_assignment_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(ex1)
include_directories(ex2)

add_executable(c_assignment_2
        ex2/ReadFilteredWords.h
        ex2/ReadFilteredWords.cpp
        ex2/ReadWords.cpp
        ex2/ReadWords.h
        ex2/filter1.cpp
        ex2/filter1.h
        ex2/filter2.cpp
        ex2/filter2.h
        ex2/filter3.cpp
        ex2/filter3.h
        ex2/ex2.cpp
        )
