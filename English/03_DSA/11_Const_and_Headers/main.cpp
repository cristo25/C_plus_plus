// Const and headers in DSA
//
// We will query a collection without changing it. With const vector<int>& we receive another label
// for the same vector, but only for reading. In Queries.h we announce the function; in Queries.cpp
// we traverse the values and count those above a limit. We need neither copying nor sorting.
// Doubling the data doubles the visits (O(n), with n elements). We add only a counter and a few
// variables (O(1) additional memory).
//

#include "Queries.h"
#include <iostream>

using namespace std;
using namespace course;

int main() {
    const vector<int> data{9, 4, 10, 6};
    // The query receives const vector<int>&: count without copying or changing the data.
    const size_t count = countAbove(data, EXAMPLE_LIMIT);
    cout << "Values above " << EXAMPLE_LIMIT << ": " << count << "\n";
    for (const int value : data) {
        cout << value << ' ';
    }
    cout << "\n";
}
