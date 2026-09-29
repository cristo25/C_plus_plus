// The stack adapter
//
// stack exposes only stack operations: push, top, pop, size and empty. pop removes without
// returning a value; query top first. An adapter restricts operations on its underlying
// container.
//
// Analogy: A box of plates with one opening at the top cannot expose the middle plate.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Simulate two actions and two undo operations, and protect a third undo attempt.

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<string> history;
    history.push("Write");
    history.push("Delete");
    if (!history.empty()) {

        // top reads the last value; pop removes it without returning the value.
        cout << "Undo: " << history.top() << "\n";
        history.pop();
    }
}
