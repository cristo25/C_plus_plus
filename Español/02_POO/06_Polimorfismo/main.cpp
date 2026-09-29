// Polimorfismo y clases abstractas
//
// Un método virtual permite elegir la implementación según el objeto real. = 0 define una
// operación abstracta y override verifica que la redefiniste correctamente. Una base polimórfica
// necesita destructor virtual si se destruyen derivados mediante ella.
//
// Analogía: El botón «hacer sonido» funciona con varios instrumentos; cada instrumento decide
// qué sonido producir.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Agrega Flauta y úsala con la misma función tocar. No cambies esa función.

#include <iostream>
#include <string>

using namespace std;

class Instrumento {
public:
    // Una base polimórfica usa destructor virtual para destruir correctamente sus objetos
    // derivados.
    virtual ~Instrumento() = default;
    virtual string sonar() const = 0;
};

class Guitarra : public Instrumento {
public:
    string sonar() const override {
        return "Cuerdas";
    }
};
class Tambor : public Instrumento {
public:
    string sonar() const override {
        return "Percusion";
    }
};

// La referencia evita copiar la base; virtual elige el sonido según el objeto real.
void tocar(const Instrumento& instrumento) {
    cout << instrumento.sonar() << "\n";
}

int main() {
    Guitarra guitarra;
    Tambor tambor;
    const Instrumento& instrumento = guitarra;

    tocar(instrumento);
    tocar(tambor);
}
