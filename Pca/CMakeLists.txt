cmake_minimum_required(VERSION 3.26)
project(pca)

set(CMAKE_CXX_STANDARD 11)

add_executable(pca main.cpp
        Pca.cpp
        Pca.h
        Jacobi.h
        Matrix.h)
