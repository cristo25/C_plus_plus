// Memoria dinámica manual
//
// new construye un objeto dinámico y delete lo destruye. Debe existir exactamente un propietario
// responsable de liberarlo. Para arreglos creados con new[] corresponde delete[]. En código
// habitual usa objetos por valor, vector o punteros inteligentes.
//
// Analogía: Alquilas un casillero: conservas la dirección y debes devolverlo una vez. Devolverlo
// dos veces o visitarlo después es un error.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Dibuja cuándo empieza y termina la vida del entero. No lo leas después de delete.

#include <iostream>

using namespace std;

int main() {
    // new reserva un entero y devuelve su dirección; este ejemplo asume la liberación manual.
    int* numero = new int(42);

    cout << *numero << "\n";
    // Liberamos una sola vez la memoria reservada con new; el puntero deja de referir un objeto
    // vivo.
    delete numero;
    numero = nullptr; // Evita reutilizar esta direccion por accidente.
}
