#include <iostream>
#include <string>

using namespace std;

class Instrument {
public:
    virtual ~Instrument() = default;
    virtual string sound() const = 0;
};

class Guitar : public Instrument {
public:
    string sound() const override {
        return "Strings";
    }
};
class Drum : public Instrument {
public:
    string sound() const override {
        return "Percussion";
    }
};

void play(const Instrument& instrument) {
    cout << instrument.sound() << "\n";
}

int main() {
    Guitar guitar;
    Drum drum;
    const Instrument& instrument = guitar;

    play(instrument);
    play(drum);
}
