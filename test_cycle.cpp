#include <iostream>
#include "src.hpp"

int main() {
    // Test cycle {2, 3, 1} on array (3, 1, 2, 0)
    int arr[] = {3, 1, 2, 0};
    int elem[] = {2, 3, 1};
    Cycle c(elem, 3);
    
    std::cout << "Before: ";
    for (int i = 0; i < 4; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
    
    c.apply(arr, 4);
    
    std::cout << "After:  ";
    for (int i = 0; i < 4; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
    
    std::cout << "Expected: 3 2 0 1" << std::endl;
    
    return 0;
}
