//
// Created by thongpv3 on 3/10/17.
//


#ifndef HASHTABLE_HASHTABLEWRAPPER_H
#define HASHTABLE_HASHTABLEWRAPPER_H

#include "HashTable.h"
#include "HashTableWrapper.h"
#include "generator/DiscreteGenerator.h"
#include <exception>
#include <cstdint>
#include <random>
#include <iostream>
#include <boost/thread/csbl/memory/unique_ptr.hpp>

template <typename K, typename V>
class HashTableWrapper {
private:

    enum class Operation {
        READ, WRITE, ERASE
    };
    DiscreteGenerator<Operation> opGen;
    std::unique_ptr<Generator<K>> keyGen;

    std::shared_ptr<HashTable<K, V>> hashTable;

public:
    HashTableWrapper (std::shared_ptr<HashTable<K, V>> table, std::unique_ptr<Generator<K>> generator) : keyGen(std::move(generator)) {
        this->hashTable = table;
    }

    HashTableWrapper& setProportion(uint32_t read, uint32_t write, uint32_t erase) {
        opGen.clear();
        opGen.addValue(Operation::READ, read);
        opGen.addValue(Operation::WRITE, write);
        opGen.addValue(Operation::ERASE, erase);
        return *this;
    }

    HashTableWrapper& setKeyGen() {

    }

//    HashTableWrapper& doWorkFor(uint64_t times) {
//        for (uint64_t i=0; i<times; i++) {
//            switch (opGen.next()) {
//                case Operation::READ: {
////                    std::cout << "READ" << std::endl;
//                    break;
//                }
//                case Operation::WRITE: {
////                    std::cout << "WRITE" << std::endl;
//                    hashTable->insert(keyGen->next(), 123456789);
//                    break;
//                }
//                case Operation::ERASE: {
////                    std::cout << "ERASE" << std::endl;
//                    break;
//                }
//            }
//        }
//    }

    HashTableWrapper& doWorkFor(uint64_t times) {
        switch (opGen.next()) {
                case Operation::READ: {
                    for (uint64_t i=0; i<times; i++) {
                        hashTable->isContains(keyGen->next());
                    }
                    break;
                }
                case Operation::WRITE: {
                    for (uint64_t i=0; i<times; i++) {
                        //todo reimplement: insert other data
                        hashTable->insert(keyGen->next(), 123456789);
                    }
                    break;
                }
                case Operation::ERASE: {
                    for (uint64_t i=0; i<times; i++) {
                        hashTable->erase(keyGen->next());
                    }
                    break;
                }
            }
    }

    HashTableWrapper& doWorkUntil(float loadFactor) {
        //todo implement
        return *this;
    }

};
#endif //HASHTABLE_HASHTABLEWRAPPER_H
