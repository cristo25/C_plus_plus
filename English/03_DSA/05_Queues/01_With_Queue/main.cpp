// FIFO queue
//
// queue processes values in arrival order: first in, first out. Add with push, inspect with
// front and remove with pop. Check empty before access.
//
// Analogy: A line at a food stall serves the first arrival first.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Add a third person and verify the order.

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<string> row;
    row.push("Ana");
    row.push("Luis");

    // The front person arrived first; reading and removing require a nonempty queue.
    while (!row.empty()) {
        cout << "Serve: " << row.front() << "\n";
        row.pop();
    }
}
