#include <iostream>

using namespace std;

bool puedeEntrar(int edad, bool tieneBoleto) {
    return edad >= 18 && tieneBoleto;
}

int main() {

    if (puedeEntrar(20, true)) {
        cout << "Entrada permitida\n";
    } else {
        cout << "Entrada rechazada\n";
    }
}
