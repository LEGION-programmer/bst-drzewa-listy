#include "data_generator.h"
#include <fstream>
#include <cstdlib>

std::vector<int> generate_random_ints(int n, int max_val) {
    std::vector<int> data(n);
    for (int i = 0; i < n; ++i)
        data[i] = rand() % max_val;
    return data;
}

std::vector<std::string> generate_random_strings(int n, int max_len) {
    std::vector<std::string> data(n);
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < n; ++i) {
        int len = 1 + rand() % max_len;
        std::string str;
        for (int j = 0; j < len; ++j)
            str += charset[rand() % (sizeof(charset) - 1)];
        data[i] = str;
    }
    return data;
}

std::vector<int> read_ints_from_file(const std::string& filename) {
    std::vector<int> data;
    std::ifstream file(filename);
    int val;
    while (file >> val)
        data.push_back(val);
    return data;
}

std::vector<std::string> read_strings_from_file(const std::string& filename) {
    std::vector<std::string> data;
    std::ifstream file(filename);
    std::string val;
    while (file >> val)
        data.push_back(val);
    return data;
}

void save_ints_to_file(const std::string& filename, const std::vector<int>& data) {
    std::ofstream file(filename);
    for (int val : data)
        file << val << "\n";
}

void save_strings_to_file(const std::string& filename, const std::vector<std::string>& data) {
    std::ofstream file(filename);
    for (const auto& str : data)
        file << str << "\n";
}
