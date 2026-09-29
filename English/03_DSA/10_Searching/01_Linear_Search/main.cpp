// Linear search
//
// Inspect values from the start until finding a match. No sorting is required. Time O(n),
// auxiliary memory O(1). optional holds a position or nullopt for absence. Check before using
// *result; index 0 is valid. In applications you can use find instead.
//
// Analogy: Search a drawer for a key by checking every compartment.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Search for the first value, the last value and a missing value.

#include "../Searches.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    const vector<int> data{8, 3, 5, 3};
    auto position = linearSearch(data, 3);

    // optional distinguishes not found from index zero; dereference it only when an index
    // exists.
    if (position) {
        cout << "Index: " << *position << "\n";
    }
}
