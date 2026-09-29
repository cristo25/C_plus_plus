#include <iostream>

using namespace std;

class Alcancia {
    int saldo = 0; // Centavos enteros para evitar errores de redondeo.
public:
    bool depositar(int centavos) {
        if (centavos <= 0 || centavos > 1000000 - saldo) {
            return false;
        }
        saldo += centavos;
        return true;
    }
    bool retirar(int centavos) {
        if (centavos <= 0 || centavos > saldo) {
            return false;
        }
        saldo -= centavos;
        return true;
    }
    int consultar() const {
        return saldo;
    }
};

int main() {
    Alcancia ahorro;
    if (ahorro.depositar(-5)) {
        return 1;
    }
    if (!(ahorro.depositar(500))) {
        return 1;
    }
    if (ahorro.retirar(600)) {
        return 1;
    }
    if (!(ahorro.retirar(200))) {
        return 1;
    }

    cout << ahorro.consultar() << " centavos\n";
}
