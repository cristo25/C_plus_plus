#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> stackValues;

    stackValues.push_back(10);
    stackValues.push_back(20);
    if (!stackValues.empty()) {
        const int topValue = stackValues.back();
        stackValues.pop_back();

        cout << "Removed: " << topValue << "\n";
    }
}
