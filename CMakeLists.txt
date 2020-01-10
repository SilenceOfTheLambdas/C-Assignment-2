cmake_minimum_required(VERSION 3.10)
project(c_assignment_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(ex1)
include_directories(ex2)

add_executable(c_assignment_2
        ex1/ex1.cpp
        ex1/Person.cpp
        ex1/Person.h
        ex1/Student.cpp
        ex1/Student.h
        ex2/ReadFilteredWords.h
        ex2/ReadWords.cpp
        ex2/ReadWords.h)
