// Queues
//
// Compare arrival order and priority order. The integration example produces 2 9 4 with FIFO and
// 9 4 2 with priority.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe

#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> arrival;
    priority_queue<int> priority;
    for (int value : {2, 9, 4}) {
        arrival.push(value);
        priority.push(value);
    }
    cout << "FIFO: ";
    // FIFO preserves arrival order; the priority queue then selects the largest available value.
    while (!arrival.empty()) {
        cout << arrival.front() << ' ';
        arrival.pop();
    }
    cout << "\nPriority: ";
    while (!priority.empty()) {
        cout << priority.top() << ' ';
        priority.pop();
    }
    cout << "\n";
}
