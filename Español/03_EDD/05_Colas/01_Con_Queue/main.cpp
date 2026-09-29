// Cola FIFO
//
// queue atiende en orden de llegada: first in, first out. Agrega con push, consulta con front y
// elimina con pop. Comprueba empty antes de consultar.
//
// Analogía: La fila de las tortillas: se atiende primero a quien llegó primero.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Agrega una tercera persona y verifica el orden.

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<string> fila;
    fila.push("Ana");
    fila.push("Luis");

    // La persona al frente llegó primero; consultar y retirar requieren una cola no vacía.
    while (!fila.empty()) {
        cout << "Atender: " << fila.front() << "\n";
        fila.pop();
    }
}
