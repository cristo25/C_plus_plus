#include <array>
#include <iostream>

using namespace std;

int main() {
    array<int, 4> drawer{10, 20, 30, 40};
    int sum = 0;
    for (int value : drawer) {
        sum += value;
    }
    drawer.at(1) = 25;

    cout << "Original sum: " << sum << "\n";
}
