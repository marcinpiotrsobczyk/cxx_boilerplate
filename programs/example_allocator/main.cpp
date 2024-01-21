#include <example/tools.hpp>

#include <benchmark/benchmark.h>

#include <iostream>
#include <memory>
#include <ostream>
#include <vector>

constexpr int N = 40;

template <typename Collection> void print_collection(Collection &collection) {
  for (const auto &value : collection)
    std::cout << value << ", ";
  std::cout << "\n";
}

static void BM_Fibonacci(benchmark::State &state) {
  for (auto _ : state) {
    std::vector<int> vec;

    for (int i = 0; i < N; i++) {
      auto value = example::NaiveFibonacci(i);
      vec.push_back(value);
    }

    std::cout << "vector size is " << vec.size() << "\n";
    print_collection(vec);
  }
}
// Register the function as a benchmark
BENCHMARK(BM_Fibonacci);

BENCHMARK_MAIN();
