// Repeating with do while
//
// do while checks its condition after the body, so it always runs at least once.
//
// Analogy: Try a key once before deciding whether to keep trying.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Start with attempts = 3 and observe that the body still runs.

#include <iostream>

using namespace std;

int main() {
    int attempts = 0;
    // Make an attempt first, then decide whether to repeat. There is always at least one
    // attempt.
    do {
        ++attempts;
        cout << "Attempt " << attempts << "\n";
    } while (attempts < 3);
}
