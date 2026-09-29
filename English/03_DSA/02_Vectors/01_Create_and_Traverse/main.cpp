// Creating and traversing a vector
//
// vector is a contiguous array whose size can change. size() counts elements; capacity() counts
// reserved slots. push_back takes amortized O(1), although an individual reallocation costs
// O(n).
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
