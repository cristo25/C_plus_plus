// Tu primer programa
//
// #include incorpora declaraciones de la biblioteca estándar; main es el punto de entrada y cout
// escribe en la consola. El programa termina con código 0 cuando todo va bien.
//
// Analogía: El programa es una receta. main indica dónde comienza el cocinero y cada instrucción
// es un paso.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Cambia el saludo por tu nombre. Agrega una segunda línea.

#include <iostream>

// Permite escribir cout sin el prefijo del namespace estándar.
using namespace std;

// La ejecución empieza en main; devolver 0 indica que terminó correctamente.
int main() {
    cout << "Hola, C++!\n";
    return 0;
}
