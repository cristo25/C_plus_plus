// Insertar y eliminar en vectores
//
// insert y erase reciben iteradores. begin() apunta al primer elemento y end() representa el límite
// posterior al último, que no se desreferencia. Insertar o borrar en medio obliga a desplazar los
// elementos que quedan después. Cuantos más haya que mover, más trabajo; en el peor caso pueden ser
// casi todos (O(n), donde n es la cantidad de elementos del vector). Una realocación invalida todos
// los punteros, referencias e iteradores; un borrado invalida desde la posición eliminada.
//
// Analogía: Para abrir un hueco en medio del cajón debes mover las cosas de las secciones
// siguientes.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Elimina todos los elementos iguales a 20 con remove y erase. Consulta la diferencia
// entre mover al final y borrar.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numeros{10, 30};
    // begin() + 1 es la posición del segundo elemento: queda 10, 20, 30.
    numeros.insert(numeros.begin() + 1, 20);

    // erase mueve los siguientes elementos; no reutilices iteradores invalidados por el borrado.
    numeros.erase(numeros.begin());

    if (!numeros.empty()) {
        numeros.pop_back();
    }

    cout << numeros.at(0) << "\n";
}
