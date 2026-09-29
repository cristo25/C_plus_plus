// Constructores, destructores y RAII
//
// El constructor establece un estado inicial válido y el destructor corre al terminar la vida
// del objeto. RAII vincula la vida de un recurso a la de un objeto; string, archivos y punteros
// inteligentes ya lo hacen.
//
// Analogía: Al abrir una tienda colocas el letrero; al cerrar recoges lo que administraba la
// tienda.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Construye dos sesiones en el mismo bloque y observa el orden inverso de destrucción.

#include <iostream>
#include <string>

using namespace std;

class Sesion {
    string usuario;

public:
    // El constructor inicializa el objeto; explicit evita conversiones implícitas inesperadas.
    explicit Sesion(const string& nombre) : usuario(nombre) {
        cout << "Entra " << usuario << "\n";
    }
    // El destructor se ejecuta automáticamente cuando termina la vida del objeto.
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
