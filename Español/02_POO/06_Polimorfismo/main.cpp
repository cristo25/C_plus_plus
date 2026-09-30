// Polimorfismo y clases abstractas
//
// Vamos a pedir la misma acción a objetos diferentes. Con tocar pedimos que suene un Instrumento,
// pero una Guitarra y un Tambor responden de forma distinta. A eso lo llamamos polimorfismo. Con
// virtual permitimos que cada instrumento tenga su propia respuesta; con = 0 dejamos esa respuesta
// pendiente en la clase general; con override comprobamos que la nueva función corresponde a la que
// queremos reemplazar. Pasamos una referencia para usar el instrumento original. El destructor
// virtual permite limpiar el objeto completo si después lo eliminamos mediante un puntero a
// Instrumento.
//

#include <iostream>
// Guardamos y trabajamos con texto mediante string.
#include <string>

using namespace std;

class Instrumento {
public:
    // Con virtual podemos liberar el instrumento completo aunque lo tratemos como Instrumento.
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

// Práctica: vamos a crear una clase Bloque y dos clases que la representen de forma distinta.
// - Declaramos una función virtual para describir un bloque.
// - Hacemos que Piedra y Madera devuelvan descripciones diferentes.
// - Pasamos cada objeto por referencia a una misma función que muestre su descripción.
