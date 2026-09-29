// Herencia
//
// Una clase derivada reutiliza una base cuando existe una relación «es un». La herencia pública
// conserva esa relación para el usuario de la clase. Prefiere composición cuando la relación sea
// «tiene un».
//
// Analogía: Una bicicleta eléctrica sigue siendo una bicicleta y añade una batería.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Consume la batería con un ciclo y verifica que no baje de cero.

#include <iostream>

using namespace std;

class Bicicleta {
    int velocidad = 0;

public:
    void pedalear() {
        velocidad += 5;
    }
    int consultarVelocidad() const {
        return velocidad;
    }
};

// Herencia: una bicicleta eléctrica ES una bicicleta y reutiliza sus operaciones públicas.
class BicicletaElectrica : public Bicicleta {
    int bateria = 100;

public:
    bool asistir() {
        if (bateria < 10) {
            return false;
        }
        bateria -= 10;
        pedalear();
        return true;
    }
    int carga() const {
        return bateria;
    }
};

int main() {
    BicicletaElectrica bici;
    if (!(bici.asistir())) {
        return 1;
    }

    cout << "Velocidad: " << bici.consultarVelocidad() << "\n";
}
