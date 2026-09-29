#include <iostream>

using namespace std;

int main() {
    int attempts = 0;
    do {
        ++attempts;
        cout << "Attempt " << attempts << "\n";
    } while (attempts < 3);
}
