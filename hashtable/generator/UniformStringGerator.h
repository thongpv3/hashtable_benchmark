//
// Created by thongpv3 on 3/14/17.
//

#pragma once

#include "Generator.h"
#include <string>
#include "UniformNumberGenerator.h"

class UniformStringGenerator : public Generator<std::string> {
private:
    UniformNumberGenerator<uint64_t> _gen;
    size_t _size;
public:
    UniformStringGenerator(size_t size) : _size(size) {
    }

    std::string next() override {
        std::string str;
        while ((str.length()) < _size) {
            str.append(std::to_string(_gen.next()));
        }

        str.erase(_size);
        return str;
    }
};