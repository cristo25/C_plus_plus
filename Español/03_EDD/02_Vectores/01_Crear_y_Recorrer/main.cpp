// Crear y recorrer un vector
//
// vector es un arreglo contiguo cuyo tamaño puede cambiar. size() es la cantidad de elementos;
// capacity() es el espacio reservado. Al agregar al final con push_back, normalmente basta con
// ocupar una casilla libre. Si se llena el espacio reservado, el vector necesita otro bloque y
// trasladar sus elementos: esa inserción puede recorrer los n elementos existentes (O(n)). Al
// repartir esas ampliaciones entre muchas inserciones, el trabajo por inserción queda acotado por
// una cantidad constante; a eso se le llama costo amortizado (O(1) amortizado).
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
