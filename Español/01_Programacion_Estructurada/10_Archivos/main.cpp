// Leer y escribir archivos
//
// ofstream escribe y ifstream lee. Comprueba apertura, escritura y lectura. Los objetos cierran
// los archivos al salir de su bloque. ios::app agrega contenido al final.
//
// Analogía: La memoria es un pizarrón que se borra al terminar; un archivo es un cuaderno que
// conserva tus anotaciones.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe
//
// Practica: Agrega otra nota y vuelve a leer el archivo. Explica qué ocurriría usando
// ios::trunc.

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    const string ruta = "notas_demo.txt";
    {
        // ios::app añade al final para conservar las líneas que ya existían.
        ofstream salida(ruta, ios::app);
        if (!salida) {
            cerr << "No se pudo abrir el archivo.\n";
            return 1;
        }
        salida << "Estudiar C++\n";
        salida.close();
        if (!salida) {
            cerr << "Error al guardar.\n";
            return 1;
        }
    }
    // La escritura ya terminó: abrimos ahora un flujo de lectura del mismo archivo.
    ifstream entrada(ruta);
    if (!entrada) {
        cerr << "No se pudo leer.\n";
        return 1;
    }
    string linea;
    while (getline(entrada, linea)) {
        cout << linea << "\n";
    }
    // Llegar al final es normal; un fallo de lectura diferente debe informarse.
    if (!entrada.eof()) {
        cerr << "Error de lectura.\n";
        return 1;
    }
}
