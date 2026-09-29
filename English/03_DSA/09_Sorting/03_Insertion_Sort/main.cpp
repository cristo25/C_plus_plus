// Insertion sort
//
// We will sort like arranging a hand of cards. We take a new value and shift larger earlier values
// until there is room for it. This keeps the left section sorted. For already sorted data we move
// through once (O(n), with n values); shifting many values each time can make work grow like n
// times n (O(n²)). By not moving a value ahead of an equal one, we preserve the order of ties.
//

#include "../Sorts.h"
#include <iostream>
// We store a collection that can grow using vector.
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
