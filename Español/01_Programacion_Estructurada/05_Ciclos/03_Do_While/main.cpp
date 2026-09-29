#include <iostream>

using namespace std;

int main() {
    int intentos = 0;
    do {
        ++intentos;
        cout << "Intento " << intentos << "\n";
    } while (intentos < 3);
}
