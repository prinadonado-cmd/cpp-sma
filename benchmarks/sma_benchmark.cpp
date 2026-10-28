#include "sma.hpp"

#include <benchmark/benchmark.h>

#include <cstddef>
#include <vector>

static void BM_Sma(benchmark::State& state)
{
    const auto count = static_cast<std::size_t>(state.range(0));
    const auto window = static_cast<std::size_t>(state.range(1));

    std::vector<double> prices(count);
    for (std::size_t i = 0; i < count; ++i) {
        prices[i] = 100.0 + static_cast<double>(i % 100);
    }

    for (auto _ : state) {
        auto result = calculate_sma(prices, window);
        benchmark::DoNotOptimize(result);
    }
}

BENCHMARK(BM_Sma)
->Args({ 1000, 10 })
->Args({ 10000, 10 })
->Args({ 10000, 100 })
->ArgNames({ "n", "window" })
->Unit(benchmark::kMicrosecond);

BENCHMARK_MAIN();