// Quick sort
//
// Choose a pivot, partition values and recursively sort the partitions. When partitions are
// reasonably even, each level processes the n values and the level count grows like repeated
// halving (O(n log n); n counts values). If the pivot leaves nearly everything on one side,
// repeated long traversals can make work grow like n multiplied by n (O(n²)); choosing the last
// value as pivot causes this for sorted or equal inputs. Up to one pending call per value can also
// accumulate (O(n) memory for calls). Not stable. Read quickSort in ../Sorts.h.
//
// Analogy: A pivot splits a line: smaller values move left and the rest move right; repeat
// within each group.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Trace pivots for 4, 1, 3, 2. Try sorted data and explain why this version becomes
// unbalanced.

#include "../Sorts.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    vector<int> data{5, -1, 3, 3, 0};
    // The pivot separates smaller values; repeat the work in both partitions.
    quickSort(data);

    for (int value : data) {
        cout << value << ' ';
    }
    cout << "\n";
}
