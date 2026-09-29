// Const y headers en programación estructurada
//
// const impide cambiar un dato desde su declaración. Las notas y el promedio de este ejemplo no
// cambian, por eso son constantes. const array<int, 3>& permite consultar las notas sin
// copiarlas ni modificarlas. constexpr indica que un valor puede evaluarse en compilación; las
// constantes inline constexpr del header se pueden compartir entre archivos de implementación.
// Calificaciones.h declara las funciones y sus constantes. Calificaciones.cpp define las
// operaciones. main.cpp organiza la ejecución. No hace falta una clase para dividir un programa
// en archivos.
//
// Analogía: El header es una ficha de instrucciones: dice qué servicio puedes pedir. El .cpp
// realiza el trabajo. const pone una vitrina sobre el cajón: puedes ver sus notas sin moverlas.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Calificaciones.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Intenta cambiar una nota después de declararla: el compilador rechazará la
// asignación. Luego cambia sus valores en la declaración a {4, 5, 6} y observa Reprobado.
// Declara y define una función que encuentre la nota más alta sin modificar el arreglo.

#include "Calificaciones.h"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace curso;

int main() {
    // Las notas se fijan al declararlas; calcularPromedio recibe una referencia de solo lectura.
    const array<int, 3> notas{8, 9, 10};
    try {
        // La declaración está en el .h y el trabajo se define en el otro .cpp.
        const double promedio = calcularPromedio(notas);
        cout << "Promedio: " << promedio << "\n";
        if (estaAprobado(promedio)) {
            cout << "Aprobado\n";
        } else {
            cout << "Reprobado\n";
        }
    } catch (const invalid_argument& error) {
        cerr << error.what() << "\n";
        return 1;
    }
}
