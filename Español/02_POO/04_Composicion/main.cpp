// Composición
//
// Un objeto puede contener otro: la relación es «tiene un». El miembro se construye antes del
// cuerpo del constructor del objeto que lo contiene.
//
// Analogía: Un automóvil tiene un motor; no es un tipo de motor.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Agrega un método para apagar el motor a través del automóvil.

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

    cout << "Motor encendido\n";
}
