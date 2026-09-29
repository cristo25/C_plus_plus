// Sorting algorithms
//
// Study algorithms using the same input and compare time, memory and stability. Stability
// preserves the original order of elements with equal keys. The integration example checks five
// algorithms against sort, including empty input, duplicates, negatives and sorted values.
// Function pointers allow repeating the same check.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe

#include "Sorts.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    // A function pointer lets us test all five algorithms through the same call.
    using SortFunction = void (*)(vector<int>&); // Address of a function.
    for (SortFunction sortValues :
         {bubbleSort, selectionSort, insertionSort, mergeSort, quickSort}) {
        for (const vector<int>& input :
             vector<vector<int>>{{}, {1}, {4, 3, 2, 1}, {1, 2, 3, 4}, {2, 2, -1, 0, 2}}) {
            auto result = input;
            auto expected = input;
            sort(expected.begin(), expected.end());
            sortValues(result);
            // assert checks an integration result; it does not perform application operations.
            assert(result == expected);
        }
    }
    cout << "All 5 algorithms match sort on 5 inputs.\n";
}
