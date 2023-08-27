#include <iostream>
#include <vector>
#include "SVD.h"

int main() {
    std::vector<std::vector<double>> a = { {4,0,5},{0,0,5} };
    double eps = 1e-15;
    size_t maxn = 100;
    SVD<double> svd(a,eps,maxn);
    svd.cal();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
