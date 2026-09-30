// Matrices
//
// Vamos a pasar de un cajón a un mueble con varios cajones. En int mueble[2][3] tenemos dos filas y
// tres columnas. Primero elegimos la fila y después la casilla: mueble[1][2] es la tercera casilla
// de la segunda fila. Usamos un ciclo para las filas y otro para los datos de cada fila. Ambos
// recorridos empiezan en cero y se detienen antes de salir del mueble.
//

// Práctica: Vamos a realizar un programa que muestre una matriz de dos filas y tres columnas.
//
// - Guardar seis números en un arreglo con dos pares de corchetes.
// - Mostrar cada fila en una línea.
// - Calcular por separado la suma de cada fila.
// - No acceder a filas o columnas fuera del arreglo.

#include <iostream>

using namespace std;

int main() {
    // Un mueble con dos cajones y tres secciones por cajón: dos filas y tres columnas.
    int mueble[2][3]{{1, 2, 3}, {4, 5, 6}};
    // La referencia const recorre cada fila sin copiar sus elementos ni modificarla.
    for (const auto& fila : mueble) {
        for (int valor : fila) {
            cout << valor << ' ';
        }
        cout << "\n";
    }
}
