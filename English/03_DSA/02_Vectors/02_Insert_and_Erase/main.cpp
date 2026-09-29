// Inserting and erasing in vectors
//
// We will open and remove spaces in the middle of a vector. With begin() we obtain a position
// pointing to the start; begin() + 1 points to the second element. We call this way of pointing to
// a position an iterator. insert places a value and shifts later ones; erase removes a value and
// closes the gap. This may move nearly all n elements (O(n)). After changing the vector we obtain
// needed positions again. Before pop_back we check empty so we do not remove from an empty vector.
//

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

    cout << numbers.at(0) << "\n";
}
