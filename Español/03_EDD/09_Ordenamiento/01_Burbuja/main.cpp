// Burbuja
//
// Compara vecinos y los intercambia si están invertidos. Cada pasada coloca el mayor restante al
// final. Con n datos, las pasadas comparan repetidamente muchos de los mismos vecinos: el trabajo
// puede crecer aproximadamente como n multiplicado por n (O(n²), tanto en promedio como en el peor
// caso). Si ya están ordenados, el indicador de cambios permite terminar tras una pasada por los n
// datos (O(n)). Solo necesita unas pocas variables adicionales, sin crear otro arreglo del tamaño
// de la entrada (O(1) de memoria adicional). Es estable. Lee su función en ../Ordenamientos.h.
//
// Analogía: Las burbujas grandes suben al extremo; cada pasada lleva el mayor número al final.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Dibuja cada pasada para los datos 4, 2, 3, 1.

#include "../Ordenamientos.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace curso;

int main() {
    vector<int> datos{5, -1, 3, 3, 0};
    // La función intercambia vecinos invertidos y deja el mayor restante al final de cada
    // pasada.
    burbuja(datos);

    for (int dato : datos) {
        cout << dato << ' ';
    }
    cout << "\n";
}
