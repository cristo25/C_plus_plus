// Quick sort
//
// We will choose one value as a reference for separating the rest; we call it the pivot. We put
// smaller values on one side and repeat within each group. This is quick sort. With evenly split
// groups, each level checks the n values and the levels grow through halving (O(n log n)). Here we
// choose the last value: with sorted or equal input, almost everything can stay on one side and
// cause repeated work (O(n²), like n times n). This choice helps us see why the pivot matters.
//

#include "../Sorts.h"
#include <iostream>
// We store a collection that can grow using vector.
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
