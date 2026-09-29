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
