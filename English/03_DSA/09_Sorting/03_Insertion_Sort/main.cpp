// Insertion sort
//
// Maintain a sorted left section and insert each new value by shifting larger ones. Each new value
// may require shifting many earlier ones. With n values, this repeated work can grow like n
// multiplied by n (O(n²), on average and in the worst case). If values are already sorted, one pass
// through them is enough (O(n)). It uses a few extra variables, without another array of the same
// size (O(1) additional memory). Stable. Read insertionSort in ../Sorts.h.
//
// Analogy: Sort a hand of cards by inserting each new card among the previous cards.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Trace the shifts when inserting 2 into 1, 3, 4.

#include "../Sorts.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    vector<int> data{5, -1, 3, 3, 0};
    // Like sorting cards: make room in the left-hand sorted region for each new value.
    insertionSort(data);

    for (int value : data) {
        cout << value << ' ';
    }
    cout << "\n";
}
