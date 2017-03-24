//
// Created by thongpv3 on 3/10/17.
//

#ifndef HASHTABLE_GENERATOR_H
#define HASHTABLE_GENERATOR_H

template <typename T>
class Generator {
public:
    virtual T next() = 0;
    virtual ~Generator() {};
};
#endif //HASHTABLE_KEYGENERATOR_H
