// Priority queues and heaps
//
// priority_queue uses a heap. By default the largest value is at the top; greater<int> puts the
// smallest there. top costs O(1), insertion and removal O(log n). Equal priorities do not
// preserve arrival order.
//
// Analogy: An emergency room serves patients by severity rather than arrival order.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Remove every value from both queues. Explain why a heap is not a fully sorted
// vector.

#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    priority_queue<int> severity;
    // greater changes the criterion to put the smallest cost on top, like a line ordered by
    // urgency.
    priority_queue<int, vector<int>, greater<int>> cost;
    for (int value : {2, 9, 4}) {
        severity.push(value);
        cost.push(value);
    }

    cout << "Highest priority: " << severity.top() << "\n";
    cout << "Lowest cost: " << cost.top() << "\n";
}
