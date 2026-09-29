#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers{10, 30};
    numbers.insert(numbers.begin() + 1, 20);

    numbers.erase(numbers.begin());

    if (!numbers.empty()) {
        numbers.pop_back();
    }

    cout << numbers.at(0) << "\n";
}
