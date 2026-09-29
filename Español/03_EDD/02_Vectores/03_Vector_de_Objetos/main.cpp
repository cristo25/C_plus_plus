// Vectores de objetos
//
// Un vector puede guardar objetos del mismo tipo. Un struct tiene miembros públicos por defecto;
// en una class son privados por defecto. const auto& permite recorrer sin copiar ni modificar.
//
// Analogía: El cajón ahora guarda fichas completas: cada ficha tiene un nombre y una nota.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Calcula el promedio del grupo. Define qué hacer si el vector está vacío.

#include <iostream>
#include <string>
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
