// Crear y recorrer un vector
//
// vector es un arreglo contiguo cuyo tamaño puede cambiar. size() es la cantidad de elementos;
// capacity() es el espacio reservado. push_back cuesta O(1) amortizado, aunque una realocación
// individual cuesta O(n).
//
// Analogía: Es un cajón extensible: al llenarse, puede mudarse a un cajón mayor. Sus secciones
// siguen numeradas desde cero.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Usa reserve(10) y comprueba que cambia la capacidad, pero no agrega elementos.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numeros{10, 20};
    // Agrega una sección al cajón extensible. Una realocación puede mover todos sus elementos.
    numeros.push_back(30);
    int suma = 0;
    for (int numero : numeros) {
        suma += numero;
    }

    cout << "Suma: " << suma << "\n";
}
