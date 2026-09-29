#include <iostream>
#include <string>

using namespace std;

string bebida(int opcion) {
    switch (opcion) {
        case 1:
            return "Agua";
        case 2:
            return "Cafe";
        default:
            return "Opcion invalida";
    }
}

int main() {

    cout << bebida(2) << "\n";
}
