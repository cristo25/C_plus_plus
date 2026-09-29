// El adaptador stack
//
// stack ofrece solo las operaciones de pila: push, top, pop, size, empty. pop elimina pero no
// devuelve el valor; consúltalo antes con top. El adaptador restringe las operaciones del
// contenedor subyacente.
//
// Analogía: Una caja de platos con una sola abertura arriba: no puedes tomar el plato de en
// medio.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Simula dos operaciones y dos acciones de deshacer; protege también el tercer
// intento.

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<string> historial;
    historial.push("Escribir");
    historial.push("Borrar");
    if (!historial.empty()) {

        // top consulta el último valor; pop lo elimina y no devuelve el dato.
        cout << "Deshacer: " << historial.top() << "\n";
        historial.pop();
    }
}
