//
// Created by thongpv3 on 3/14/17.
//
#include <benchmark/benchmark.h>
#include "StdUnorderedMapBinding.h"
#include "StdMapBinding.h"
#include "generator/UniformNumberGenerator.h"
#include "HashTableWrapper.h"
#include "LeapfrogMapBinding.h"

void BM_stdmap1(benchmark::State& state) {
    std::shared_ptr<StdMapBinding<uint64_t , uint32_t>> stdMap(new StdMapBinding<uint64_t, uint32_t>());
    std::unique_ptr<Generator<uint64_t>> ptr(new UniformNumberGenerator<uint64_t>());
    HashTableWrapper<uint64_t, uint32_t> htw(stdMap, std::move(ptr));

    //set htw to insert mode
    htw.setProportion(0,1,0);
    while (state.KeepRunning()) {
        htw.doWorkFor(200000000);
    }
    std::cout << "std::map size after insert: " << stdMap->size() << std::endl;
}
BENCHMARK(BM_stdmap1);

void BM_stdmap2(benchmark::State& state) {
    std::shared_ptr<StdMapBinding<uint64_t , uint32_t>> stdMap(new StdMapBinding<uint64_t, uint32_t>());
    std::unique_ptr<Generator<uint64_t>> ptr(new UniformNumberGenerator<uint64_t>());
    HashTableWrapper<uint64_t, uint32_t> htw(stdMap, std::move(ptr));
    //insert 20m records
    htw.setProportion(0,1,0).doWorkFor(20000000);

    //set htw ready for erase
    htw.setProportion(0,0,1);
    while (state.KeepRunning()) {
        htw.doWorkFor(200000000);
    }
    std::cout << "std::map size after erase: " << stdMap->size() << std::endl;
}
BENCHMARK(BM_stdmap2);


void BM_stdumap1(benchmark::State& state) {
    std::shared_ptr<StdUnorderedMapBinding<uint64_t, uint32_t>> stdUMap(new StdUnorderedMapBinding<uint64_t, uint32_t>());
    std::unique_ptr<Generator<uint64_t>> ptr(new UniformNumberGenerator<uint64_t>());
    HashTableWrapper<uint64_t, uint32_t> htw(stdUMap, std::move(ptr));

    //set htw to insert mode
    htw.setProportion(0,1,0);
    while (state.KeepRunning()) {
        htw.doWorkFor(20000000);
    }
    std::cout << "std::unordered_map size after insert: " << stdUMap->size() << std::endl;
}
BENCHMARK(BM_stdumap1);

void BM_stdumap2(benchmark::State& state) {
    std::shared_ptr<StdUnorderedMapBinding<uint64_t, uint32_t>> stdUMap(new StdUnorderedMapBinding<uint64_t, uint32_t>());
    std::unique_ptr<Generator<uint64_t>> ptr(new UniformNumberGenerator<uint64_t>());
    HashTableWrapper<uint64_t, uint32_t> htw(stdUMap, std::move(ptr));
    //insert 20m record
    htw.setProportion(0,1,0).doWorkFor(20000000);

    //set htw to erase mode
    htw.setProportion(0,0,1);


    while (state.KeepRunning()) {
        htw.doWorkFor(20000000);
    }
    std::cout << "std::unordered_map size after erase: " << stdUMap->size() << std::endl;
}
BENCHMARK(BM_stdumap2);

BENCHMARK_MAIN();