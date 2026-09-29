// Tablas hash con unordered_map
//
// unordered_map asocia claves únicas con valores mediante una función hash. La función hash orienta
// la consulta hacia un grupo de entradas. En promedio, buscar o insertar necesita una cantidad de
// pasos que no crece con el total de entradas (O(1)). Si muchas claves caen en el mismo grupo, una
// operación puede tener que revisar las n entradas de la tabla (O(n) en el peor caso). La
// biblioteca administra las colisiones; el orden de recorrido no está garantizado. operator[] puede
// insertar: usa find para solo consultar.
//
// Analogía: Un recepcionista transforma una clave en el número de un casillero. Si varias claves
// coinciden, debe distinguir sus fichas.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Intenta insertar dos veces la misma clave con emplace y revisa el valor booleano del
// resultado.

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, string> alumnos;
    alumnos.emplace(101, "Ana");
    alumnos.emplace(102, "Luis");
    // find consulta sin insertar una clave nueva; aquí sabemos que 101 existe porque se agregó
    // antes.
    auto encontrado = alumnos.find(101);
    cout << encontrado->second << "\n";
    if (!(alumnos.erase(102) == 1 && alumnos.size() == 1)) {
        return 1;
    }
}
