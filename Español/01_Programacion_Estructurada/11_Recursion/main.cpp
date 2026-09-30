// Recursión
//
// Vamos a resolver una tarea llamando a la misma función con un caso más pequeño; a eso lo llamamos
// recursión. Aquí calculamos el factorial: 4! significa 4 por 3 por 2 por 1. En factorial(n)
// multiplicamos n por el resultado de factorial(n - 1). Detenemos las llamadas cuando n es 0 o 1,
// cuyo resultado es 1. Podemos imaginar cajas dentro de cajas: abrimos hasta la más pequeña y
// después regresamos reuniendo resultados. Antes de llamar a factorial comprobamos que el número
// esté entre 0 y 12, para que el resultado quepa en int.
//

// Práctica: Vamos a realizar un programa que calcule una suma mediante recursión.
//
// - Crear una función para sumar desde 1 hasta n.
// - Definir un caso que termine sin otra llamada.
// - Usar un valor menor en cada llamada.
// - Probar 0, 1 y 5 y explicar cómo vuelve el resultado.

#include <iostream>

using namespace std;

int factorial(int n) {
    // Caso base: 0! y 1! valen 1. Sin un caso que termine, la recursión no se detendría.
    if (n <= 1) {
        return 1;
    }
    // Cada llamada resuelve un problema menor; al regresar se multiplican los resultados.
    return n * factorial(n - 1);
}

int main() {
    const int numero = 5;
    if (numero < 0 || numero > 12) {
        cerr << "Usa un numero entre 0 y 12.\n";
        return 1;
    }
    cout << factorial(numero) << "\n";
}
