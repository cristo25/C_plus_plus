// Pilas
//
// Compara el mecanismo con vector y la interfaz de stack. El integrador verifica que ambos
// producen 3 2 1.
//
// Compilar desde esta carpeta: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o programa.exe
//
// Ejecutar: ./programa.exe

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    vector<int> manual;
    stack<int> adaptador;
    for (int dato : {1, 2, 3}) {
        manual.push_back(dato);
        adaptador.push(dato);
    }
    // Ambas pilas retiran por el extremo superior: último en entrar, primero en salir.
    while (!manual.empty()) {
        cout << manual.back() << ' ';
        manual.pop_back();
        adaptador.pop();
    }
    cout << "\n";
}
