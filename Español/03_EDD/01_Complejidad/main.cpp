// Complejidad: tiempo y espacio
//
// Big O describe cómo crece el trabajo con el tamaño de la entrada, no los segundos exactos.
// Acceder por índice es O(1); recorrer n elementos es O(n); reducir el problema a la mitad
// repetidamente requiere O(log n) pasos. También cuenta la memoria adicional.
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
        // Cada vuelta divide el problema por dos: 1024 llega a 1 en diez pasos, crecimiento
        // O(log n).
        n /= 2;
        ++pasos;
    }
    return pasos;
}

int main() {
    cout << "Recorrido de 1024 elementos: 1024 visitas\n";
    cout << "Dividir 1024 hasta 1: " << pasosMitad(1024) << " pasos\n";
}
