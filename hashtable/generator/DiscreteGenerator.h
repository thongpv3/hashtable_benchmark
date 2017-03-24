//
// Created by thongpv3 on 3/10/17.
//

#ifndef HASHTABLE_DISCRETEGENERATOR_H
#define HASHTABLE_DISCRETEGENERATOR_H

#include <string>
#include <vector>
#include "Generator.h"
#include "UniformNumberGenerator.h"

template <typename T>
class DiscreteGenerator : public Generator<T> {
    std::vector<std::pair<T, uint32_t >> _values;
    UniformNumberGenerator<uint32_t> generator;
    uint32_t sum = 0;
public:
    void addValue(T value, uint32_t weight) {
        _values.push_back(std::make_pair(value, weight));
        sum += weight;
    }

    T next() {
        uint32_t val = generator.next() % sum;

        uint32_t t = 0;
        for (auto const &i : _values) {
            t +=i.second;
            if (val < i.second)
                return i.first;
        }

//        static_assert(false, "Unexpected behavior");
        return _values[0].first;
    }

    void clear() {
        _values.clear();
    }
};

#endif //HASHTABLE_DISCRETEGENERATOR_H
