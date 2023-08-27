#include <iostream>
#include <vector>
#include "Jacobi.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
//    return 0;
    std::vector<std::vector<double>> a{{2,-1,0},{-1,2,-1},{0,-1,2}};
    double eps = 1e-15;
    int maxN = 100;
    Jacobi aaa(a, eps, maxN);
//    std::cout << "ok1" << std::endl;
    aaa.calEigen();
}
