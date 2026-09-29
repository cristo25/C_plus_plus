#include <iostream>

using namespace std;

int main() {
    int box = 10;
    int* address = &box; // Non-owning: box manages its own lifetime.
    *address = 25;

    int* withoutTarget = nullptr;
    if (withoutTarget != nullptr) {
        cout << *withoutTarget << "\n";
    }
    cout << "Contents: " << *address << "\n";
}
