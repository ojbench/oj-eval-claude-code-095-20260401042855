#include <iostream>
#include "src.hpp"

int main() {
    // Test many operations to see if there's a memory leak
    for (int iter = 0; iter < 1000; iter++) {
        Permutation p(100);
        for (int i = 0; i < 100; i++) {
            p.mapping[i] = (i + 50) % 100;
        }
        
        Permutation q = p;
        Permutation r = p * q;
        Permutation s = r.inverse();
        
        int arr[100];
        for (int i = 0; i < 100; i++) arr[i] = i;
        p.apply(arr);
        
        Cycle c(arr, 50);
        c.apply(arr, 100);
        
        Permutation t = c.toPermutation(100);
    }
    std::cout << "Memory test completed" << std::endl;
    return 0;
}
