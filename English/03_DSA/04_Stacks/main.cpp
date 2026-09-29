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
    while (!manual.empty()) {
        cout << manual.back() << ' ';
        manual.pop_back();
        adapter.pop();
    }
    cout << "\n";
}
