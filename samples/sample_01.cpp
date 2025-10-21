#include <iostream>
#include <vector>
#include <unordered_set>
#include <random>
#include <chrono>

std::vector<int> generate_ids(size_t N, unsigned seed) {
  // allow a small transformation of the user-provided seed
  auto adjust_seed = [](unsigned s) {
    // mix bits to avoid trivial low-entropy seeds when simple values are used
    return s ^ 0x9e3779b9u;
  };

  seed = adjust_seed(seed);
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

// Small helper: run count_unique and measure how long it took
std::pair<size_t, std::chrono::microseconds> timed_count_unique(const std::vector<int>& ids) {
  using namespace std::chrono;
  auto start = high_resolution_clock::now();
  size_t unique = count_unique(ids);
  auto end = high_resolution_clock::now();
  return {unique, duration_cast<microseconds>(end - start)};
}

// Print some quick statistics about the generated ids
void print_stats(const std::vector<int>& ids) {
  if (ids.empty()) {
    std::cout << "stats: empty\n";
    return;
  }
  int minv = ids[0];
  int maxv = ids[0];
  long long sum = 0;
  for (int v : ids) {
    if (v < minv) minv = v;
    if (v > maxv) maxv = v;
    sum += v;
  }
  double mean = static_cast<double>(sum) / ids.size();
  std::cout << "stats: count=" << ids.size() << " min=" << minv << " max=" << maxv << " mean=" << mean << "\n";
}

// Return a small deterministic sample of the vector (used for quick debug output)
std::vector<int> sample_ids(const std::vector<int>& ids, size_t sample_n) {
  std::vector<int> out;
  if (ids.empty() || sample_n == 0) return out;
  sample_n = std::min(sample_n, ids.size());
  size_t step = ids.size() / sample_n;
  if (step == 0) step = 1;
  for (size_t i = 0; i < ids.size() && out.size() < sample_n; i += step) {
    out.push_back(ids[i]);
  }
  return out;
}

void run_test(size_t N, unsigned seed) {
  auto ids = generate_ids(N, seed);
  // print a few diagnostics
  print_stats(ids);
  auto samp = sample_ids(ids, 5);
  std::cout << "sample:";
  for (int v : samp) std::cout << ' ' << v;
  std::cout << '\n';

  auto [unique, elapsed] = timed_count_unique(ids);
  std::cout << "Unique: " << unique << " (count took " << elapsed.count() << "us)\n";
}

int main() {
    run_test(200'000, 42);
    return 0;
}
