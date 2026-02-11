#include <iostream>
#include <vector>
#include <unordered_set>
#include <random>
#include <chrono>
#include "utils.h"

std::vector<int> generate_ids(size_t N, unsigned seed) {
  std::mt19937 rng(seed);
  std::uniform_int_distribution<int> dist(100000, 300000);
  std::vector<int> ids(N);
  for (size_t i = 0; i < N; ++i) {
    ids[i] = dist(rng);
  }
  return ids;
}

size_t count_unique(const std::vector<int>& ids) {
    std::unordered_set<int> seen;  // Use unordered_set to track unique IDs
    for (int id : ids) {
        seen.insert(id);  // Insertion will ignore duplicates
    }
    return seen.size();  // The number of unique IDs is the size of the set
}

void run_test(size_t N, unsigned seed) {
    auto ids = generate_ids(N, seed);
    size_t unique = count_unique(ids);
    std::cout << "Unique: " << unique << "\n";
}

void greet() {
    std::cout << "Hello from greet function!\n";
    
    // Do some actual work to prevent optimization
    const size_t iterations = 1000000;
    volatile double result = 0.0;
    
    for (size_t i = 1; i <= iterations; ++i) {
        result += 1.0 / static_cast<double>(i);
        result *= 1.0000001;
        result -= 0.0000001 * i;
    }
    
    std::cout << "Computation result: " << result << "\n";
}

void bubble_sort(std::vector<int>& arr) {
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
    std::cout << "Array sorted with " << n << " elements\n";
}

int calculate_factorial(int n) {
    if (n <= 1) return 1;
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    std::cout << "Factorial of " << n << " is " << result << "\n";
    return result;
}

int main() {
    greet();
    calculate_factorial(10);
    compute_primes(50000);
    run_test(200'000, 42);
    return 0;
}
