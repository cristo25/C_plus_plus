// Polymorphism and abstract classes
//
// virtual selects behavior using the actual object type. = 0 declares an abstract operation;
// override verifies a correct override. A polymorphic base needs a virtual destructor when
// derived objects are destroyed through it.
//
// Analogy: The play-sound button works with different instruments, and each instrument decides
// which sound to make.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Add a Flute and use the same play function without changing it.

#include <iostream>
#include <string>

using namespace std;

class Instrument {
public:
    // A polymorphic base uses a virtual destructor to destroy derived objects correctly.
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

// The reference avoids copying the base; virtual selects the sound using the actual object.
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
