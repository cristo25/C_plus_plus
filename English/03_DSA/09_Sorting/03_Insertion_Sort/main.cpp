// Insertion sort
//
// Maintain a sorted left section and insert each new value by shifting larger ones. Average and
// worst-case time O(n²); O(n) for sorted inputs. Additional memory O(1). Stable. Read
// insertionSort in ../Sorts.h.
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
