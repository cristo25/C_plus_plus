// Merge sort
//
// Split into halves, sort each half and merge them. Halving creates several levels of work;
// doubling the data adds about one level. At each level, merging visits all n values in total: the
// work combines the value count with the number of levels (O(n log n); n counts values and log n
// describes halving levels). It needs an auxiliary array that grows with the data (O(n) memory) and
// keeps pending calls along the current division path (O(log n) memory for calls). Stable because
// ties select the left item first. Read mergeSort in ../Sorts.h.
//
// Analogy: Divide sheets between two helpers, then combine their sorted piles by choosing the
// smaller available sheet.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Draw splits and merges for six values. Observe that the range endpoint is excluded.

#include "../Sorts.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    vector<int> data{5, -1, 3, 3, 0};
    // Split into halves and merge the sorted groups; the header shows each step.
    mergeSort(data);

    for (int value : data) {
        cout << value << ' ';
    }
    cout << "\n";
}
