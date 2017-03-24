//
// Created by thongpv3 on 3/10/17.
//

#include <iostream>
#include <map>
#include "generator/UniformNumberGenerator.h"
#include "generator/DiscreteGenerator.h"
#include "HashTableWrapper.h"
#include "StdMapBinding.h"
#include "generator/UniformStringGerator.h"

int main() {
    std::shared_ptr<StdMapBinding<uint64_t , uint32_t>> stdMap(new StdMapBinding<uint64_t, uint32_t>());
    std::unique_ptr<Generator<uint64_t>> ptr(new UniformNumberGenerator<uint64_t>());
    HashTableWrapper<uint64_t, uint32_t> htw(stdMap, std::move(ptr));

    htw.setProportion(0, 1000, 0).doWorkFor(10000);
    std::cout << stdMap->size() << std::endl;
}