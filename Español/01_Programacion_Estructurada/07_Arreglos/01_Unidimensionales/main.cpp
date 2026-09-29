// Arreglos unidimensionales
//
// array<int, 4> guarda cuatro enteros contiguos. El tamaño es fijo y los índices van de 0 a 3.
// at() comprueba el índice; [] requiere que tú garantices que sea válido. Un arreglo tradicional
// se escribe int datos[4], pero no ofrece at().
//
// Analogía: Un arreglo es un cajón para un solo tipo de cosas, dividido en secciones numeradas
// desde cero. No cabe una quinta cosa en un cajón de cuatro secciones.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Crea un cajón de cinco calificaciones y calcula su promedio con división decimal.

#include <array>
#include <iostream>

using namespace std;

int main() {
    // Cajón de cuatro secciones para enteros: índices 0, 1, 2 y 3; su tamaño es fijo.
    array<int, 4> cajon{10, 20, 30, 40};
    int suma = 0;
    for (int valor : cajon) {
        suma += valor;
    }
    // at(1) es la segunda sección y comprueba el índice. La suma ya se calculó antes del cambio.
    cajon.at(1) = 25;

    cout << "Suma original: " << suma << "\n";
}
