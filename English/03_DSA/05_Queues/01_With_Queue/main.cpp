#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<string> row;
    row.push("Ana");
    row.push("Luis");

    while (!row.empty()) {
        cout << "Serve: " << row.front() << "\n";
        row.pop();
    }
}
