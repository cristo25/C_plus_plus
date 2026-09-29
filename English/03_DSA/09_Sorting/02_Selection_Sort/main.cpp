// Selection sort
//
// Find the smallest pending value and swap it into the next position. After choosing one value, it
// scans the remaining section again to choose the next. With n values, comparisons accumulate
// roughly like n multiplied by n, even for sorted input (O(n²)). It only uses a few extra
// variables, without another array of the same size (O(1) additional memory). This implementation
// is not stable. Read selectionSort in ../Sorts.h.
//
// Analogy: Always take the smallest card from a pile and put it in the next free slot.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Count comparisons for four values and compare with bubble sort.

#include "../Sorts.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    vector<int> data{5, -1, 3, 3, 0};
    // Find the smallest pending value and put it in the next sorted position.
    selectionSort(data);

    for (int value : data) {
        cout << value << ' ';
    }
    cout << "\n";
}
