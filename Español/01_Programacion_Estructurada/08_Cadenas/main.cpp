// Cadenas con string
//
// string administra una secuencia de caracteres. Puedes concatenar, consultar el tamaño, buscar
// y extraer fragmentos. Comprueba string::npos antes de usar un resultado de búsqueda.
//
// Analogía: Una cadena es un collar: cada carácter es una cuenta; puedes unir collares o tomar
// un tramo.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Busca una palabra que no exista y evita llamar substr con npos.
// El fragmento encontrado se muestra en otra línea: Ana.

#include <iostream>
#include <string>

using namespace std;

int main() {
    string nombre = "Ana";
    string saludo = "Hola, " + nombre;
    // find devuelve el índice del texto encontrado, o string::npos cuando no existe.
    auto posicion = saludo.find(nombre);

    cout << saludo << "\n";
    if (posicion != string::npos) {
        // Solo extraemos la subcadena después de comprobar que hubo una coincidencia.
        cout << saludo.substr(posicion) << "\n";
    }
}
