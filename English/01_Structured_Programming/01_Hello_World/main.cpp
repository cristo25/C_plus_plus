// Your first program
//
// #include brings in declarations from the standard library. main is the entry point and cout
// writes to the console. Returning 0 means success. using namespace std; lets us write standard
// names without a prefix.
//
// Analogy: A program is a recipe. main tells the cook where to start, and each statement is a
// step.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Replace the greeting with your name and add another line.

#include <iostream>

// Lets us write cout without the standard namespace prefix.
using namespace std;

// Execution starts in main; returning 0 reports success.
int main() {
    cout << "Hello, C++!\n";
    return 0;
}
