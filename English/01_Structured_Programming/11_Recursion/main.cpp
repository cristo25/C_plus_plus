// Recursion
//
// A recursive function calls itself with a smaller problem. A base case stops the calls. Without
// a base case or progress, the call stack may be exhausted. throw signals an invalid argument;
// try/catch lets the example check the rejection.
//
// Analogy: Open a box containing a smaller box until reaching an empty one.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Draw the calls and returns of factorial(3), then write a version using for.

#include <iostream>
#include <stdexcept>

using namespace std;

int factorial(int n) {
    if (n < 0 || n > 12) {
        throw invalid_argument("Use a number between 0 and 12");
    }
    // Base case: 0! and 1! equal 1. Without a stopping case, recursion would not end.
    if (n <= 1) {
        return 1;
    }
    // Each call solves a smaller problem; returning calls multiply their results.
    return n * factorial(n - 1);
}

int main() {

    try {
        cout << factorial(5) << "\n";
    } catch (const invalid_argument& error) {
        cerr << error.what() << "\n";
        return 1;
    }
}
