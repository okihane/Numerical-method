//
// Created by else on 2023/8/13.
//
#include <iostream>
#include <valarray>
#include "Jacobi.h"
//构造函数
template <typename T>
Jacobi<T>::Jacobi(const std::vector<std::vector<T>>& rhs, T eps, int maxN){
    this->a = rhs;
    this->Eps = eps;
    this->MaxNum = maxN;
    this->nDim = rhs.size();
    this->eigenVec.resize(nDim);
    for (int i=0;i<nDim;i++){
        eigenVec[i].resize(nDim,0.0);
        eigenVec[i][i] = 1.0;
    }
}

//计算特征值
template <typename T>
void Jacobi<T>::calEigen(){
    //检查是否为对称矩阵
    for (int i = 0; i < nDim; i++){
        for (int j = 0; j < nDim; j++){
            if (a[i][j] != a[j][i]){
                std::cout << "not sys" << std::endl;
                exit(1);
            }
        }
    }
    //开始迭代计算
    int index = 0;
    double maxE = fabs(a[0][1]);
    int row, col;
//    std::cout << "ok2" << std::endl;
    while (index < MaxNum){
        max_E(row, col, maxE);
        if (maxE < Eps) break;
//        std::cout << row << col << std::endl;
        Givens(row, col);
        index++;
    }
    std::cout << "iterate num" << index << std::endl;
    output();
}

template <typename T>
void Jacobi<T>::max_E(int& row, int& col, T& maxE) {
    maxE = fabs(a[0][1]);
    row = 0;
    col = 1;
    for (int i = 0; i < nDim; i++){
        for (int j = 0; j < nDim; j++){
            if ((fabs(a[i][j])>maxE) && (i != j)){
                maxE = fabs(a[i][j]);
                row = i;
                col = j;
            }
        }
    }
//    std::cout << "ok3" << std::endl;
}

template <typename T>
void Jacobi<T>::Givens(int p, int q) {
    //计算旋转角度；
    double theta, sn, cs, sn2th, cs2th;
    if (a[p][p] - a[q][q] < 1e-20){
//        std::cout << "ok4" << std::endl;
        if (a[p][q] < 0){
            sn = -1/sqrt(2);
            cs = 1/sqrt(2);
            sn2th = -1;
            cs2th = 0;
        }
        else {
            sn = 1/sqrt(2);
            cs = 1/sqrt(2);
            sn2th = 1;
            cs2th = 0;
        }
    }
    else{
//        std::cout << "ok4" << std::endl;
        theta = 0.5*atan2(2*a[p][q],(a[p][p]-a[q][q]));
        sn = sin(theta);
        cs = cos(theta);
        sn2th = sin(2*theta);
        cs2th = cos(2*theta);
    }
//    std::cout << "ok4" << std::endl;
    //计算A矩阵各元素
    double app = a[p][p];
    double aqq = a[q][q];
    double apq = a[p][q];

    a[p][p] = app * cs * cs + aqq * sn * sn + apq * sn2th;
    a[q][q] = app * sn *sn + aqq * cs *cs - apq * sn2th;
    a[p][q] = 0.5 * (aqq - app) * sn2th + apq * cs2th;
    a[q][p] = a[p][q];

    for (int i=0; i<nDim; i++){
        if ((i != p) && (i != q)){
            double api = a[p][i];
            double aqi = a[q][i];

            a[p][i] = cs * api + sn * aqi;
            a[q][i] = cs * aqi - sn * api;
            a[i][p] = a[p][i];
            a[i][q] = a[q][i];
        }
    }

    //计算特征向量
    for (int k = 0; k < nDim; k++){
        double Ekp = eigenVec[k][p];
        double Ekq = eigenVec[k][q];
        eigenVec[k][p] = Ekp * cs + Ekq * sn;
        eigenVec[k][q] = Ekq * cs - Ekp * sn;
    }
}

template <typename T>
void Jacobi<T>::output(){
    for (int i = 0; i< nDim; i++){
        std::cout << "eigen value= ";
        std::cout << a[i][i] << std::endl;
        for (int j = 0; j < nDim; j++){
            std::cout << eigenVec[j][i] << "\t";
        }
        std::cout << std::endl;
    }
}