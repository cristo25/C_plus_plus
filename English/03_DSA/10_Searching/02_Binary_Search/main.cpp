// Binary search
//
// Requires ascending sorted data. Every comparison discards half of the range. Time O(log n),
// auxiliary memory O(1). Sorting has a separate cost. This version returns the first match;
// lower_bound is its standard alternative, while binary_search returns only existence.
//
// Analogy: Open a sorted guide at its middle and decide which half could contain the requested
// number.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Draw the ranges when searching for 8 and explain why the algorithm cannot directly
// use 8, 1, 3.

#include "../Searches.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    // The data is already sorted: each comparison can discard half of the remaining range.
    const vector<int> data{1, 3, 3, 5, 8};
    auto position = binarySearch(data, 3);

    if (position) {
        cout << "Index: " << *position << "\n";
    }
}
