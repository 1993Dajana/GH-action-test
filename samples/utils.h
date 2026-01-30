#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <cmath>

inline void compute_primes(size_t limit) {
    std::cout << "Computing primes up to " << limit << "...\n";
    
    size_t count = 0;
    for (size_t num = 2; num <= limit; ++num) {
        bool is_prime = true;
        for (size_t i = 2; i <= static_cast<size_t>(std::sqrt(num)); ++i) {
            if (num % i == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            ++count;
        }
    }
    
    std::cout << "Found " << count << " primes up to " << limit << "\n";
}

#endif // UTILS_HPP
