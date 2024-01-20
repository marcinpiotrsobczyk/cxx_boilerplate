#include <example/tools.hpp>

#include <benchmark/benchmark.h>

#include <iostream>
#include <memory>
#include <ostream>

static void BM_Fibonacci(benchmark::State &state) {
  for (auto _ : state)
    example::NaiveFibonacci(45);
}
// Register the function as a benchmark
BENCHMARK(BM_Fibonacci);

BENCHMARK_MAIN();
