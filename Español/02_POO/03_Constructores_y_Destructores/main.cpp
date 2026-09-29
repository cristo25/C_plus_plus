#include <iostream>
#include <string>

using namespace std;

class Sesion {
    string usuario;

public:
    explicit Sesion(const string& nombre) : usuario(nombre) {
        cout << "Entra " << usuario << "\n";
    }
    ~Sesion() {
        cout << "Sale " << usuario << "\n";
    }
    const string& nombre() const {
        return usuario;
    }
};

int main() {
    {
        Sesion sesion("Ana");

    } // Aqui termina la vida de sesion.
    cout << "Sesion terminada\n";
}
