//
// Created by else on 2023/8/27.
//

#include "Pca.h"
#include "Jacobi.h"
#include "Matrix.h"
Pca::Pca(std::vector<std::vector<double>>& mat) {
    this->Npara = mat[0].size();
    this->Ndata = mat.size();
    this->Mat.resize(Npara);
    this->Mid.resize(Npara);
    for (int i = 0; i < Npara; i++){
        this->Mat[i].resize(Ndata);
        double temp = 0;
        for (int j = 0; j < Ndata; j++){
            temp = temp + mat[j][i];
            Mat[i][j] = mat[j][i];
        }
        this->Mid[i] = temp/Ndata;
        std::cout << Mid[i] << std::endl;
    }
}

void Pca::conv(){
    std::vector<std::vector<double>> cov(Npara, std::vector<double>(Npara,0));
    for (int i = 0; i < Npara; i++){
        for (int j = 0; j < Npara; j++){
            double temp = 0;
            for (int k = 0; k < Ndata; k++){
                temp = temp + (Mat[i][k]-Mid[i]) * (Mat[j][k] - Mid[j]);
            }
            cov[i][j] = temp/Npara;
            std::cout << cov[i][j] << std::endl;
        }
    }
    Jacobi<double> jac(cov,1e-15,100);
    jac.calEigen();
    Matrix<double> eignvec(jac.eigenVec);
//    Matrix<double> eignvecT = eignvec.transport();
    Matrix<double> data(Mat);
    std::cout << data.mat.size() << data.mat[0].size() << std::endl;
    Matrix<double> res = eignvec.transport()*data;
    res.out();
//    for (int i = 0; i < res.mat.size(); i++) {
//        for (int j = 0; j < res.mat[0].size(); j++) {
//            std::cout << res.mat[i][j] << "\t";
//        }
//        std::cout << std::endl;
//    }
}
