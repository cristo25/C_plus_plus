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
