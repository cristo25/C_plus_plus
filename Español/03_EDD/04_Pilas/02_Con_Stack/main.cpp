// El adaptador stack
//
// Vamos a usar stack, la herramienta de <stack> que ofrece directamente las operaciones de una
// pila. push agrega arriba, top permite leer la cima y pop la retira. Podemos imaginar un historial
// para deshacer: la última acción que hicimos es la primera que revisamos. Aquí mostramos qué
// acción se desharía; retirarla del historial no modifica por sí sola un documento real.
//
// Práctica: Vamos a usar stack para guardar acciones.
// - Agreguemos tres acciones con push.
// - Consultemos top antes de usar pop y mostremos qué acción salió.

#include <iostream>
// Guardamos una pila: con stack sale primero lo último que entró.
#include <stack>
// Guardamos y trabajamos con texto mediante string.
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
