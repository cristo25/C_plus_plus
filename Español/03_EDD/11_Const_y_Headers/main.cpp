// Const y headers en EDD
//
// Vamos a consultar una colección sin modificarla. Con const vector<int>& recibimos otra etiqueta
// del mismo vector, pero solo para leerlo. En Consultas.h anunciamos la función; en Consultas.cpp
// recorremos los datos y contamos los que superan un límite. No necesitamos copiar ni ordenar
// nada. Si duplicamos la cantidad de datos hacemos el doble de visitas. Solo añadimos un contador
// y unas pocas variables.
//
// Práctica: Vamos a consultar un vector desde un archivo separado.
// - Anunciemos en el header una función que reciba un vector sin cambiarlo.
// - Contemos en el archivo .cpp los valores menores que un límite.

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
