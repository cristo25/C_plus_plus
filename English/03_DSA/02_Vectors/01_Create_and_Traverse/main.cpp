// Creating and traversing a vector
//
// vector is a contiguous array whose size can change. size() counts elements; capacity() counts
// reserved slots. Appending with push_back normally uses a free slot. When reserved storage fills
// up, the vector needs another block and must relocate its elements: that insertion may visit all n
// existing elements (O(n)). Spreading these expansions over many insertions keeps the work per
// insertion bounded by a constant amount; this is called amortized cost (amortized O(1)).
//
// Analogy: A growing drawer can move to a larger drawer when full. Its compartments still start
// at index zero.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Call reserve(10) and check that it changes capacity without adding elements.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers{10, 20};
    // Add a compartment to the expandable drawer. A reallocation may move every element.
    numbers.push_back(30);
    int sum = 0;
    for (int number : numbers) {
        sum += number;
    }

    cout << "Sum: " << sum << "\n";
}
