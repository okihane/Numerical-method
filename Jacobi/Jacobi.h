//
// Created by else on 2023/8/13.
//
#pragma once
#include <vector>
#ifndef JACOBI_JACOBI_H
#define JACOBI_JACOBI_H

template <typename T>
class Jacobi {
public:
    T Eps;
    int MaxNum;
    int nDim;
    std::vector<std::vector<T>> a;
    std::vector<std::vector<T>> eigenVec;
public:
    Jacobi(){};
    ~Jacobi(){};
    Jacobi(const std::vector<std::vector<T>>& rhs, T eps, int maxN);
    void calEigen();
    void max_E(int& row, int& col, T& maxE);
    void Givens(int p, int q);
    void output();
};


#endif //JACOBI_JACOBI_H
