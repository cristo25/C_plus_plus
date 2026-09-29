// Bubble sort
//
// Compare adjacent values and swap inverted pairs. Each pass moves the largest remaining value to
// the end. With n values, repeated passes compare many of the same neighbors: work can grow roughly
// like n multiplied by n (O(n²), on average and in the worst case). If values are already sorted,
// the change flag allows stopping after one pass over the n values (O(n)). It only needs a few
// extra variables, without another input-sized array (O(1) additional memory). Stable. Read
// bubbleSort in ../Sorts.h.
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
