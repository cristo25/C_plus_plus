// Recursión
//
// Vamos a resolver una tarea llamando a la misma función con un caso más pequeño; a eso lo llamamos
// recursión. Aquí calculamos el factorial: 4! significa 4 por 3 por 2 por 1. En factorial(n)
// multiplicamos n por el resultado de factorial(n - 1). Detenemos las llamadas cuando n es 0 o 1,
// cuyo resultado es 1. Podemos imaginar cajas dentro de cajas: abrimos hasta la más pequeña y
// después regresamos reuniendo resultados. Limitamos n a 12 para que el resultado quepa en int. Con
// throw avisamos de un dato inválido; con try y catch recogemos ese aviso para mostrarlo.
//

#include <iostream>
// Avisamos de errores con mensajes, por ejemplo invalid_argument para un dato inválido.
#include <stdexcept>

using namespace std;

int factorial(int n) {
    if (n < 0 || n > 12) {
        throw invalid_argument("Usa un numero entre 0 y 12");
    }
    // Caso base: 0! y 1! valen 1. Sin un caso que termine, la recursión no se detendría.
    if (n <= 1) {
        return 1;
    }
    // Cada llamada resuelve un problema menor; al regresar se multiplican los resultados.
    return n * factorial(n - 1);
}

int main() {
    try {
        cout << factorial(5) << "\n";
    } catch (const invalid_argument& error) {
        cerr << error.what() << "\n";
        return 1;
    }
}
