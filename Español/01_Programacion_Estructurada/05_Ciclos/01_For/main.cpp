// Repetir con for
//
// Vamos a repetir una tarea con for. Entre sus paréntesis indicamos dónde empieza el contador,
// cuándo seguimos y cómo cambia después de cada vuelta. Podemos imaginar cinco casilleros
// numerados: revisamos uno, avanzamos y repetimos hasta el último. ++ aumenta el contador en uno;
// las instrucciones entre llaves se ejecutan en cada vuelta.
//
// Practica: Realiza un programa que muestre la tabla del 7.
//
// - Usar un contador desde 1 hasta 10.
// - Calcular cada multiplicación dentro del for.
// - Mostrar cada operación y su resultado en una línea.

#include <iostream>

using namespace std;

int sumaHasta(int limite) {
    int suma = 0;
    // Empieza en 1, continúa hasta limite y aumenta numero después de cada vuelta.
    for (int numero = 1; numero <= limite; ++numero) {
        suma += numero;
    }
    return suma;
}

int main() {

    cout << sumaHasta(5) << "\n";
}
