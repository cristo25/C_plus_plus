// Recursion
//
// We will solve a task by calling the same function with a smaller case; we call this recursion.
// Here we calculate a factorial: 4! means 4 times 3 times 2 times 1. In factorial(n) we multiply n
// by factorial(n - 1). We stop calls when n is 0 or 1, whose result is 1. We can picture boxes
// inside boxes: we open them down to the smallest and then return, combining results. We limit n to
// 12 so the result fits in int. With throw we report invalid data; with try and catch we catch that
// report and display it.
//

#include <iostream>
// We report errors with messages, such as invalid_argument for an invalid value.
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
