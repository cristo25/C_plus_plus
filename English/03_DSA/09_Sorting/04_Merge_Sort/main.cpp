// Merge sort
//
// We will divide a pile into halves until the groups are small, then join them in order. We can
// picture two helpers sorting their sheets: when joining them, we always take the smallest
// available sheet. This is merge sort. We need extra space for merging, and it grows with the
// number of values. Each level visits all values, and there are as many levels as repeated
// halvings. For a tie we take the left value first to preserve order.
//
// Practice: We will sort by dividing and merging groups.
// - We will divide the data into small groups.
// - We will merge the halves in order without losing repeated values.

#include "../Sorts.h"
#include <iostream>
// We store a collection that can grow using vector.
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
