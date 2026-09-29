// Merge sort
//
// Split into halves, sort each half and merge them. Time O(n log n); auxiliary memory O(n) plus
// O(log n) recursive calls. Stable because ties select the left item first. Read mergeSort in
// ../Sorts.h.
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
