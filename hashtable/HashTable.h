//
// Created by thongpv3 on 3/7/17.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

template <typename  K, typename V>
class HashTable {
public:
    //capacity
    bool empty() = 0;
    size_t size() = 0;

    //element access
    bool isContains(K key) = 0;

    //Modifiers
    bool insert(K key, V value) = 0;
    bool erase(K key) = 0;
    void clear() = 0;
};

#endif //HASHTABLE_HASHTABLE_H
