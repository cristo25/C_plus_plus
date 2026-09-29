// Bubble sort
//
// We will sort by comparing neighbors. If the left value is larger, we swap their positions; after
// a pass the largest remaining value ends up at the end. We can picture large bubbles rising. If a
// pass makes no swaps, we are done. With n values we may repeat many comparisons, roughly like n
// times n (O(n²)); already sorted data needs only one pass (O(n)). The complete function is in
// Sorts.h.
//

#include "../Sorts.h"
#include <iostream>
// We store a collection that can grow using vector.
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
