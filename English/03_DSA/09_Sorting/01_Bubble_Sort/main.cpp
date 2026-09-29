// Bubble sort
//
// Compare adjacent values and swap inverted pairs. Each pass moves the largest remaining value
// to the end. Average and worst-case time O(n²), best case O(n) for sorted data with the change
// flag. Additional memory O(1). Stable. Read bubbleSort in ../Sorts.h.
//
// Analogy: Large bubbles rise toward an end; each pass moves the largest number there.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Draw every pass for 4, 2, 3, 1.

#include "../Sorts.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    vector<int> data{5, -1, 3, 3, 0};
    // The function swaps reversed neighbors and leaves the largest remaining value at the end of
    // each pass.
    bubbleSort(data);

    for (int value : data) {
        cout << value << ' ';
    }
    cout << "\n";
}
