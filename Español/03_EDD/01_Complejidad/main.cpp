// Complejidad: tiempo y espacio
//
// Para comparar programas, imagina que la cantidad de datos crece. Llegar directamente a una
// casilla por su índice requiere una cantidad fija de pasos, aunque haya más casillas (se escribe
// O(1); no significa exactamente un paso). Revisar todas las casillas sí aumenta el trabajo: con 20
// visitas hacemos el doble que con 10 (O(n), donde n es la cantidad de elementos). Si reducimos lo
// pendiente a la mitad, pasar de 8 a 1 requiere tres divisiones y de 16 a 1 requiere cuatro
// (O(log n); aquí log n representa ese crecimiento por divisiones). Estas abreviaturas se llaman
// notación O grande y describen cómo puede crecer el trabajo, sin indicar segundos exactos. También
// podemos contar cuántos datos adicionales necesita guardar el programa: eso es la memoria
// auxiliar.
//
// Analogía: Buscar un cajón por número es directo; revisar todas las secciones tarda más cuando
// el mueble crece; partir una guía ordenada por la mitad descarta muchas páginas a la vez.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Compara n = 8, 16 y 32. Dibuja el crecimiento de n y del número de divisiones.

#include <iostream>

using namespace std;

int pasosMitad(int n) {
    int pasos = 0;
    while (n > 1) {
        // Cada vuelta reduce lo pendiente a la mitad: 1024 llega a 1 en diez divisiones. Si
        // empezamos con el doble, 2048, basta una división más (crecimiento O(log n), con n como
        // cantidad inicial).
        n /= 2;
        ++pasos;
    }
    return pasos;
}

int main() {
    cout << "Recorrido de 1024 elementos: 1024 visitas\n";
    cout << "Dividir 1024 hasta 1: " << pasosMitad(1024) << " pasos\n";
}
