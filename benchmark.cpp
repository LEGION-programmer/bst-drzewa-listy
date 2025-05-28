#include "benchmark.h"
#include <chrono>
using namespace std;
using namespace std::chrono;

template<typename Structure, typename T>
long long benchmark(Structure& s, const std::vector<T>& data, const std::string& op) {
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
    auto stop = high_resolution_clock::now();
    return duration_cast<milliseconds>(stop - start).count();
}

// Instancjacje szablonu
template long long benchmark<class Structure, int>(Structure&, const std::vector<int>&, const std::string&);
template long long benchmark<class Structure, std::string>(Structure&, const std::vector<std::string>&, const std::string&);
