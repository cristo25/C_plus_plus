// Complexity: time and space
//
// To compare programs, imagine increasing the amount of data. Reaching a slot directly by its index
// takes a fixed amount of work even when there are more slots (written O(1); it does not mean
// exactly one step). Inspecting every slot does increase the work: 20 visits are twice as many as
// 10 (O(n), where n is the number of elements). If we repeatedly halve what remains, going from 8
// to 1 takes three divisions and from 16 to 1 takes four (O(log n); here log n describes growth
// through halving). These abbreviations are called Big O notation and describe how work can grow,
// without specifying exact seconds. We can also count the extra data the program needs to keep:
// that is auxiliary memory.
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
        // Each iteration halves what remains: 1024 reaches 1 in ten divisions. Starting with twice
        // as many, 2048, only adds one division (O(log n) growth, with n as the initial amount).
        n /= 2;
        ++steps;
    }
    return steps;
}

int main() {
    cout << "Traversal of 1024 elements: 1024 visits\n";
    cout << "Halve 1024 down to 1: " << halvingSteps(1024) << " steps\n";
}
