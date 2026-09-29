// Ordenar con la biblioteca estándar
//
// sort ofrece O(n log n) comparaciones en el peor caso y no garantiza estabilidad. stable_sort
// conserva el orden de elementos equivalentes. El comparador debe expresar un orden estricto:
// usa <, no <=. Aprende los algoritmos manuales y usa la biblioteca para tareas habituales.
//
// Analogía: Encargas ordenar el cajón a una herramienta ya probada, indicándole cómo comparar
// sus objetos.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Ordena por nombre. Después ordena por nota descendente conservando el orden de los
// empates.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Alumno {
    string nombre;
    int nota;
};

int main() {
    vector<int> numeros{3, 1, 2};
    sort(numeros.begin(), numeros.end());

    vector<Alumno> grupo{{"Ana", 8}, {"Eva", 9}, {"Luis", 8}};
    // stable_sort conserva el orden original de los empates: Ana permanece antes que Luis.
    stable_sort(grupo.begin(), grupo.end(), [](const Alumno& a, const Alumno& b) {
        return a.nota < b.nota;
    });

    for (const auto& alumno : grupo) {
        cout << alumno.nombre << ": " << alumno.nota << "\n";
    }
}
