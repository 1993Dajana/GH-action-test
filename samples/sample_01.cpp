#include <iostream>
#include <vector>
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

size_t count_unique(const std::vector<int>& ids) {
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

int main() {
    run_test(200'000, 42);
    return 0;
}
