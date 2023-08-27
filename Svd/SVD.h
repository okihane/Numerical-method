#pragma once
#include "Matrix.h"
#include "Jacobi.h"
template <typename T>
class SVD
{
public:
    T Eps;
    size_t m = 0;
    size_t n = 0;
    size_t maxN;
    Matrix<T> A;
public:
    SVD(){};
    SVD(std::vector<std::vector<T>>& a, T eps, size_t maxn);
    ~SVD() {};
    void cal();
};

template <typename T>
SVD<T>::SVD(std::vector<std::vector<T>>& a, T eps, size_t maxn) {
    this->m = a.size();
    this->n = a[0].size();
    this->A = Matrix<T>(a);
    this->Eps = eps;
    this->maxN = maxn;
}

template <typename T>
void SVD<T>::cal() {
    Matrix<T> AT = A.transport();
    Matrix<T> ATA = AT * A;
    Jacobi ja(ATA.mat,Eps,maxN);
    ja.calEigen();
    Matrix<T> V(ja.eigenVec);
    V.out();
    Matrix<T> AAT = A * AT;
    Jacobi ja2(AAT.mat,Eps,maxN);
    ja2.calEigen();
    Matrix<T> U(ja2.eigenVec);
    U.out();
    //定义sigma
    Matrix<T> sigma(m,n);
    size_t rank = m;
    if (rank > n) rank = n;
    for (int i=0; i < rank; i++){
        sigma.mat[i][i] = ja2.a[i][i];
    }
    sigma.out();
}