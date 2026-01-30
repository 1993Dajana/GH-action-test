#include <iostream>
#include <vector>
#include <unordered_set>
#include <random>
#include <chrono>
#include <string>
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

// Unused utility functions

long long factorial(int n) {
    if (n <= 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int fibonacci(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1;
    for (int i = 2; i <= n; ++i) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

double compute_average(const std::vector<int>& values) {
    if (values.empty()) return 0.0;
    long long sum = 0;
    for (int v : values) {
        sum += v;
    }
    return static_cast<double>(sum) / values.size();
}

bool is_palindrome(const std::string& str) {
    size_t left = 0;
    size_t right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right]) return false;
        ++left;
        --right;
    }
    return true;
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

void test_feature_2() {
    std::cout << "Testing feature-2 branch PR\n";
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

int main() {
    greet();
    compute_primes(50000);
    run_test(200'000, 42);
    test_feature_2();
    return 0;
}
