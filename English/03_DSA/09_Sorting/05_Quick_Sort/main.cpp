// Quick sort
//
// Choose a pivot, partition values and recursively sort the partitions. Usually O(n log n), but
// this last-element pivot can take O(n²) for sorted or equal inputs. The recursive stack can
// reach O(n). Not stable. Read quickSort in ../Sorts.h.
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
