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
