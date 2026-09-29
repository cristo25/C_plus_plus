// Memoria y punteros en POO
//
// Vamos a aplicar los punteros a un objeto Alumno. Creamos el alumno con make_unique y prestamos su
// dirección con get. Con consulta->consultarNombre() seguimos esa dirección y llamamos a una
// función del alumno; -> equivale a seguir el puntero y usar el punto. Cuando llamamos reset
// liberamos el alumno. A partir de ese momento la dirección prestada deja de servir: debemos dejar
// de usarla y ponerla en nullptr. El puntero prestado nunca es responsable de borrar el alumno.
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
    // reset destruye el objeto. A partir de aquí el observador ya no se puede seguir esa dirección
    // para leer el dato.
    propietario.reset();
    consulta = nullptr;
}
