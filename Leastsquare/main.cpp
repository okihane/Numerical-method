#include <iostream>
#include <vector>
#include "Leastsquare.h"
int main() {
//    std::vector<double> vx{1.0,2.0,2.0,3.0,4.0};
//    std::vector<double> vy{1.0,3.0,1.0,4.0,2.0};
//    Leastsquare<double> le(vx,vy);
//    le.cal();
//    le.out();
    std::vector<double> vx{-3,-2,-1,0,1,2,3};
    std::vector<double> vy{4,2,3,0,-1,-2,-5};
    Leastsquare<double> le(vx,vy);
    le.polycal(2);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
