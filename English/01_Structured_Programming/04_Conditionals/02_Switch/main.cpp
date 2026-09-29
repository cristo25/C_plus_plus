#include <iostream>
#include <string>

using namespace std;

string drink(int option) {
    switch (option) {
        case 1:
            return "Water";
        case 2:
            return "Coffee";
        default:
            return "Invalid option";
    }
}

int main() {

    cout << drink(2) << "\n";
}
