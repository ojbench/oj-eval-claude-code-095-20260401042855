#include <iostream>
#include "src.hpp"

int main() {
    Permutation p1(4);
    p1.mapping[0] = 2;
    p1.mapping[1] = 3;
    p1.mapping[2] = 1;
    p1.mapping[3] = 0;
    
    Permutation p2 = p1;  // Copy constructor
    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;
    
    Permutation p3(5);
    p3 = p1;  // Copy assignment
    std::cout << "p3: " << p3 << std::endl;
    
    return 0;
}
