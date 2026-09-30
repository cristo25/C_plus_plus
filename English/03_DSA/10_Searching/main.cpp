// Searching
//
// We will compare one-by-one search with halving search. First we search unsorted data, then sort
// and try both methods on the same vector. The number stays the same, but sorting can change its
// position. We also count the preparation: building a sorted list is extra work, even if searching
// within it afterward is faster.
//
// Practice: We will compare two ways to find a number.
// - We will search an unsorted list one value at a time.
// - We will sort another list and search by halves, comparing the positions.

#include "Searches.h"
// We use sort to sort or change data order.
#include <algorithm>
#include <iostream>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;
using namespace course;

int main() {
    vector<int> data{8, 3, 5, 1, 3};
    if (!(linearSearch(data, 8).value() == 0)) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    // Binary search requires sorted input; sorting changes the original positions of values.
    sort(data.begin(), data.end());
    for (int target : {0, 1, 3, 5, 8, 99}) {
        if (!(linearSearch(data, target) == binarySearch(data, target))) {
            cerr << "The check did not produce the expected result.\n";
            return 1;
        }
    }
    cout << "Index of 8 after sorting: " << binarySearch(data, 8).value() << "\n";
}
