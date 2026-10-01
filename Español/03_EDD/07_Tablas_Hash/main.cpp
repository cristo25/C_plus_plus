// Tablas hash con unordered_map
//
// Vamos a buscar por una clave, como encontrar una ficha de alumno por su matrícula. unordered_map
// relaciona una clave con un dato; aquí un número con un nombre. Por dentro usa una función hash,
// que calcula en qué grupo buscar la clave. Con find buscamos sin crear una ficha; si obtenemos
// end(), no existe. En la ficha encontrada, first es la clave y second el dato. No esperamos que
// sus fichas aparezcan ordenadas. Habitualmente revisamos pocas entradas, pero si muchas claves
// caen juntas podemos tener que revisar muchas.
//
// Práctica: Vamos a consultar alumnos por matrícula.
// - Guardemos tres matrículas y nombres en unordered_map.
// - Busquemos una matrícula existente y otra ausente sin crear fichas nuevas.

#include <iostream>
// Guardamos y trabajamos con texto mediante string.
#include <string>
// Relacionamos una clave con un dato para buscar, como matrícula y nombre.
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, string> alumnos;
    // Con [101] elegimos la ficha 101; si falta, la creamos y guardamos el nombre.
    alumnos[101] = "Ana";
    alumnos[102] = "Luis";
    // find consulta sin insertar una clave nueva; aquí sabemos que 101 existe porque se agregó
    // antes.
    auto encontrado = alumnos.find(101);
    cout << encontrado->second << "\n";
    if (!(alumnos.erase(102) == 1 && alumnos.size() == 1)) {
        return 1;
    }
}
