// Memoria y punteros en POO
//
// Imaginemos que Alumno es una caja con un nombre y consulta guarda la dirección de esa caja.
// Creamos al alumno con make_unique y pedimos su dirección prestada con get. Con
// consulta->consultarNombre() seguimos la dirección y leemos el nombre. Antes de llamar reset
// dejamos de usar la dirección prestada y ponemos consulta en nullptr. Después, reset libera al
// alumno. El puntero prestado nunca tiene que borrarlo.
//

#include <iostream>
// Usamos unique_ptr para liberar automáticamente el objeto que administra.
#include <memory>
// Guardamos y trabajamos con texto mediante string.
#include <string>

using namespace std;

class Alumno {
    string nombre;

public:
    explicit Alumno(const string& nombreInicial) : nombre(nombreInicial) {
    }
    const string& consultarNombre() const {
        return nombre;
    }
};

int main() {
    auto propietario = make_unique<Alumno>("Ana");
    // get devuelve un observador: el unique_ptr sigue siendo el dueño y libera el objeto.
    const Alumno* consulta = propietario.get();

    cout << consulta->consultarNombre() << "\n";
    // Dejamos de usar la dirección prestada antes de destruir el objeto con reset.
    consulta = nullptr;
    propietario.reset();
}

// Práctica: vamos a crear una clase Mascota y administrarla con unique_ptr.
// - Guardamos un nombre y lo consultamos con una función const.
// - Leemos el nombre mediante una dirección prestada por get.
// - Dejamos de usar esa dirección antes de liberar la mascota con reset.
