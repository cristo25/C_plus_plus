#include <iostream>
#include <string>

using namespace std;

class Instrumento {
public:
    virtual ~Instrumento() = default;
    virtual string sonar() const = 0;
};

class Guitarra : public Instrumento {
public:
    string sonar() const override {
        return "Cuerdas";
    }
};
class Tambor : public Instrumento {
public:
    string sonar() const override {
        return "Percusion";
    }
};

void tocar(const Instrumento& instrumento) {
    cout << instrumento.sonar() << "\n";
}

int main() {
    Guitarra guitarra;
    Tambor tambor;
    const Instrumento& instrumento = guitarra;

    tocar(instrumento);
    tocar(tambor);
}
