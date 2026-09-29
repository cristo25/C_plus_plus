#include <iostream>

using namespace std;

int main() {
    int total = 0;
    for (int dia = 1; dia <= 3; ++dia) {
        total += dia * 10;
    }
    int entregas = 0;
    while (total > 0) {
        total -= 10;
        ++entregas;
    }
    int avisos = 0;
    do {
        ++avisos;
    } while (avisos < 1);
    cout << "Entregas: " << entregas << ", avisos: " << avisos << "\n";
}
