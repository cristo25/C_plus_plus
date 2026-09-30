// Polymorphism and abstract classes
//
// We will request the same action from different objects. With play we ask an Instrument to make a
// sound, but a Guitar and a Drum answer differently. We call this polymorphism. With virtual we
// allow each instrument its own answer; with = 0 we leave that answer unspecified in the general
// class; with override we check that the new function matches the one being replaced. We pass a
// reference to use the original instrument. A virtual destructor allows cleaning up the complete
// object if we later delete it through an Instrument pointer.
//

#include <iostream>
// We store and work with text using string.
#include <string>

using namespace std;

class Instrument {
public:
    // With virtual we can release the complete instrument even when treating it as Instrument.
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

// Practice: let's create a Block class and two kinds of block with different descriptions.
// - Declare a virtual function that describes a block.
// - Make Stone and Wood return different descriptions.
// - Pass both objects by reference to one function that prints their descriptions.
