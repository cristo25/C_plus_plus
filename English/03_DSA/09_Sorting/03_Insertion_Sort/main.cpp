// Insertion sort
//
// We will sort like arranging a hand of cards. We take a new value and shift larger earlier
// values until there is room for it. This keeps the left section sorted. If the values are
// already sorted, we pass through once. If they are reversed, we shift many values and do more
// work. By not moving a value ahead of an equal one, we preserve the order of ties.
//
// Practice: We will sort numbers like cards in our hand.
// - We will take one value and make room among the previous ones.
// - We will keep equal values in their original order when inserting it.

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
