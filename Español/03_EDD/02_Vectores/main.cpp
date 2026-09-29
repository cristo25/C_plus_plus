// Vectores
//
// Estudia tamaño, recorrido, modificación y objetos. El integrador organiza tareas, marca una y
// la elimina; quedan Compilar y Practicar.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe

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
    // Insertar en medio desplaza los elementos siguientes; el vector conserva su orden.
    tareas.insert(tareas.begin() + 1, {"Compilar", false});
    tareas.at(0).terminada = true;
    tareas.erase(tareas.begin());
    for (const auto& tarea : tareas) {
        cout << tarea.nombre << "\n";
    }
}
