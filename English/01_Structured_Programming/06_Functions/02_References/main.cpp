// References and parameter passing
//
// int& is an alias for the original value. const string& lets you inspect a string without
// copying or modifying it. Initialize a reference when declaring it.
//
// Analogy: A reference is a second label on the same box, rather than a second box.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Change the parameter to int number and observe why the check fails.

#include <iostream>
#include <string>

using namespace std;

// A reference is another name for the same variable: ++ changes the original counter.
void increment(int& number) {
    ++number;
}
// const string& reads the text without copying or modifying it.
size_t length(const string& text) {
    return text.size();
}

int main() {
    int counter = 4;
    increment(counter);

    cout << counter << "\n";
}
