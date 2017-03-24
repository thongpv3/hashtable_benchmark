//
// Created by thongpv3 on 3/10/17.
//

#ifndef HASHTABLE_UNIFORMNUMBERGENERATOR_H
#define HASHTABLE_UNIFORMNUMBERGENERATOR_H

#include "Generator.h"
#include <cstdlib>
#include <random>
#include <type_traits>

template <typename T>
class UniformNumberGenerator : public Generator<T> {
    static_assert(std::is_integral<T>::value, "T must be an integral type");
    std::mt19937_64 _randomNumberGenerator;
public:
    UniformNumberGenerator()  {}

    T next() {
        return next(0, std::numeric_limits<T>::max());
    }

    T next(T maxValue) {
        return next(0, maxValue);
    }

    T next(T minValue, T maxValue) {
        std::uniform_int_distribution<T> distribution(minValue, maxValue);
        return distribution(_randomNumberGenerator);
    }
};
#endif //HASHTABLE_UNIFORMNUMBERGENERATOR_H
