#include <iostream>

using namespace std;

int precio(int opcion, bool estudiante) {
    int base = 0;
    switch (opcion) {
        case 1:
            base = 20;
            break;
        case 2:
            base = 30;
            break;
        default:
            return -1;
    }
    if (estudiante) {
        base -= 5;
    }
    return base;
}

int main() {

    cout << "Bebida 2 con descuento: " << precio(2, true) << "\n";
}
