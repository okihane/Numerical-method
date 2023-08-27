//
// Created by else on 2023/8/27.
//
#include <iostream>
#include <vector>
#ifndef PCA_PCA_H
#define PCA_PCA_H


class Pca {
public:
    size_t Npara = 0;
    size_t Ndata = 0;
    std::vector<std::vector<double>> Mat;
    std::vector<double> Mid;
public:
//    Pca(){};
    Pca(std::vector<std::vector<double>>& mat);
    ~Pca(){};
    void conv();
};

#endif //PCA_PCA_H
