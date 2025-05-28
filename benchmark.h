#pragma once
#include <vector>
#include <string>
#include <chrono>

template<typename Structure, typename T>
long long benchmark(Structure& s, const std::vector<T>& data, const std::string& op) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    if (op == "insert") {
        for (const auto& val : data) s.insert(val);
    }
    else if (op == "search") {
        for (const auto& val : data) s.search(val);
    }
    else if (op == "delete") {
        for (const auto& val : data) s.remove(val);
    }

    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}
