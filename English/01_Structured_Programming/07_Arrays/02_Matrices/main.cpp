// Matrices
//
// A matrix has rows and columns. Here an array contains arrays; both indices start at zero.
//
// Analogy: A cabinet has drawers (rows), and each drawer has compartments (columns).
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Compute the sum of each row separately.

#include <array>
#include <iostream>

using namespace std;

int main() {
    // A cabinet with two drawers and three compartments per drawer: two rows and three columns.
    array<array<int, 3>, 2> cabinet{{{1, 2, 3}, {4, 5, 6}}};
    // The const reference visits each row without copying or modifying it.
    for (const auto& row : cabinet) {
        for (int value : row) {
            cout << value << ' ';
        }
        cout << "\n";
    }
}
