// Leer y escribir archivos
//
// Vamos a conservar texto cuando termine el programa. Podemos pensar en la memoria como un pizarrón
// y en un archivo como un cuaderno que guardamos. Con ofstream abrimos el cuaderno para escribir;
// con ifstream lo abrimos para leer. Ambas herramientas vienen de <fstream>. Usamos ios::app para
// agregar líneas al final sin borrar las anteriores. Comprobamos que cada archivo se pudo abrir y
// leemos una línea por vuelta: cuando ya no hay otra, el ciclo termina.
//
// Práctica: Vamos a llevar un diario de estudio.
//
// - Agregar una actividad al final de un archivo.
// - Leer el archivo y mostrar todas las actividades.
// - Avisar si no se puede abrir para escribir o leer.

#include <iostream>

// Con fstream podemos escribir y leer archivos.
#include <fstream>

// Con string guardamos la ruta y cada línea leída.
#include <string>

using namespace std;

int main() {
    const string ruta = "notas_demo.txt";

    // Con ios::app agregamos una línea sin borrar las anteriores.
    {
        ofstream salida(ruta, ios::app);
        if (!salida) {
            cerr << "No se pudo abrir el archivo para escribir.\n";
            return 1;
        }

        salida << "Estudiar C++\n";
        // Al salir de este bloque, el archivo se cierra solo.
    }

    // Abrimos el mismo archivo para leerlo.
    ifstream entrada(ruta);
    if (!entrada) {
        cerr << "No se pudo abrir el archivo para leer.\n";
        return 1;
    }

    string linea;
    // getline lee línea por línea y el bucle termina por sí solo al llegar al final del archivo.
    while (getline(entrada, linea)) {
        cout << linea << "\n";
    }

    // Al terminar el programa, el archivo también se cierra solo.
    return 0;
}
