// Una pila con vector
//
// Una pila sigue LIFO: el último que entra es el primero que sale. push_back, back y pop_back
// permiten implementarla; comprueba empty antes de consultar o sacar.
//
// Analogía: Una pila de platos: colocas uno arriba y retiras el de arriba.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Agrega tres elementos y retíralos con un ciclo hasta que quede vacía.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> pila;

    pila.push_back(10);
    pila.push_back(20);
    // Antes de consultar back o eliminar, comprobamos que exista una cima.
    if (!pila.empty()) {
        const int cima = pila.back();
        pila.pop_back();

        cout << "Sale: " << cima << "\n";
    }
}
