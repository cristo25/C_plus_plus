// Encapsulamiento y const
//
// Vamos a proteger el saldo de una alcancía. En lugar de permitir cualquier cambio desde main, lo
// guardamos dentro de la clase y ofrecemos depositar y retirar. Cada función comprueba sus reglas
// antes de cambiar el saldo. Llamamos encapsulamiento a reunir esos datos y sus reglas detrás de
// operaciones controladas. Dentro de class, los datos son privados si no escribimos public. Con
// consultar() const podemos leer el saldo sin cambiarlo: const al final de una función promete
// respetar los datos del objeto.
//

#include <iostream>

using namespace std;

class Alcancia {
    int saldo = 0; // Centavos enteros para evitar errores de redondeo.
// saldo es privado por defecto en class. Solo los métodos validados pueden cambiarlo.
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
    // const después de los paréntesis promete que la consulta no modifica el objeto.
    int consultar() const {
        return saldo;
    }
};

int main() {
    Alcancia ahorro;
    if (ahorro.depositar(-5)) {
        return 1;
    }
    if (!ahorro.depositar(500)) {
        return 1;
    }
    if (ahorro.retirar(600)) {
        return 1;
    }
    if (!ahorro.retirar(200)) {
        return 1;
    }

    cout << ahorro.consultar() << " centavos\n";
}

// Práctica: vamos a crear una clase Cuenta con un saldo que solo cambie mediante sus funciones.
// - Rechazamos depósitos negativos y retiros mayores que el saldo.
// - Añadimos una función const para consultar el saldo.
// - Mostramos el saldo después de un depósito y un retiro válidos.
