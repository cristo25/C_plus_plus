// 3. Un arreglo de tarjetas para enteros
//
// Ahora el cajón contiene tarjetas: array<int*, 3>. Cada tarjeta puede señalar
// un entero que vive fuera del arreglo. El arreglo contiene los punteros,
// pero no es dueño de los enteros. *direcciones.at(0) sigue la primera tarjeta
// y modifica rojo; asignar direcciones.at(0) solo cambia esa tarjeta.
// nullptr deja un compartimento sin destino. Destruir las tarjetas no destruye
// las cajas y copiar las tarjetas conserva los mismos destinos.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
// Ejecutar: ./programa.exe
//
// Practica: Haz que dos tarjetas apunten a rojo y cambia rojo mediante una de ellas.

#include <array>
#include <iostream>

using namespace std;

int main() {
    int rojo = 2;
    int azul = 5;
    array<int*, 3> direcciones{&rojo, &azul, nullptr};

    // * cambia el entero de destino. rojo pasa de 2 a 7.
    *direcciones.at(0) = 7;
    // Sin * cambiamos la tarjeta. rojo sigue valiendo 7.
    direcciones.at(0) = &azul;
    for (const int* direccion : direcciones) {
        if (direccion != nullptr) {
            cout << *direccion << "\n";
        } else {
            cout << "Sin destino\n";
        }
    }
    cout << "Rojo conserva: " << rojo << "\n";
}
