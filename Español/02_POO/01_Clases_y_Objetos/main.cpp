// Clases y objetos
//
// Vamos a reunir datos y acciones que pertenecen a una misma cosa. Podemos imaginar una clase como
// el molde de un bloque de Minecraft: indica qué datos tiene y qué puede hacer cada bloque creado
// con ese molde. Cada bloque concreto sería un objeto. En este programa usamos Bicicleta: guardamos
// color y velocidad, y con pedalear aumentamos la velocidad. Creamos roja y azul por separado;
// pedalear con roja no cambia azul. Llamamos atributos a esos datos y métodos a las funciones que
// escribimos dentro de la clase. Con public permitimos usarlos desde main.
//

#include <iostream>
// Guardamos y trabajamos con texto mediante string.
#include <string>

using namespace std;

// La clase es el molde; cada objeto tendrá su propio color y velocidad.
class Bicicleta {
// Empezamos permitiendo consultar y cambiar estos datos; después aprenderemos a protegerlos.
public:
    string color;
    int velocidad = 0;
    void pedalear() {
        velocidad += 5;
    }
};

int main() {
    Bicicleta roja;
    roja.color = "roja";
    Bicicleta azul;
    azul.color = "azul";
    roja.pedalear();

    cout << "Bicicleta " << roja.color << ": " << roja.velocidad << "\n";
    cout << "Bicicleta " << azul.color << ": " << azul.velocidad << "\n";
}

// Práctica: vamos a crear una clase Bloque para representar dos bloques de Minecraft.
// - Guardamos el nombre y la dureza de cada bloque.
// - Añadimos una función que reduzca la dureza al golpearlo.
// - Mostramos que golpear un bloque no cambia el otro.
