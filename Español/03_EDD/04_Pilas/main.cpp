// Pilas
//
// Vamos a comparar una pila construida con vector con otra de tipo stack. Introducimos 1, 2 y 3 en
// ambas y retiramos por el extremo superior. En las dos debe salir primero el 3. La idea que
// estamos practicando es el orden de salida; una pila se reconoce por esa regla, aunque usemos
// herramientas distintas para guardarla.
//
// Práctica: Vamos a comparar dos pilas de acciones.
// - Guardemos las mismas acciones con vector y con stack.
// - Retirémoslas y comprobemos que salga primero la última.

#include <iostream>
// Guardamos una pila: con stack sale primero lo último que entró.
#include <stack>
// Guardamos una colección que puede crecer con vector.
#include <vector>

using namespace std;

int main() {
    vector<int> manual;
    stack<int> adaptador;
    for (int dato : {1, 2, 3}) {
        manual.push_back(dato);
        adaptador.push(dato);
    }
    // Ambas pilas retiran por el extremo superior: último en entrar, primero en salir.
    while (!manual.empty()) {
        cout << manual.back() << ' ';
        manual.pop_back();
        adaptador.pop();
    }
    cout << "\n";
}
