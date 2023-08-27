#include <iostream>
#include <vector>
#include "Pca.h"

int main() {
//    std::vector<std::vector<double>> test{{60,165},{70,180},{55,160},{75,175},{65,170}};
    std::vector<std::vector<double>> test{{92,74},{70,87},{95,70},{73,92},{72,97},{87,74}};
    Pca pca(test);
    pca.conv();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
