// Repetir con while
//
// Vamos a repetir mientras se cumpla una condición. Con while revisamos la condición antes de
// entrar: si ya es falsa, no hacemos ninguna vuelta. Podemos imaginar una alcancía a la que
// agregamos dinero mientras no alcanzamos la meta. Dentro del ciclo cambiamos el ahorro; si nunca
// cambiamos lo que revisamos, podríamos repetir para siempre.
//
// Práctica: Vamos a realizar un programa que simule un ahorro semanal.
//
// - Comenzar con un ahorro de 0.
// - Agregar 25 por semana hasta alcanzar al menos 110.
// - Contar las semanas y mostrar el ahorro después de cada una.
// - Mostrar por qué el resultado final puede superar la meta.

#include <iostream>

using namespace std;

int main() {
    int ahorro = 0;
    int semanas = 0;
    // La condición se revisa antes del bloque; semanas cuenta cuántos depósitos hacen falta.
    while (ahorro < 100) {
        ahorro += 25;
        ++semanas;
    }

    cout << semanas << " semanas\n";
}
