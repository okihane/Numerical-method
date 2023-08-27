//
// Created by else on 2023/8/14.
//
#include <iostream>
#include <vector>
#ifndef LEASTSQUARE_MATRIX_H
#define LEASTSQUARE_MATRIX_H

template <typename T>
class Matrix {
public:
    size_t rows = 0;
    size_t cols = 0;
    std::vector<std::vector<T>> mat;
public:
    Matrix(size_t rows, size_t cols) {
        this->rows = rows;
        this->cols = cols;
        this->mat.resize(rows);
        for (int i = 0; i < rows; i++) {
            mat[i].resize(cols);
            for (int j = 0; j < cols; j++) {
                mat[i][j] = 0;
            }
        }
    };

    Matrix(std::vector<std::vector<T>> &m_mat) {
        this->rows = m_mat.size();
        this->cols = m_mat[0].size();
        this->mat = m_mat;
    };

    Matrix(std::vector<T> &m_mat) {
        this->rows = m_mat.size();
        this->cols = m_mat[0].size();
        this->mat.resize(rows, std::vector<T>(1, 0));
        for (int i = 0; i < rows; i++) {
            this->mat[i][0] = m_mat[i];
        }
    };

    Matrix() {};

    ~Matrix() {};

    Matrix operator*(Matrix tmp) {
        Matrix<T> m_x(rows, tmp.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < tmp.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    m_x.mat[i][j] += this->mat[i][k] * tmp.mat[k][j];
                }
            }
        }
        return m_x;
    };

    Matrix<T> transport() {
        Matrix<T> At(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                At.mat[j][i] = mat[i][j];
            }
        }
        return At;
    };

    void out() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << mat[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    };
};

#endif //LEASTSQUARE_MATRIX_H
