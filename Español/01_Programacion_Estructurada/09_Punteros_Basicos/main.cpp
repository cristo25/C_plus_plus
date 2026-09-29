// Punteros: dirección y contenido
//
// &dato obtiene una dirección; int* guarda una dirección de un entero y *puntero accede al
// contenido. nullptr representa la ausencia de un destino. El dato debe seguir vivo mientras lo
// usas mediante un puntero. Todavía no necesitas new.
//
// Analogía: La variable es una casa; el puntero es un papel con su dirección. & anota la
// dirección y * visita la casa. Una dirección no garantiza que la casa siga existiendo.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Crea dos punteros al mismo entero y comprueba que ambos observan los cambios.

#include <iostream>

using namespace std;

int main() {
    int caja = 10;
    // & obtiene la dirección de caja; el puntero permite localizar ese mismo entero.
    int* direccion = &caja; // No es propietario: caja administra su propia vida.
    // * accede al contenido: cambiarlo mediante el puntero también cambia caja.
    *direccion = 25;

    int* sinDestino = nullptr;
    // nullptr significa sin destino; nunca leas el contenido de un puntero nulo.
    if (sinDestino != nullptr) {
        cout << *sinDestino << "\n";
    }
    cout << "Contenido: " << *direccion << "\n";
}
