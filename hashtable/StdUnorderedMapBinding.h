//
// Created by thongpv3 on 3/14/17.
//

#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>
#include "HashTable.h"
template <typename K, typename V>
class StdUnorderedMapBinding : public HashTable<K, V> {
    std::unordered_map<K, V> _map;
public:
    bool empty() override {
        return _map.empty();
    }

    size_t size() override {
        return _map.size();
    }

    bool isContains(const K& key) override {
        return _map.find(key) != _map.end();
    }

    bool insert(const K& key, const V& value) override {
        return _map.emplace(key, value).second;
    }

    void erase (const K& key) override {
        _map.erase(key);
    }

    void clear() override {
        _map.clear();
    }
};