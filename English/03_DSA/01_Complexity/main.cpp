// Complexity: time and space
//
// Big O describes how work grows with input size, rather than exact seconds. Index access is
// O(1), visiting n elements is O(n), and repeatedly halving a problem takes O(log n) steps. Also
// count additional memory.
//
// Analogy: Finding a numbered compartment is direct. Inspecting every compartment takes longer
// as the cabinet grows. Halving a sorted guide discards many pages at once.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Compare n = 8, 16 and 32. Draw the growth of n and the number of halvings.

#include <iostream>

using namespace std;

int halvingSteps(int n) {
    int steps = 0;
    while (n > 1) {
        // Each iteration halves the problem: 1024 reaches 1 in ten steps, O(log n) growth.
        n /= 2;
        ++steps;
    }
    return steps;
}

int main() {
    cout << "Traversal of 1024 elements: 1024 visits\n";
    cout << "Halve 1024 down to 1: " << halvingSteps(1024) << " steps\n";
}
