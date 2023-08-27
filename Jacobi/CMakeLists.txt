cmake_minimum_required(VERSION 3.26)
project(Jacobi)

set(CMAKE_CXX_STANDARD 11)

add_executable(Jacobi main.cpp
        Jacobi.cpp
        Jacobi.h)
