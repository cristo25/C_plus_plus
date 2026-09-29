// Linear search
//
// We will search by checking a drawer one slot at a time. We do not need to sort first: we move
// until we find the value or reach the end. We may visit all n elements (O(n)). To return the
// result we use optional: a small box from <optional> that either holds a position or is empty. We
// check that it holds something before reading *position. Position zero is valid and must not be
// confused with “not found”.
//

#include "../Searches.h"
#include <iostream>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;
using namespace course;

int main() {
    const vector<int> data{8, 3, 5, 3};
    auto position = linearSearch(data, 3);

    // optional distinguishes not found from index zero; read its contained value only when an index
    // exists.
    if (position) {
        cout << "Index: " << *position << "\n";
    }
}
