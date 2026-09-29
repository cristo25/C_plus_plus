// Stacks
//
// Compare a vector implementation with the stack adapter. The integration example verifies that
// both produce 3 2 1.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    vector<int> manual;
    stack<int> adapter;
    for (int value : {1, 2, 3}) {
        manual.push_back(value);
        adapter.push(value);
    }
    // Both stacks remove from the top: last in, first out.
    while (!manual.empty()) {
        cout << manual.back() << ' ';
        manual.pop_back();
        adapter.pop();
    }
    cout << "\n";
}
