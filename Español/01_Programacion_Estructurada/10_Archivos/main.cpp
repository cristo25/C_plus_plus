// Leer y escribir archivos
//
// Vamos a conservar texto cuando termine el programa. Podemos pensar en la memoria como un pizarrón
// y en un archivo como un cuaderno que guardamos. Con ofstream abrimos el cuaderno para escribir;
// con ifstream lo abrimos para leer. Ambas herramientas vienen de <fstream>. Usamos ios::app para
// agregar líneas al final sin borrar las anteriores. Comprobamos que se pudo abrir y guardar; al
// leer hasta el final, eof nos indica que ya no quedan datos.
//

// Leemos y guardamos archivos con ifstream y ofstream.
#include <iostream>

// <fstream> (file stream): Proporciona las herramientas para trabajar con archivos en disco.
// Define 'ofstream' para escribir/guardar datos y 'ifstream' para leerlos.
#include <fstream>

// <string>: Permite usar el tipo de dato 'string' para almacenar y manipular cadenas de texto.
#include <string>

using namespace std;

int main() {
    const string ruta = "notas_demo.txt";

    // 1. Escritura: se abre en modo append (ios::app) para añadir al final sin borrar lo previo.
    {
        ofstream salida(ruta, ios::app);
        if (!salida) {
            cerr << "No se pudo abrir el archivo para escribir.\n";
            return 1;
        }

        salida << "Estudiar C++\n";
        // Al salir de este bloque {}, el archivo se cierra automáticamente gracias al destructor de 'salida'.
    }

    // 2. Lectura: se abre el archivo para leer su contenido.
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

    // Al finalizar main(), 'entrada' se cierra automáticamente.
    return 0;
}