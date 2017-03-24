//
// Created by thongpv3 on 3/7/17.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

template <typename  K, typename V>
class HashTable {
public:
    //capacity
    virtual bool empty() {};
    virtual size_t size() {};

    //element access
    virtual bool isContains(const K& key) {};

    //Modifiers
    virtual bool insert(const K& key, const V& value) {};
    virtual void erase(const K& key) {};
    virtual void clear() {};
};

#endif //HASHTABLE_HASHTABLE_H
