//
// Created by thongpv3 on 3/7/17.
//
#include <benchmark/benchmark_api.h>
#include <iostream>

static void BM_MemoryAllocate(benchmark::State& state) {
    std::cout << "a" << std::endl;
    while (state.KeepRunning()) {
        std::cout << "Hello, World\n" << std::endl;
    }
}

BENCHMARK(BM_MemoryAllocate);

BENCHMARK_MAIN();