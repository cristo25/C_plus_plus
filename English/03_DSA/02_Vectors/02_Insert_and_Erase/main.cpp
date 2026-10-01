// Inserting and erasing in vectors
//
// We will open and remove spaces in the middle of a vector. With begin() we obtain a position
// pointing to the start; begin() + 1 points to the second element. We call this way of pointing
// to a position an iterator. insert places a value and shifts later ones; erase removes a value
// and closes the gap. This may move nearly all the elements. After changing the vector we obtain
// needed positions again. Before pop_back we check empty so we do not remove from an empty
// vector.
//
// Practice: We will organize a list of numbers.
// - We will insert a number in the middle and remove another.
// - We will check that the list is not empty before removing the last one.

#include <iostream>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;

int main() {
    vector<int> numbers{10, 30};
    // begin() + 1 is the second element's position: the values become 10, 20, 30.
    numbers.insert(numbers.begin() + 1, 20);

    // We close the gap by moving later values. Afterward we obtain the positions we need again.
    numbers.erase(numbers.begin());

    if (!numbers.empty()) {
        numbers.pop_back();
    }

    if (!numbers.empty()) {
        cout << numbers[0] << "\n";
    }
}
