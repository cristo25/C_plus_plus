#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers{10, 20};
    numbers.push_back(30);
    int sum = 0;
    for (int number : numbers) {
        sum += number;
    }

    cout << "Sum: " << sum << "\n";
}
