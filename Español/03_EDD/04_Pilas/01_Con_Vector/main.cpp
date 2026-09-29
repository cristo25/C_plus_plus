#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> pila;

    pila.push_back(10);
    pila.push_back(20);
    if (!pila.empty()) {
        const int cima = pila.back();
        pila.pop_back();

        cout << "Sale: " << cima << "\n";
    }
}
