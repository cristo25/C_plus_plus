#include <iostream>

using namespace std;

int halvingSteps(int n) {
    int steps = 0;
    while (n > 1) {
        n /= 2;
        ++steps;
    }
    return steps;
}

int main() {
    cout << "Traversal of 1024 elements: 1024 visits\n";
    cout << "Halve 1024 down to 1: " << halvingSteps(1024) << " steps\n";
}
