// Complexity: time and space
//
// We will compare how much work we do as data grows. Reaching a slot directly takes a fixed amount
// of work even with more slots (O(1); it does not mean exactly one step). Checking ten slots means
// ten visits, and checking twenty means twenty (O(n), where n is the slot count). By halving, we go
// from 8 to 1 in three divisions and from 16 to 1 in four (O(log n), where log n describes growth
// through halving). We call these abbreviations Big O notation: they describe growth, not exact
// seconds. We can also count extra data kept while doing the task; we call that auxiliary memory.
//
// Practice: We will compare two ways to inspect numbers.
// - We will count visits when reading one position and when scanning an entire array.
// - We will repeat with more data and explain which work increased.

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
