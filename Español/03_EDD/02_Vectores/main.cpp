#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Tarea {
    string nombre;
    bool terminada;
};

int main() {
    vector<Tarea> tareas{{"Leer", false}, {"Practicar", false}};
    tareas.insert(tareas.begin() + 1, {"Compilar", false});
    tareas.at(0).terminada = true;
    tareas.erase(tareas.begin());
    for (const auto& tarea : tareas) {
        cout << tarea.nombre << "\n";
    }
}
