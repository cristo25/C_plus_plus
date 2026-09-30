// Binary search
//
// We will search an already sorted list. We look at the middle and decide which half could
// contain the number. We can picture numbered pages: for a smaller page, we discard the right
// half. Reducing 16 candidates to 8, 4, 2 and 1 takes four divisions; starting with 32 adds just
// one. This version finds the first match. We receive a position or an empty result and check
// which before reading it.
//
// Practice: We will search numbers in an ordered list.
// - We will check the center and discard the half that cannot contain the number.
// - We will try one repeated number and one missing number.

#include "../Searches.h"
#include <iostream>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;
using namespace course;

int main() {
    // The data is already sorted: each comparison can discard half of the remaining range.
    const vector<int> data{1, 3, 3, 5, 8};
    auto position = binarySearch(data, 3);

    if (position) {
        cout << "Index: " << *position << "\n";
    }
}
