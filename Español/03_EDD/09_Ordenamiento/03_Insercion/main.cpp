// Inserción
//
// Mantiene una zona izquierda ordenada e inserta cada dato nuevo desplazando los mayores. Cada dato
// nuevo puede obligarnos a desplazar muchos de los anteriores. Con n datos, ese trabajo repetido
// puede crecer como n multiplicado por n (O(n²), en promedio y en el peor caso). Si ya estaban
// ordenados, basta con avanzar por ellos una vez (O(n)). Usa unas pocas variables adicionales, sin
// otro arreglo del mismo tamaño (O(1) de memoria adicional). Es estable. Lee su función en
// ../Ordenamientos.h.
//
// Analogía: Ordenas una mano de cartas colocando cada carta nueva en su lugar entre las
// anteriores.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Traza los desplazamientos cuando insertas el 2 en 1, 3, 4.

#include "../Ordenamientos.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    vector<int> datos{5, -1, 3, 3, 0};
    // Como ordenar cartas: abre un lugar en la zona izquierda para cada dato nuevo.
    insercion(datos);

    for (int dato : datos) {
        cout << dato << ' ';
    }
    cout << "\n";
}
