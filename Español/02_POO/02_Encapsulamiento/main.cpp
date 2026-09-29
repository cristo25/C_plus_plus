// Encapsulamiento y const
//
// private protege el estado. Los métodos públicos controlan cambios válidos; los métodos const
// consultan sin modificar el objeto. No necesitas un getter y un setter por cada atributo.
//
// Analogía: Una alcancía no deja meter la mano directamente: sus operaciones controlan cómo
// entra y sale el dinero.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Comprueba que no puedes acceder a saldo directamente desde main. Prueba retirar
// cero.

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
