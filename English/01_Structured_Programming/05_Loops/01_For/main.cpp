// Repeating with for
//
// for groups initialization, condition and progress. Use it when you know the number of
// repetitions.
//
// Analogy: You visit five lockers one by one without skipping any.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Print the multiplication table for 7 with ten iterations.

#include <iostream>

using namespace std;

int sumUpTo(int limit) {
    int sum = 0;
    // Start at 1, continue through limit, and increase number after each iteration.
    for (int number = 1; number <= limit; ++number) {
        sum += number;
    }
    return sum;
}

int main() {

    cout << sumUpTo(5) << "\n";
}
