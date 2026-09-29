// One-dimensional arrays
//
// array<int, 4> stores four contiguous integers. Its size is fixed, with indices 0 through 3.
// at() checks bounds; [] requires a valid index. A traditional array is written int data[4] and
// has no at().
//
// Analogy: An array is a drawer for one type of item, divided into numbered compartments
// starting at zero. Four compartments cannot hold a fifth item.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Create a drawer of five grades and compute an average using floating-point division.

#include <array>
#include <iostream>

using namespace std;

int main() {
    // A four-compartment drawer for integers: indexes 0, 1, 2 and 3; its size is fixed.
    array<int, 4> drawer{10, 20, 30, 40};
    int sum = 0;
    for (int value : drawer) {
        sum += value;
    }
    // at(1) is the second compartment and checks the index. The sum was computed before this
    // change.
    drawer.at(1) = 25;

    cout << "Original sum: " << sum << "\n";
}
