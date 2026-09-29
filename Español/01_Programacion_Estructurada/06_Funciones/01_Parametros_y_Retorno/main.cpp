// Funciones: parámetros y retorno
//
// Una función recibe datos, realiza una tarea y puede devolver un resultado. Los parámetros por
// valor son copias: cambiarlos no modifica el original.
//
// Analogía: Una máquina recibe ingredientes por una entrada y entrega un producto por la salida.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Crea una función que convierta minutos a segundos.

#include <iostream>

using namespace std;

// La función recibe una copia del número y devuelve su cuadrado.
int cuadrado(int numero) {
    return numero * numero;
}

int main() {

    cout << cuadrado(4) << "\n";
}
