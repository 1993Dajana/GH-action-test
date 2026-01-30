#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <chrono>
#include <unordered_set>

std::vector<int> generate_ids(size_t N, unsigned seed) {
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dist(100000, 300000);
    std::vector<int> ids;
    ids.resize(N);
    for (size_t i = 0; i < N; ++i) {
        ids[i] = dist(rng);
    }
    return ids;
}

// Count unique values. Fast path: if the value range is small compared
// to the number of elements, use a dense bitmap for O(n) time and
// very low overhead. Otherwise fall back to unordered_set.
size_t count_unique(const std::vector<int>& ids) {
    if (ids.empty()) return 0;

    // find min/max in one pass
    auto mm = std::minmax_element(ids.begin(), ids.end());
    int minv = *mm.first;
    int maxv = *mm.second;

    // compute range and choose strategy
    long long range = static_cast<long long>(maxv) - static_cast<long long>(minv) + 1;

    // If the value range is reasonably small compared to number of ids,
    // use a dense byte bitmap. The multiplier (8) is a heuristic: if the
    // range is <= 8 * n, the bitmap will be memory- and time-efficient.
    if (range > 0 && range <= static_cast<long long>(ids.size()) * 8 && range <= 10'000'000) {
        std::vector<unsigned char> seen(static_cast<size_t>(range));
        size_t unique = 0;
        for (int id : ids) {
            size_t idx = static_cast<size_t>(id - minv);
            if (!seen[idx]) { seen[idx] = 1; ++unique; }
        }
        return unique;
    }

    // Fallback: unordered_set (reserve to avoid rehashing)
    std::unordered_set<int> seen;
    seen.reserve(ids.size());          // reduces rehashing
    for (int id : ids) seen.insert(id);
    return seen.size();
}

void run_test(size_t N, unsigned seed) {
    const auto t0 = std::chrono::high_resolution_clock::now();

    auto ids = generate_ids(N, seed);
    size_t unique = count_unique(ids);

    const auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Unique: " << unique
              << "  (elapsed " 
              << std::chrono::duration<double, std::milli>(t1 - t0).count()
              << " ms)\n";
    for (int i = 0; i < 10 && i < ids.size(); ++i) {
        std::cout << ids[i] << " ";
    }
    std::cout << "\n";
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

int main() {
    greet();
    run_test(200'000, 42);
    return 0;
}
