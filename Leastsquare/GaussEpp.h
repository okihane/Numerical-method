//
// Created by else on 2023/8/15.
//

#ifndef LEASTSQUARE_GAUSSEPP_H
#define LEASTSQUARE_GAUSSEPP_H

#include <vector>
#include <iostream>
#include <cmath>
template <typename T>
class GaussEpp {
public:
    size_t n = 0;
    std::vector<std::vector<T>> X;
    std::vector<std::vector<T>> Y;
    std::vector<std::vector<T>> aa;
public:
    GaussEpp(std::vector<std::vector<T>>& x,std::vector<std::vector<T>>& y,std::vector<std::vector<T>>& m_a){
        this->n = x.size();
        this->X = x;
        this->Y = y;
        this->aa = m_a;
    }
    std::vector<std::vector<T>> solve(){
        n = aa.size();
        for (int i = 0; i < n-1; i++){
            double maxe = aa[i][i];
            int maxrow  = i;
            //std::cout << "ok5" << std::endl;
            for (int j = i; j < n; j++){
                //std::cout << "ok5" << std::endl;
                if (fabs(aa[j][i]) > maxe){
                    maxe = fabs(aa[j][i]);
                    maxrow = j;
                }
            }
            //交换
            if (maxrow != i){
                std::vector<T> tmp(n,0);
                T tmp1;
                for (int k = 0; k < n; k++){
                    tmp[k] = aa[i][k];
                    aa[i][k] = aa[maxrow][k];
                    aa[maxrow][k] = tmp[k];
                    tmp1 = Y[i][0];
                    Y[i][0] = Y[maxrow][0];
                    Y[maxrow][0] = tmp1;
                }
            }
            for (int ii = 0; ii < 3; ii ++){
                for (int jj =0; jj < 3; jj ++){
                    std::cout << aa[ii][jj] << "  ";
                }
                std::cout << std::endl;
            }
            //消去
            T km;
            for (int l = i+1; l < n; l++){
                km = aa[l][i]/aa[i][i];
                for (int m = 0; m < n; m++){
                    aa[l][m] -= km*aa[i][m];
                }
                Y[l][0] -= km*Y[i][0];
            }
        }
        for (int ii = 0; ii < 3; ii ++){
            for (int jj =0; jj < 3; jj ++){
                std::cout << aa[ii][jj] << "  ";
            }
            std::cout << std::endl;
        }
        std::cout << "ok5" << std::endl;
        //求解
        T sum = 0;
        for (int mn = n-1; mn >= 0; mn--){
            for (int mnn = mn+1; mnn < n; mnn++){
                sum += aa[mn][mnn]*X[mnn][0];
            }
            X[mn][0] = (Y[mn][0] - sum)/aa[mn][mn];
        }
        return X;
    }
};


#endif //LEASTSQUARE_GAUSSEPP_H
