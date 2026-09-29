// Complejidad: tiempo y espacio
//
// Vamos a comparar cuánto trabajo hacemos cuando aumentan los datos. Llegar directamente a una
// casilla requiere una cantidad fija de pasos, aunque haya más casillas (O(1); no significa
// exactamente un paso). Revisar diez casillas implica diez visitas y revisar veinte implica veinte
// (O(n), donde n es la cantidad de casillas). Si vamos dividiendo por la mitad, de 8 a 1 hacemos
// tres divisiones y de 16 a 1 hacemos cuatro (O(log n), donde log n describe ese crecimiento por
// mitades). Llamamos notación O grande a estas abreviaturas: describen crecimiento, no segundos
// exactos. También podemos contar cuántos datos adicionales guardamos para hacer la tarea; a eso lo
// llamamos memoria auxiliar.
//

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
