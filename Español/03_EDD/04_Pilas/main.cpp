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
    while (!manual.empty()) {
        cout << manual.back() << ' ';
        manual.pop_back();
        adaptador.pop();
    }
    cout << "\n";
}
