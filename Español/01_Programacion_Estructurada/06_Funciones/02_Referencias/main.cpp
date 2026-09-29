#include <iostream>
#include <string>

using namespace std;

void incrementar(int& numero) {
    ++numero;
}
size_t longitud(const string& texto) {
    return texto.size();
}

int main() {
    int contador = 4;
    incrementar(contador);

    cout << contador << "\n";
}
