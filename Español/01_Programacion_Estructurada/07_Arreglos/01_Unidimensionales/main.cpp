// Arreglos unidimensionales
//
// Vamos a guardar varios enteros en un mismo cajón. Con int cajon[4] reservamos cuatro
// compartimentos del mismo tipo. Los contamos desde cero: cajon[0] es el primero y cajon[3] el
// último. Los corchetes nos permiten elegir una casilla; no comprueban por nosotros que exista, así
// que nunca usamos cajon[4]. Recorremos las casillas para sumar sus datos y después cambiamos la
// segunda. Este arreglo tiene un tamaño fijo y no necesita una biblioteca adicional.
//

// Práctica: Vamos a realizar un programa que trabaje con cinco calificaciones.
//
// - Guardarlas en un arreglo int notas[5].
// - Recorrer solo las posiciones de 0 a 4.
// - Calcular la suma y el promedio con decimales.
// - Mostrar la nota más alta.

#include <iostream>

using namespace std;

int main() {
    // Cajón de cuatro secciones para enteros: índices 0, 1, 2 y 3; su tamaño es fijo.
    int cajon[4]{10, 20, 30, 40};
    int suma = 0;
    for (int valor : cajon) {
        suma += valor;
    }
    // Con cajon[1] elegimos la segunda casilla, dentro del límite de cuatro. Ya calculamos la suma
    // antes de este cambio.
    cajon[1] = 25;

    cout << "Suma original: " << suma << "\n";
}
