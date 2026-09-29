// Functions: parameters and return values
//
// A function receives data, performs a task and may return a result. Parameters passed by value
// are copies; changing them does not change the original.
//
// Analogy: A machine receives ingredients through its input and delivers a product through its
// output.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Write a function that converts minutes to seconds.

#include <iostream>

using namespace std;

// The function receives a copy of the number and returns its square.
int square(int number) {
    return number * number;
}

int main() {

    cout << square(4) << "\n";
}
