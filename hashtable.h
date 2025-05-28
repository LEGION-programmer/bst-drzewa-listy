#pragma once
#include <iostream>
#include <vector>
#include <list>

template<typename T>
class HashTable {
private:
    static const int SIZE = 10007; // Du¿a liczba pierwsza
    std::vector<std::list<T>> table;

    size_t hash(const T& val) const {
        return std::hash<T>{}(val) % SIZE;
    }

public:
    HashTable() : table(SIZE) {}

    void insert(const T& val) {
        size_t idx = hash(val);
        for (const auto& item : table[idx]) {
            if (item == val) return;
        }
        table[idx].push_back(val);
    }

    bool search(const T& val) const {
        size_t idx = hash(val);
        for (const auto& item : table[idx]) {
            if (item == val) return true;
        }
        return false;
    }

    void remove(const T& val) {
        size_t idx = hash(val);
        table[idx].remove(val);
    }
};