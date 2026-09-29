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
    const Alumno* consulta = propietario.get();

    cout << consulta->consultarNombre() << "\n";
    propietario.reset();
    consulta = nullptr;
}
