#include <iostream>
#include <string>

using namespace std;

void increment(int& number) {
    ++number;
}
size_t length(const string& text) {
    return text.size();
}

int main() {
    int counter = 4;
    increment(counter);

    cout << counter << "\n";
}
