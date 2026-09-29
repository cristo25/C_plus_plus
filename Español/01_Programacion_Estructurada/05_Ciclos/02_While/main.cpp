#include <iostream>

using namespace std;

int main() {
    int ahorro = 0;
    int semanas = 0;
    while (ahorro < 100) {
        ahorro += 25;
        ++semanas;
    }

    cout << semanas << " semanas\n";
}
