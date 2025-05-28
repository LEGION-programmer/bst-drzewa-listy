#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "data_generator.h"
#include "benchmark.h"
#include "linked_list.h"
#include "bst.h"
#include "hashtable.h"

using namespace std;

template<typename T>
void run_benchmark(vector<T> data) {
    LinkedList<T> list;
    BST<T> bst;
    HashTable<T> hash;

    cout << "\n== INSERT ==" << endl;
    cout << "Lista: " << benchmark(list, data, "insert") << " ms\n";
    cout << "BST:   " << benchmark(bst, data, "insert") << " ms\n";
    cout << "Hash:  " << benchmark(hash, data, "insert") << " ms\n";

    cout << "\n== SEARCH ==" << endl;
    cout << "Lista: " << benchmark(list, data, "search") << " ms\n";
    cout << "BST:   " << benchmark(bst, data, "search") << " ms\n";
    cout << "Hash:  " << benchmark(hash, data, "search") << " ms\n";

    cout << "\n== DELETE ==" << endl;
    cout << "Lista: " << benchmark(list, data, "delete") << " ms\n";
    cout << "BST:   " << benchmark(bst, data, "delete") << " ms\n";
    cout << "Hash:  " << benchmark(hash, data, "delete") << " ms\n";
}

int main() {
    srand(time(nullptr));
    int n, data_type, source;

    cout << "=== TEST STRUKTUR DANYCH ===\n";
    cout << "Liczba elementów do testu: ";
    cin >> n;

    cout << "Typ danych:\n1. Liczby całkowite\n2. Ciągi znaków\nWybór: ";
    cin >> data_type;

    cout << "Źródło danych:\n1. Losowe\n2. Plik\nWybór: ";
    cin >> source;

    if (data_type == 1) {
        vector<int> data;

        if (source == 1) {
            data = generate_random_ints(n);
            char save;
            cout << "Czy zapisać dane do pliku? (t/n): ";
            cin >> save;
            if (save == 't' || save == 'T') {
                string fname;
                cout << "Podaj nazwę pliku: ";
                cin >> fname;
                save_ints_to_file(fname, data);
            }
        }
        else {
            string fname;
            cout << "Podaj nazwę pliku: ";
            cin >> fname;
            data = read_ints_from_file(fname);
        }

        run_benchmark(data);

    }
    else if (data_type == 2) {
        vector<string> data;

        if (source == 1) {
            data = generate_random_strings(n);
            char save;
            cout << "Czy zapisać dane do pliku? (t/n): ";
            cin >> save;
            if (save == 't' || save == 'T') {
                string fname;
            }
        }
    }
};