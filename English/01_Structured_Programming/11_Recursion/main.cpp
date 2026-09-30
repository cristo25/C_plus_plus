// Recursion
//
// We will solve a task by calling the same function with a smaller case; we call this recursion.
// Here we calculate a factorial: 4! means 4 times 3 times 2 times 1. In factorial(n) we multiply n
// by factorial(n - 1). We stop calls when n is 0 or 1, whose result is 1. We can picture boxes
// inside boxes: we open them down to the smallest and then return, combining results. Before calling
// factorial we check that the number is between 0 and 12 so its result fits in int.
//

// Practice: Let's write a program that calculates a sum recursively.
//
// - Create a function that adds from 1 to n.
// - Define a case that ends without another call.
// - Use a smaller value on each call.
// - Try 0, 1 and 5 and explain how the result returns.

#include <iostream>

using namespace std;

int factorial(int n) {
    // Base case: 0! and 1! equal 1. Without a stopping case, recursion would not end.
    if (n <= 1) {
        return 1;
    }
    // Each call solves a smaller problem; returning calls multiply their results.
    return n * factorial(n - 1);
}

int main() {
    const int number = 5;
    if (number < 0 || number > 12) {
        cerr << "Use a number between 0 and 12.\n";
        return 1;
    }
    cout << factorial(number) << "\n";
}
