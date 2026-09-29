// Ciclos
//
// Compara cuándo se evalúa la condición. El integrador acumula pedidos, los entrega y emite un
// aviso; produce 6 entregas y 1 aviso.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe

#include <iostream>

using namespace std;

int main() {
    int total = 0;
    // for reúne inicio, condición y avance. Este ciclo acumula el trabajo de tres días.
    for (int dia = 1; dia <= 3; ++dia) {
        total += dia * 10;
    }
    int entregas = 0;
    // while comprueba la condición antes de cada entrega.
    while (total > 0) {
        total -= 10;
        ++entregas;
    }
    int avisos = 0;
    // do ejecuta el bloque al menos una vez y comprueba la condición al final.
    do {
        ++avisos;
    } while (avisos < 1);
    cout << "Entregas: " << entregas << ", avisos: " << avisos << "\n";
}
