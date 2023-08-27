cmake_minimum_required(VERSION 3.26)
project(Leastsquare)

set(CMAKE_CXX_STANDARD 11)

add_executable(Leastsquare main.cpp
        Leastsquare.cpp
        Leastsquare.h
        Matrix.cpp
        Matrix.h
        GaussEpp.cpp
        GaussEpp.h)
