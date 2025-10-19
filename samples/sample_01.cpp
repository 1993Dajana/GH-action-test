#include <iostream>
#include <vector>
#include <unordered_set>
#include <random>
#include <chrono>

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

int main() {
    run_test(200'000, 42);
    return 0;
}
