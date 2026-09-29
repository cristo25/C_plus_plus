// Referencias y paso de parámetros
//
// int& es un alias del dato original. const string& permite consultar una cadena sin copiarla ni
// modificarla. Una referencia válida se inicializa al declararse.
//
// Analogía: Una referencia es una segunda etiqueta en la misma caja; no es otra caja.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Cambia el parámetro a int numero y observa por qué falla la comprobación.

#include <iostream>
#include <string>

using namespace std;

// Una referencia es otro nombre para la misma variable: ++ modifica el contador original.
void incrementar(int& numero) {
    ++numero;
}
// const string& permite consultar el texto sin copiarlo ni modificarlo.
size_t longitud(const string& texto) {
    return texto.size();
}

int main() {
    int contador = 4;
    incrementar(contador);

    cout << contador << "\n";
}
