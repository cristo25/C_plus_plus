#include <iostream>

using namespace std;

int main() {
    int* number = new int(42);

    cout << *number << "\n";
    delete number;
    number = nullptr; // Avoid accidentally reusing this address.
}
