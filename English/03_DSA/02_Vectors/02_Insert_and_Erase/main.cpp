// Inserting and erasing in vectors
//
// insert and erase take iterators. begin() points to the first element; end() is past the last
// and must not be dereferenced. Middle insertion and erasure shift elements, costing O(n).
// Reallocation invalidates all pointers, references and iterators; erasure invalidates them from
// the erased position onward.
//
// Analogy: Making room in the middle of a drawer requires moving the items in the following
// compartments.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Remove every 20 using remove and erase. Explain the difference between rearranging
// elements and erasing them.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers{10, 30};
    // begin() + 1 is the second element's position: the values become 10, 20, 30.
    numbers.insert(numbers.begin() + 1, 20);

    // erase shifts following elements; do not reuse iterators invalidated by removal.
    numbers.erase(numbers.begin());

    if (!numbers.empty()) {
        numbers.pop_back();
    }

    cout << numbers.at(0) << "\n";
}
