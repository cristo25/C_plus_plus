// Const y headers en EDD
//
// Una consulta de una estructura puede recibir const vector<int>&: usa sus elementos sin copiar
// ni cambiar el vector. El vector y el resultado del ejemplo son const. El header declara la
// operación y una constante inline constexpr; el .cpp define el algoritmo con count_if y
// main.cpp lo usa. La consulta cuesta O(n) y requiere O(1) de memoria auxiliar.
// Los ejemplos de listas, árboles y grafos ya tienen headers con clases y operaciones. Aquí se
// muestra la separación entre declaración e implementación para una consulta. Comparar esta
// firma con un ordenamiento que recibe vector<int>& ayuda a distinguir lectura y modificación.
//
// Analogía: Una consulta es revisar el cajón a través de una vitrina: cuentas los objetos sin
// cambiar su posición. Ordenar el cajón sí exige abrirlo y moverlos.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Consultas.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Agrega una consulta para contar valores menores sin modificar los datos. Prueba un
// vector vacío y verifica que dé 0. Intenta ordenar el vector const y observa el error del
// compilador; para ordenarlo debes crear una copia mutable.

#include "Consultas.h"
#include <iostream>

using namespace std;
using namespace curso;

int main() {
    const vector<int> datos{9, 4, 10, 6};
    // La consulta recibe const vector<int>&: cuenta sin copiar ni modificar los datos.
    const size_t cantidad = contarMayores(datos, LIMITE_DE_EJEMPLO);
    cout << "Valores mayores a " << LIMITE_DE_EJEMPLO << ": " << cantidad << "\n";
    for (const int dato : datos) {
        cout << dato << ' ';
    }
    cout << "\n";
}
