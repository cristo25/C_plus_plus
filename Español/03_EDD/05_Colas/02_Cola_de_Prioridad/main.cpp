// Cola de prioridad y heap
//
// priority_queue utiliza un heap (montículo). Por defecto coloca el mayor arriba; con
// greater<int> coloca el menor. Consultar top cuesta O(1); insertar y retirar, O(log n). No
// conserva el orden de llegada entre prioridades iguales.
//
// Analogía: En urgencias se atiende por prioridad; la gravedad decide el siguiente turno.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Retira todos los valores de ambas colas. Explica por qué un heap no equivale a un
// vector completamente ordenado.

#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    priority_queue<int> gravedad;
    // greater cambia el criterio para poner el menor costo arriba, como una fila ordenada por
    // urgencia.
    priority_queue<int, vector<int>, greater<int>> costo;
    for (int dato : {2, 9, 4}) {
        gravedad.push(dato);
        costo.push(dato);
    }

    cout << "Mayor prioridad: " << gravedad.top() << "\n";
    cout << "Menor costo: " << costo.top() << "\n";
}
