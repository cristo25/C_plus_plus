// Const y headers en EDD
//
// Vamos a consultar una colección sin modificarla. Con const vector<int>& recibimos otra etiqueta
// del mismo vector, pero solo para leerlo. En Consultas.h anunciamos la función; en Consultas.cpp
// recorremos los datos y contamos los que superan un límite. No necesitamos copiar ni ordenar nada.
// Si duplicamos la cantidad de datos hacemos el doble de visitas (O(n), con n elementos). Solo
// añadimos un contador y unas pocas variables (O(1) de memoria adicional).
//

#include "Consultas.h"
#include <iostream>

using namespace std;
using namespace curso;

int main() {
    const vector<int> datos{9, 4, 10, 6};
    // La consulta recibe const vector<int>&: cuenta sin copiar ni modificar los datos.
    const size_t cantidad = contarMayores(datos, LIMITE_DE_EJEMPLO);
    cout << "Valores mayores a " << LIMITE_DE_EJEMPLO << ": " << cantidad << "\n";
    for (const int dato : datos) {
        cout << dato << ' ';
    }
    cout << "\n";
}
