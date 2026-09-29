// Binary search
//
// We will search an already sorted list. We look at the middle and decide which half could contain
// the number. We can picture numbered pages: for a smaller page, we discard the right half.
// Reducing 16 candidates to 8, 4, 2 and 1 takes four divisions; starting with 32 adds just one
// (O(log n), where n counts candidates and log n describes the divisions). This version finds the
// first match. We receive a position or an empty result and check which before reading it.
//

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
