// Const, headers y compilación de varios archivos
//
// Producto.h declara la clase; Producto.cpp define sus métodos; main.cpp la utiliza. Las guardas
// #ifndef evitan incluir la misma declaración dos veces. Cada .cpp se compila y el enlazador
// reúne el resultado. Incluye el .h, nunca el .cpp.
//
// Analogía: El header es la carta del restaurante: explica qué puedes pedir. El .cpp es la
// cocina y main hace el pedido.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Producto.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Agrega una consulta de precio con descuento. Declárala en el header y defínela en
// Producto.cpp.
// Los headers usan namespace curso { using namespace std; ... }; los .cpp importan curso para
// acceder a sus declaraciones. Así el header no agrega nombres estándar al namespace global del
// archivo que lo incluye.

#include "Producto.h"
#include <iostream>

using namespace std;
using namespace curso;

int main() {
    // Un objeto const solo permite llamar métodos que respeten su estado, como estas consultas.
    const Producto cuaderno("Cuaderno", 1250);

    cout << cuaderno.consultarNombre() << ": " << cuaderno.consultarPrecio() << " centavos\n";
}
