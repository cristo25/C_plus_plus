#include <array>
#include <iostream>

using namespace std;

int main() {
    array<array<int, 3>, 2> cabinet{{{1, 2, 3}, {4, 5, 6}}};
    for (const auto& row : cabinet) {
        for (int value : row) {
            cout << value << ' ';
        }
        cout << "\n";
    }
}
