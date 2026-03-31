#include <iostream>
#include "src.hpp"

void test_permutation_multiplication() {
    std::cout << "Testing permutation multiplication..." << std::endl;
    // Test: (p * q)[i] = p[q[i]] - first apply q, then apply p
    Permutation p(4);
    p.mapping[0] = 1; p.mapping[1] = 0; p.mapping[2] = 3; p.mapping[3] = 2;
    
    Permutation q(4);
    q.mapping[0] = 2; q.mapping[1] = 3; q.mapping[2] = 0; q.mapping[3] = 1;
    
    Permutation result = p * q;
    std::cout << "p = " << p << std::endl;
    std::cout << "q = " << q << std::endl;
    std::cout << "p * q = " << result << std::endl;
    
    // Verify: result[i] = p[q[i]]
    for (int i = 0; i < 4; i++) {
        int expected = p.mapping[q.mapping[i]];
        std::cout << "result[" << i << "] = " << result.mapping[i] 
                  << ", expected = " << expected 
                  << (result.mapping[i] == expected ? " ✓" : " ✗") << std::endl;
    }
}

void test_cycle_size_1() {
    std::cout << "\nTesting cycle with size 1..." << std::endl;
    int arr[] = {0, 1, 2, 3};
    int elem[] = {2};
    Cycle c(elem, 1);
    c.apply(arr, 4);
    std::cout << "After applying {2} to (0,1,2,3): ";
    for (int i = 0; i < 4; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void test_empty_cycle() {
    std::cout << "\nTesting empty cycle..." << std::endl;
    int arr[] = {0, 1, 2, 3};
    int elem[] = {};
    Cycle c(elem, 0);
    c.apply(arr, 4);
    std::cout << "After applying {} to (0,1,2,3): ";
    for (int i = 0; i < 4; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    test_permutation_multiplication();
    test_cycle_size_1();
    test_empty_cycle();
    return 0;
}
