// Bubble sort
//
// We will sort by comparing neighbors. If the left value is larger, we swap their positions;
// after a pass the largest remaining value ends up at the end. We can picture large bubbles
// rising. If a pass makes no swaps, we are done. When values are reversed, we make many
// comparisons; doubling the number of values can make them grow to almost four times as many.
// Already sorted values need just one pass. The complete function is in Sorts.h.
//
// Practice: We will sort numbers like bubbles rising.
// - We will compare neighbors and swap them when out of order.
// - We will stop when a full pass makes no changes.

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
