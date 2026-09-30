// Composición
//
// Vamos a construir una cosa usando otra como parte. Un Auto tiene un Motor; por eso guardamos un
// objeto Motor dentro de Auto. A esta relación la llamamos composición. Desde main pedimos que
// arranque el auto, y el auto se encarga de encender su motor. Podemos imaginar un bloque que
// contiene un inventario: tener una parte no significa ser esa parte. Al terminar el auto también
// termina el motor que contiene.
//

#include <iostream>

using namespace std;

class Motor {
    bool encendido = false;

public:
    void encender() {
        encendido = true;
    }
    bool estaEncendido() const {
        return encendido;
    }
};

class Auto {
    // Composición: un Auto TIENE un Motor. Su vida está ligada a la del auto.
    Motor motor;

public:
    void arrancar() {
        motor.encender();
    }
    bool enMarcha() const {
        return motor.estaEncendido();
    }
};

int main() {
    Auto autoRojo;

    autoRojo.arrancar();

    if (autoRojo.enMarcha()) {
        cout << "Motor encendido\n";
    }
}

// Práctica: vamos a crear un Cofre que tenga un Inventario como parte.
// - Guardamos la cantidad de objetos dentro de Inventario.
// - Desde Cofre añadimos un objeto al inventario.
// - Mostramos la cantidad antes y después de añadirlo.
