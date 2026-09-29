// Vectores de objetos
//
// Vamos a guardar fichas completas dentro del vector. Con struct Alumno reunimos un nombre y una
// nota, como dos casillas de una misma ficha. vector<Alumno> guarda esas fichas y push_back agrega
// otra. Con const auto& leemos cada ficha sin copiarla: auto permite que C++ deduzca el tipo, & nos
// da otra etiqueta del mismo objeto y const impide cambiarlo mediante esa etiqueta. Usamos el punto
// para elegir un dato de la ficha.
//

#include <iostream>
// Guardamos y trabajamos con texto mediante string.
#include <string>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;

struct Alumno {
    string nombre;
    int nota;
};

int main() {
    vector<Alumno> grupo{{"Ana", 9}, {"Luis", 8}};
    grupo.push_back({"Eva", 10});

    // Consultamos cada ficha completa por referencia const, sin copiar nombres ni modificar
    // notas.
    for (const auto& alumno : grupo) {
        cout << alumno.nombre << ": " << alumno.nota << "\n";
    }
}
