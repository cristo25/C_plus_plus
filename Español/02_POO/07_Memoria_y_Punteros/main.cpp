// Memoria y punteros en POO
//
// Relaciona propiedad con vida del objeto. El integrador administra un alumno con unique_ptr y
// lo consulta mediante un puntero que no es propietario.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe

#include <iostream>
#include <memory>
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
    // reset destruye el objeto. A partir de aquí el observador ya no se puede desreferenciar.
    propietario.reset();
    consulta = nullptr;
}
