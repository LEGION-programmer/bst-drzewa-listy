#pragma once
#include <vector>
#include <string>

// Generowanie danych
std::vector<int> generate_random_ints(int n, int max_val = 1000000);
std::vector<std::string> generate_random_strings(int n, int max_len = 50);

// Wczytywanie danych
std::vector<int> read_ints_from_file(const std::string& filename);
std::vector<std::string> read_strings_from_file(const std::string& filename);

// ZAPIS do pliku
void save_ints_to_file(const std::string& filename, const std::vector<int>& data);
void save_strings_to_file(const std::string& filename, const std::vector<std::string>& data);
