#include "Sorts.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    using SortFunction = void (*)(vector<int>&); // Address of a function.
    for (SortFunction sortValues :
         {bubbleSort, selectionSort, insertionSort, mergeSort, quickSort}) {
        for (const vector<int>& input :
             vector<vector<int>>{{}, {1}, {4, 3, 2, 1}, {1, 2, 3, 4}, {2, 2, -1, 0, 2}}) {
            auto result = input;
            auto expected = input;
            sort(expected.begin(), expected.end());
            sortValues(result);
            assert(result == expected);
        }
    }
    cout << "All 5 algorithms match sort on 5 inputs.\n";
}
