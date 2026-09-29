// Vectores
//
// Vamos a reunir creación, cambios y fichas de objetos en una lista de tareas. Cada Tarea guarda su
// nombre y si ya terminó. Insertamos una tarea, marcamos otra y quitamos una ficha. Podemos
// imaginar una libreta donde agregamos y retiramos renglones. El vector mantiene juntos los datos,
// pero sus posiciones pueden cambiar al insertar o borrar; por eso no confundimos el nombre de una
// tarea con su posición actual.
//

#include <iostream>
// Guardamos y trabajamos con texto mediante string.
#include <string>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;

struct Tarea {
    string nombre;
    bool terminada;
};

int main() {
    vector<Tarea> tareas{{"Leer", false}, {"Practicar", false}};
    // Insertar en medio desplaza los elementos siguientes; el vector conserva su orden.
    tareas.insert(tareas.begin() + 1, {"Compilar", false});
    tareas.at(0).terminada = true;
    tareas.erase(tareas.begin());
    for (const auto& tarea : tareas) {
        cout << tarea.nombre << "\n";
    }
}
