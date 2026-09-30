// Herencia
//
// Vamos a describir una versión más específica de algo que ya tenemos. Una BicicletaElectrica sigue
// siendo una Bicicleta, pero también tiene batería. Con : public Bicicleta conservamos las
// operaciones públicas de la bicicleta y agregamos las propias. Llamamos herencia a esta relación.
// En asistir revisamos la batería antes de gastarla y pedalear. Nos conviene cuando podemos decir
// «es una»; para decir «tiene una parte» usamos la composición del tema anterior.
//

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
    if (!bici.asistir()) {
        return 1;
    }

    cout << "Velocidad: " << bici.consultarVelocidad() << "\n";
}

// Práctica: vamos a crear una clase Vehiculo y una clase AutoElectrico que herede de ella.
// - Damos al vehículo una función para avanzar.
// - Añadimos una batería al auto eléctrico y gastamos carga al usarla.
// - Mostramos el avance y la carga después de usar el auto.
