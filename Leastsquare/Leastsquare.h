//
// Created by else on 2023/8/14.
//
#include <vector>
#include "Matrix.h"
#include "GaussEpp.h"
#ifndef LEASTSQUARE_LEASTSQUARE_H
#define LEASTSQUARE_LEASTSQUARE_H

template <typename T>
class Leastsquare {
public:
    std::vector<T> x;
    std::vector<T> y;
    double xbar = 0;
    double ybar = 0;
    int n = 0;
    double a0 = 0;
    double a1 = 0;
public:
    Leastsquare(std::vector<T> xx, std::vector<T> yy);
    ~Leastsquare(){};
    void cal();
    void out();
    void polycal(size_t nn);
};

template<typename T>
Leastsquare<T>::Leastsquare(std::vector<T> xx, std::vector<T> yy) {
    this->x = xx;
    this->y = yy;
    this->n = xx.size();
}

template<typename T>
void Leastsquare<T>::cal() {
    for (int i = 0; i < n; i++){
        xbar += x[i];
        ybar += y[i];
        a1 += x[i]*y[i];
        a0 += x[i]*x[i];
    }
    xbar = xbar/n;
    ybar = ybar/n;
    a1 = (a1 - n*xbar*ybar)/(a0 - n*xbar*xbar);
    a0 = ybar - a1*xbar;
}

template<typename T>
void Leastsquare<T>::polycal(size_t m) {
    std::cout << "ok" << std::endl;
    Matrix<T> A(n,m+1);
//    Matrix<T> AT(m+1,n);
//    Matrix<T> ATA(m+1,m+1);
//    Matrix<T> ATY(m+1,1);
    Matrix<T> Y(y,n,1);
    Matrix<T> X(m+1,1);
    for (int i = 0; i < n; i++){
        A.mat[i][0] = 1;
        for (int j = 1; j < m+1; j++){
            A.mat[i][j] = pow(x[i],j);
        }
    }
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 3; j++){
            std::cout << A.mat[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << "ok1" << std::endl;
    Matrix<T> AT = A.transport();
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 7; j++){
            std::cout << AT.mat[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << A.mat.size() << std::endl;
    std::cout << AT.mat.size() << std::endl;
    Matrix<T> ATA = AT * A;
    std::cout << ATA.mat.size() << std::endl;
    for (int i = 0; i < ATA.mat.size(); i++){
        for (int j = 0; j < ATA.mat.size(); j++){
            std::cout << ATA.mat[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    Matrix<T> ATY = AT * Y;
    for (int i = 0; i < ATY.mat.size(); i++){
        std::cout << ATY.mat[i][0] << "  ";
    }
    std::cout << std::endl;
    std::cout << "ok3" << std::endl;
    std::cout << ATA.mat.size() << std::endl;
    GaussEpp<T> gau(X.mat,ATY.mat,ATA.mat);
    std::cout << "ok4" << std::endl;
    std::vector<std::vector<T>> result = gau.solve();
    for (std::vector<T>& xi:result){
        std::cout << xi[0] << " " << std::endl;
    }
}

template<typename T>
void Leastsquare<T>::out(){
    std::cout << "a0= " << a0 << "a1= " << a1 << std::endl;
}
#endif //LEASTSQUARE_LEASTSQUARE_H
