// Repeating with while
//
// while checks its condition before each iteration. It may run zero times. Change something that
// eventually makes the condition false.
//
// Analogy: Keep filling a piggy bank until you reach your savings goal.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Change the goal to 110 and explain why the final balance is 125.

#include <iostream>

using namespace std;

int main() {
    int savings = 0;
    int weeks = 0;
    // Check the condition before the body; weeks counts how many deposits are needed.
    while (savings < 100) {
        savings += 25;
        ++weeks;
    }

    cout << weeks << " weeks\n";
}
