# Learn C++ step by step

This is the course's general guide: structured programming, object-oriented programming (OOP), and data structures and algorithms (DSA). Each topic combines an explanation, an analogy when useful, and a code example. There are **73 independent programs**.

Program-specific explanations, compilation commands and exercises are **comments inside `.cpp` and `.h` files**. OOP and DSA retain guides for comparing concepts and variants; individual programs do not need separate READMEs.

## Study order

1. [Structured programming](#structured-programming): data, decisions, loops and functions.
2. [Object-oriented programming](#object-oriented-programming): state, behavior and ownership.
3. [Data structures and algorithms](#data-structures-and-algorithms): data organization, traversals and costs.

Follow the folder numbers. Read the comments in `main.cpp` and predict its output. In divided topics, finish the subfolders before the `main.cpp` beside them. Read any course header it includes to see the implementation. Run the example and try the exercise in its comments.

## Compile and run

Use C++17 with GCC (`g++`) or Clang (`clang++`). Open Git Bash or PowerShell **in the example folder**, not the course root:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Each example has its own `main`. Compile one program at a time. On Linux or macOS, use `program` instead of `program.exe`. Code blocks in this guide correspond to the linked file; run that file from its folder. Examples create demonstration data in their working directory.

Three examples also compile a separate implementation:

| Folder | Files to compile together |
| --- | --- |
| `01_Structured_Programming/12_Const_and_Headers` | `main.cpp Grades.cpp` |
| `02_OOP/08_Headers` | `main.cpp Product.cpp` |
| `03_DSA/11_Const_and_Headers` | `main.cpp Queries.cpp` |

For example, inside `02_OOP/08_Headers`:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Product.cpp -o program.exe
./program.exe
```

Include the `.h`, never the `.cpp`. Declarations let you call functions from other files; the compiler and linker need their definitions.

## Structured programming

Learn to represent data, make decisions, repeat operations and divide tasks before designing objects.

### 1. Your first program

`#include` brings in declarations from the standard library. `main` is the entry point and `cout` writes to the console. Returning 0 means success. `using namespace std;` lets us write standard names without a prefix.

Analogy: A program is a recipe. `main` tells the cook where to start, and each statement is a step.

Complete example: [main.cpp](01_Structured_Programming/01_Hello_World/main.cpp).

```cpp
#include <iostream>

using namespace std;

int main() {
    cout << "Hello, C++!\n";
    return 0;
}
```

### 2. Variables, types and operators

Declare `int`, `double`, `char`, `bool` and `string`. Use `const` for values that do not change. Integer division discards the fractional part; convert an operand to `double` to keep it.

Analogy: A variable is a labeled box. Its type determines what it can hold. `const` seals its contents.

Complete example: [main.cpp](01_Structured_Programming/02_Variables_and_Types/main.cpp).

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    const string product = "Notebook";
    int count = 3;
    const double price = 12.5;
    const char category = 'A';
    const bool available = count > 0;
    const double total = count * price;

    cout << product << ": " << total << "\n";
    cout << category << " available: " << boolalpha << available << "\n";
    cout << "Integer division: " << 5 / 2 << "\n";
    cout << "Floating-point division: " << 5.0 / 2 << "\n";
}
```

### 3. Reading and displaying input

`getline(cin, text)` reads a whole line. An `istringstream` parses the age from that line. Validate the extraction, the allowed range and that no extra text remains. Reject empty or whitespace-only names. Handle invalid input with clear error messages.

Analogy: The console is a service window: receive a request, check it, then return a response.

Complete example: [main.cpp](01_Structured_Programming/03_Input_and_Output/main.cpp).

```cpp
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string name;
    int age = 0;
    cout << "Name: ";
    if (!getline(cin, name) || name.find_first_not_of(" \t\r") == string::npos) {
        cerr << "Invalid name.\n";
        return 1;
    }
    cout << "Age: ";
    string line;
    if (!getline(cin, line)) {
        return 1;
    }
    istringstream parser(line);
    if (!(parser >> age) || age < 0 || age > 130 || !(parser >> ws).eof()) {
        cerr << "Invalid age.\n";
        return 1;
    }
    cout << "Hello, " << name << ". You are " << age << " years old.\n";
}
```

### 4. Conditionals

Choose execution paths, then combine `switch` and `if` to calculate a discounted price. The integration example produces `25`.

**Decisions with if and else.** A condition evaluates to `true` or `false`. `if`, `else if` and `else` select a branch. Combine conditions with `&&`, `||` and `!`.

Analogy: A fork in the road sends you along a different path depending on the sign.

**Choosing with switch.** `switch` selects among concrete integer, character or enumeration values. `break` ends a case and `default` handles unknown values. This example uses `return`, which ends both the case and the function.

Analogy: A numbered restaurant menu sends each choice to a different preparation.

Complete example: [main.cpp](01_Structured_Programming/04_Conditionals/main.cpp).

```cpp
#include <iostream>

using namespace std;

int price(int option, bool isStudent) {
    int base = 0;
    switch (option) {
        case 1:
            base = 20;
            break;
        case 2:
            base = 30;
            break;
        default:
            return -1;
    }
    if (isStudent) {
        base -= 5;
    }
    return base;
}

int main() {

    cout << "Drink 2 with discount: " << price(2, true) << "\n";
}
```

### 5. Loops

Compare when each loop checks its condition. The integration example accumulates jobs, processes them and issues a notice: `6` deliveries and `1` notice.

**Repeating with for.** `for` groups initialization, condition and progress. Use it when you know the number of repetitions.

Analogy: You visit five lockers one by one without skipping any.

**Repeating with while.** `while` checks its condition before each iteration. It may run zero times. Change something that eventually makes the condition false.

Analogy: Keep filling a piggy bank until you reach your savings goal.

**Repeating with do while.** `do while` checks its condition after the body, so it always runs at least once.

Analogy: Try a key once before deciding whether to keep trying.

Complete example: [main.cpp](01_Structured_Programming/05_Loops/main.cpp).

```cpp
#include <iostream>

using namespace std;

int main() {
    int total = 0;
    for (int day = 1; day <= 3; ++day) {
        total += day * 10;
    }
    int deliveries = 0;
    while (total > 0) {
        total -= 10;
        ++deliveries;
    }
    int notices = 0;
    do {
        ++notices;
    } while (notices < 1);

    cout << "Deliveries: " << deliveries << ", notices: " << notices << "\n";
}
```

### 6. Functions

Split a problem into small tasks. The integration example calculates a subtotal by value and applies a coupon by reference; the total is `50`.

**Functions: parameters and return values.** A function receives data, performs a task and may return a result. Parameters passed by value are copies; changing them does not change the original.

Analogy: A machine receives ingredients through its input and delivers a product through its output.

**References and parameter passing.** `int&` is an alias for the original value. `const string&` lets you inspect a string without copying or modifying it. Initialize a reference when declaring it.

Analogy: A reference is a second label on the same box, rather than a second box.

Complete example: [main.cpp](01_Structured_Programming/06_Functions/main.cpp).

```cpp
#include <iostream>

using namespace std;

int subtotal(int count, int price) {
    return count * price;
}
void applyCoupon(int& total) {
    if (total >= 50) {
        total -= 10;
    }
}

int main() {
    int total = subtotal(3, 20);
    applyCoupon(total);

    int small = 20;
    applyCoupon(small);

    cout << "Total: " << total << "\n";
}
```

### 7. Arrays

Start with one drawer, then a cabinet. The integration example stores grades in a matrix and averages in an array: `9` and `8`.

**One-dimensional arrays.** `array<int, 4>` stores four contiguous integers. Its size is fixed, with indices 0 through 3. `at()` checks bounds; `[]` requires a valid index. A traditional array is written `int data[4]` and has no `at()`.

Analogy: An array is a drawer for one type of item, divided into numbered compartments starting at zero. Four compartments cannot hold a fifth item.

**Matrices.** A matrix has rows and columns. Here an `array` contains arrays; both indices start at zero.

Analogy: A cabinet has drawers (rows), and each drawer has compartments (columns).

Complete example: [main.cpp](01_Structured_Programming/07_Arrays/main.cpp).

```cpp
#include <array>
#include <iostream>

using namespace std;

int main() {
    array<array<int, 3>, 2> grades{{{8, 9, 10}, {7, 8, 9}}};
    array<double, 2> averages{};
    for (size_t row = 0; row < grades.size(); ++row) {
        int sum = 0;
        for (int grade : grades.at(row)) {
            sum += grade;
        }
        averages.at(row) = static_cast<double>(sum) / grades.at(row).size();
    }

    for (double average : averages) {
        cout << average << "\n";
    }
}
```

### 8. Strings

`string` manages a sequence of characters. Concatenate, inspect its size, search and extract substrings. Check for `string::npos` before using a search result. `size()` counts bytes; UTF-8 characters can occupy multiple bytes.

Analogy: A string is a necklace: every character is a bead. Join necklaces or take a section.

Complete example: [main.cpp](01_Structured_Programming/08_Strings/main.cpp).

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string name = "Ana";
    string greeting = "Hello, " + name;
    auto position = greeting.find(name);

    cout << greeting << "\n";
    if (position != string::npos) {
        cout << greeting.substr(position) << "\n";
    }
}
```

### 9. Pointers: addresses and contents

`&value` obtains an address, `int*` holds the address of an integer, and `*pointer` accesses its contents. `nullptr` means no target. The target must stay alive while you access it through the pointer. You do not need `new` yet.

Analogy: The variable is a house and the pointer is a note containing its address. `&` writes down the address; `*` visits the house. An address does not guarantee the house still exists.

Complete example: [main.cpp](01_Structured_Programming/09_Basic_Pointers/main.cpp).

```cpp
#include <iostream>

using namespace std;

int main() {
    int box = 10;
    int* address = &box; // Non-owning: box manages its own lifetime.
    *address = 25;

    int* withoutTarget = nullptr;
    if (withoutTarget != nullptr) {
        cout << *withoutTarget << "\n";
    }
    cout << "Contents: " << *address << "\n";
}
```

### 10. Reading and writing files

`ofstream` writes and `ifstream` reads. Check opening, writing and reading. Objects close their files when leaving their scope. `ios::app` appends content.

Analogy: Memory is a whiteboard erased when the program ends. A file is a notebook that keeps your notes.

Complete example: [main.cpp](01_Structured_Programming/10_Files/main.cpp).

```cpp
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    const string path = "notes_demo.txt";
    {
        ofstream output(path, ios::app);
        if (!output) {
            cerr << "Could not open the file.\n";
            return 1;
        }
        output << "Study C++\n";
        output.close();
        if (!output) {
            cerr << "Save error.\n";
            return 1;
        }
    }
    ifstream input(path);
    if (!input) {
        cerr << "Could not read.\n";
        return 1;
    }
    string line;
    while (getline(input, line)) {
        cout << line << "\n";
    }
    if (!input.eof()) {
        cerr << "Read error.\n";
        return 1;
    }
}
```

### 11. Recursion

A recursive function calls itself with a smaller problem. A base case stops the calls. Without a base case or progress, the call stack may be exhausted. `throw` signals an invalid argument; `try/catch` lets the example check the rejection.

Analogy: Open a box containing a smaller box until reaching an empty one.

Complete example: [main.cpp](01_Structured_Programming/11_Recursion/main.cpp).

```cpp
#include <iostream>
#include <stdexcept>

using namespace std;

int factorial(int n) {
    if (n < 0 || n > 12) {
        throw invalid_argument("Use a number between 0 and 12");
    }
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {

    try {
        cout << factorial(5) << "\n";
    } catch (const invalid_argument& error) {
        cerr << error.what() << "\n";
        return 1;
    }
}
```

### 12. Const and headers in structured programming

`const` prevents changing a value after declaration. These grades and their average never change, so they are constants. `const array<int, 3>&` reads grades without copying or modifying them. `constexpr` allows compile-time evaluation; `inline constexpr` header constants can be shared across implementation files.

`Grades.h` declares functions and constants, `Grades.cpp` defines their operations, and `main.cpp` organizes execution. Splitting a program into files does not require a class.

Analogy: The header is an instruction card describing available services. The implementation does the work. `const` puts glass over the drawer: you can inspect grades without moving them.

Complete example: [main.cpp](01_Structured_Programming/12_Const_and_Headers/main.cpp).

```cpp
#include "Grades.h"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace course;

int main() {
    const array<int, 3> grades{8, 9, 10};
    try {
        const double average = calculateAverage(grades);
        cout << "Average: " << average << "\n";
        if (hasPassed(average)) {
            cout << "Passed\n";
        } else {
            cout << "Failed\n";
        }
    } catch (const invalid_argument& error) {
        cerr << error.what() << "\n";
        return 1;
    }
}
```

### 13. Integration: a grade report

Combine functions, references, strings, arrays, loops, conditions, a non-owning pointer and a file. Read the steps in order: compute, classify, build the report and save it.

Analogy: A teacher checks a drawer of grades, calculates an average and records it in a notebook.

Complete example: [main.cpp](01_Structured_Programming/13_Integration/main.cpp).

```cpp
#include <array>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

double average(const array<int, 3>& grades) {
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return static_cast<double>(sum) / grades.size();
}

int main() {
    const array<int, 3> grades{8, 9, 10};
    const double result = average(grades);
    const double* observer = &result;

    string status;
    if (*observer >= 6) {
        status = "Passed";
    } else {
        status = "Failed";
    }
    const string report = "Ana: " + to_string(*observer) + " - " + status;
    ofstream output("report_demo.txt", ios::app);
    if (!output) {
        cerr << "Could not open the report.\n";
        return 1;
    }
    output << report << "\n";
    output.close();
    if (!output) {
        cerr << "Could not save.\n";
        return 1;
    }

    cout << report << "\n";
}
```

## Object-oriented programming

Apply the preceding foundations to state, behavior, ownership and data access.

[Block guide](02_OOP/README.md).

### 1. Classes and objects

A class defines data and operations. An object is a concrete instance. `public` makes members accessible from outside; the next lesson protects state with `private`.

Analogy: A class is a bicycle blueprint. Every bicycle built from it is an object with its own color.

Complete example: [main.cpp](02_OOP/01_Classes_and_Objects/main.cpp).

```cpp
#include <iostream>
#include <string>

using namespace std;

class Bicycle {
public:
    string color;
    int speed = 0;
    void pedal() {
        speed += 5;
    }
};

int main() {
    Bicycle red;
    red.color = "red";
    Bicycle blue;
    blue.color = "blue";
    red.pedal();

    cout << "Bicycle " << red.color << ": " << red.speed << "\n";
    cout << "Bicycle " << blue.color << ": " << blue.speed << "\n";
}
```

### 2. Encapsulation and const

`private` protects state. Public methods control valid changes. A `const` method queries without changing the object. Integer cents avoid floating-point rounding; this example limits its balance to 1,000,000 cents. You do not need a getter and setter for every attribute.

Analogy: A piggy bank does not let you reach directly inside: its operations control deposits and withdrawals.

Complete example: [main.cpp](02_OOP/02_Encapsulation/main.cpp).

```cpp
#include <iostream>

using namespace std;

class PiggyBank {
    int balanceCents = 0; // Integer cents avoid rounding errors.
public:
    bool deposit(int cents) {
        if (cents <= 0 || cents > 1000000 - balanceCents) {
            return false;
        }
        balanceCents += cents;
        return true;
    }
    bool withdraw(int cents) {
        if (cents <= 0 || cents > balanceCents) {
            return false;
        }
        balanceCents -= cents;
        return true;
    }
    int balance() const {
        return balanceCents;
    }
};

int main() {
    PiggyBank savings;
    if (savings.deposit(-5)) {
        return 1;
    }
    if (!(savings.deposit(500))) {
        return 1;
    }
    if (savings.withdraw(600)) {
        return 1;
    }
    if (!(savings.withdraw(200))) {
        return 1;
    }

    cout << savings.balance() << " cents\n";
}
```

### 3. Constructors, destructors and RAII

A constructor establishes initial state; a destructor runs when the object's lifetime ends. RAII ties a resource's lifetime to an object's lifetime. Strings, files and smart pointers already manage resources this way.

Analogy: Opening a shop puts up its sign; closing it puts away the resources it managed.

Complete example: [main.cpp](02_OOP/03_Constructors_and_Destructors/main.cpp).

```cpp
#include <iostream>
#include <string>

using namespace std;

class Session {
    string user;

public:
    explicit Session(const string& name) : user(name) {
        cout << "Enter " << user << "\n";
    }
    ~Session() {
        cout << "Leave " << user << "\n";
    }
    const string& name() const {
        return user;
    }
};

int main() {
    {
        Session session("Ana");

    } // The lifetime of session ends here.
    cout << "Session ended\n";
}
```

### 4. Composition

An object can contain another: a has-a relationship. Members are constructed before the containing object's constructor body runs.

Analogy: A car has an engine; a car is not a type of engine.

Complete example: [main.cpp](02_OOP/04_Composition/main.cpp).

```cpp
#include <iostream>

using namespace std;

class Engine {
    bool on = false;

public:
    void turnOn() {
        on = true;
    }
    bool isOn() const {
        return on;
    }
};

class Car {
    Engine engine;

public:
    void start() {
        engine.turnOn();
    }
    bool isRunning() const {
        return engine.isOn();
    }
};

int main() {
    Car redCar;

    redCar.start();

    cout << "Engine on\n";
}
```

### 5. Inheritance

A derived class reuses a base when an is-a relationship exists. Public inheritance preserves that relationship for callers. Prefer composition for has-a relationships. This base is not used to destroy derived objects through base pointers; the next lesson covers virtual destructors.

Analogy: An electric bicycle is still a bicycle and adds a battery.

Complete example: [main.cpp](02_OOP/05_Inheritance/main.cpp).

```cpp
#include <iostream>

using namespace std;

class Bicycle {
    int speed = 0;

public:
    void pedal() {
        speed += 5;
    }
    int getSpeed() const {
        return speed;
    }
};

class ElectricBicycle : public Bicycle {
    int battery = 100;

public:
    bool assist() {
        if (battery < 10) {
            return false;
        }
        battery -= 10;
        pedal();
        return true;
    }
    int charge() const {
        return battery;
    }
};

int main() {
    ElectricBicycle bicycle;
    if (!(bicycle.assist())) {
        return 1;
    }

    cout << "Speed: " << bicycle.getSpeed() << "\n";
}
```

### 6. Polymorphism and abstract classes

`virtual` selects behavior using the actual object type. `= 0` declares an abstract operation; `override` verifies a correct override. A polymorphic base needs a virtual destructor when derived objects are destroyed through it.

Analogy: The play-sound button works with different instruments, and each instrument decides which sound to make.

Complete example: [main.cpp](02_OOP/06_Polymorphism/main.cpp).

```cpp
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
```

### 7. Memory and pointers in OOP

Connect ownership to object lifetime. The integration example owns a student through `unique_ptr` and queries it through a non-owning pointer.

**Manual dynamic memory.** `new` constructs a dynamic object and `delete` destroys it. Exactly one owner must be responsible for releasing it. Arrays made with `new[]` need `delete[]`. Usually prefer values, vectors or smart pointers.

Analogy: Rent a locker, keep its address and return it exactly once. Returning it twice or visiting it afterward is an error.

**Ownership with unique_ptr.** `unique_ptr` has one owner and releases its object automatically. `make_unique` constructs it. `move` transfers ownership; a `unique_ptr` cannot be copied. Use raw pointers only as observers when the target's lifetime is guaranteed.

Analogy: A unique key controls the locker. When handing over that key, the former owner no longer holds it.

Complete example: [main.cpp](02_OOP/07_Memory_and_Pointers/main.cpp).

```cpp
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Student {
    string name;

public:
    explicit Student(const string& initialName) : name(initialName) {
    }
    const string& getName() const {
        return name;
    }
};

int main() {
    auto owner = make_unique<Student>("Ana");
    const Student* observer = owner.get();

    cout << observer->getName() << "\n";
    owner.reset();
    observer = nullptr;
}
```

[Topic and variant guide](02_OOP/07_Memory_and_Pointers/README.md).

### 8. Const, headers and compiling multiple files

`Product.h` declares the class, `Product.cpp` defines its methods, and `main.cpp` uses it. `#ifndef` guards prevent repeated declarations. Compile both implementation files and link them. Include headers, never implementation files. Declarations live in `namespace course`, where `using namespace std;` does not introduce standard names into the includer's global namespace.

Analogy: The header is a restaurant menu, the implementation is its kitchen, and `main` places the order.

`main.cpp` creates a `const Product`: you can query its name and price without modifying it. Query methods put `const` after their parentheses in both the header and implementation, allowing calls on const objects. The name query returns `const string&` to avoid a copy and protect the original text.

Distinguish three uses: const values, read-only `const T&` parameters or results, and const methods that inspect object state. A price-changing method should not be const.

Complete example: [main.cpp](02_OOP/08_Headers/main.cpp).

```cpp
#include "Product.h"
#include <iostream>

using namespace std;
using namespace course;

int main() {
    const Product notebook("Notebook", 1250);

    cout << notebook.getName() << ": " << notebook.getPrice() << " cents\n";
}
```

[Topic and variant guide](02_OOP/08_Headers/README.md).

### 9. DAO: separating data access

Study in-memory CRUD and persistence. The integration example combines CRUD and serialization using a string stream without writing files. Definitions inside classes are implicitly inline. This DAO uses linear queries and allows at most 10,000 books; a database is a later step when needed.

**In-memory DAO and CRUD.** DAO means Data Access Object: a data-access pattern, not a paradigm. `BookDAO` centralizes create, read, update and delete (CRUD). Call its operations without manipulating storage directly. For now, view `vector` as a growing collection; DSA studies it in detail. The educational DAO accepts at most 10,000 books, consistently across creation, saving and loading.

Analogy: The librarian knows where books are stored. Ask for a book by its ID without inspecting every shelf.

**Persisting a DAO in a file.** `save` serializes a snapshot and `load` validates it before replacing memory contents. `quoted` preserves spaces and quotes. Each snapshot begins with its book count. The example appends snapshots and reads the latest complete one. It reports damaged snapshots without silently discarding them.

Analogy: The librarian photographs the catalog at closing time and restores its latest photograph when reopening.

Complete example: [main.cpp](02_OOP/09_DAO/main.cpp).

```cpp
#include "BookDAO.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;
using namespace course;

int main() {
    BookDAO original;
    if (!(original.create({1, "Structures"}))) {
        return 1;
    }
    if (!(original.create({2, "Objects"}))) {
        return 1;
    }
    if (!(original.update(2, "Objects and \"classes\""))) {
        return 1;
    }
    if (!(original.remove(1))) {
        return 1;
    }
    stringstream file;
    if (!(original.save(file))) {
        return 1;
    }
    BookDAO copy;
    if (!(copy.load(file))) {
        return 1;
    }
    assert(copy.all().size() == 1);
    assert(copy.findById(2)->title == "Objects and \"classes\"");
    istringstream duplicates("2\n2 \"One\"\n2 \"Two\"\n");
    if (copy.load(duplicates)) {
        return 1;
    }
    assert(copy.all().size() == 1);
    cout << copy.findById(2)->title << "\n";
}
```

[Topic and variant guide](02_OOP/09_DAO/README.md).

### 10. Integration: a library using objects

Encapsulate a DAO using composition and practice polymorphism with two derived views. Reuse the previous header. `unique_ptr` owns the view, and a virtual destructor allows releasing its concrete type.

Analogy: The library has a librarian and shows its catalog through either a detailed service window or a summary window.

Complete example: [main.cpp](02_OOP/10_Integration/main.cpp).

```cpp
#include "../09_DAO/BookDAO.h"
#include <iostream>
#include <memory>
#include <string>

using namespace std;
using namespace course;

class Library {
    BookDAO dao;

public:
    bool registerBook(const Book& book) {
        return dao.create(book);
    }
    const BookDAO& catalog() const {
        return dao;
    }
};

class View {
public:
    virtual ~View() = default;
    virtual string render(const BookDAO& dao) const = 0;
};
class DetailView : public View {
public:
    string render(const BookDAO& dao) const override {
        string text;
        for (const auto& book : dao.all()) {
            text += to_string(book.id) + ": " + book.title + "\n";
        }
        return text;
    }
};
class SummaryView : public View {
public:
    string render(const BookDAO& dao) const override {
        return "Books: " + to_string(dao.all().size()) + "\n";
    }
};

int main() {
    Library library;
    if (!(library.registerBook({1, "Learn C++"}))) {
        return 1;
    }
    if (library.registerBook({1, "Duplicate"})) {
        return 1;
    }
    unique_ptr<View> view = make_unique<DetailView>();

    cout << view->render(library.catalog());
    view = make_unique<SummaryView>();

    cout << view->render(library.catalog());
}
```

## Data structures and algorithms

Choose structures based on their operations and costs. DSA is a field of study that can use both structured programming and OOP.

[Block guide](03_DSA/README.md).

### 1. Complexity: time and space

Big O describes how work grows with input size, rather than exact seconds. Index access is O(1), visiting n elements is O(n), and repeatedly halving a problem takes O(log n) steps. Also count additional memory.

Analogy: Finding a numbered compartment is direct. Inspecting every compartment takes longer as the cabinet grows. Halving a sorted guide discards many pages at once.

Complete example: [main.cpp](03_DSA/01_Complexity/main.cpp).

```cpp
#include <iostream>

using namespace std;

int halvingSteps(int n) {
    int steps = 0;
    while (n > 1) {
        n /= 2;
        ++steps;
    }
    return steps;
}

int main() {
    cout << "Traversal of 1024 elements: 1024 visits\n";
    cout << "Halve 1024 down to 1: " << halvingSteps(1024) << " steps\n";
}
```

### 2. Vectors

Study size, traversal, modification and stored objects. The integration example organizes tasks, completes one and removes it, leaving `Compile` and `Practice`.

**Creating and traversing a vector.** `vector` is a contiguous array whose size can change. `size()` counts elements; `capacity()` counts reserved slots. `push_back` takes amortized O(1), although an individual reallocation costs O(n).

Analogy: A growing drawer can move to a larger drawer when full. Its compartments still start at index zero.

**Inserting and erasing in vectors.** `insert` and `erase` take iterators. `begin()` points to the first element; `end()` is past the last and must not be dereferenced. Middle insertion and erasure shift elements, costing O(n). Reallocation invalidates all pointers, references and iterators; erasure invalidates them from the erased position onward.

Analogy: Making room in the middle of a drawer requires moving the items in the following compartments.

**Vectors of objects.** A vector can store objects of one type. Members of a `struct` are public by default; members of a `class` are private by default. `const auto&` traverses without copying or changing objects.

Analogy: The drawer now stores complete cards, each containing a name and a grade.

Complete example: [main.cpp](03_DSA/02_Vectors/main.cpp).

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Task {
    string name;
    bool done;
};

int main() {
    vector<Task> tasks{{"Read", false}, {"Practice", false}};
    tasks.insert(tasks.begin() + 1, {"Compile", false});
    tasks.at(0).done = true;
    tasks.erase(tasks.begin());
    for (const auto& task : tasks) {
        cout << task.name << "\n";
    }
}
```

[Topic and variant guide](03_DSA/02_Vectors/README.md).

### 3. Linked lists

All three implementations store integers to focus on links and ownership. Manual `new/delete` teaches the mechanism; standard containers manage storage for common applications. The integration example uses all three headers and removes 20 from each list. Compare traversals, then remove the first node, the last node and the only node.

**Singly linked list.** Every node holds a value and the address of the next node. The last points to `nullptr`. There is no direct index access; traversing and searching cost O(n). The header appends values, removes the first matching value and releases all nodes. Appending here costs O(n).

Analogy: A treasure hunt: every card contains a value and a clue pointing to the next card; the last says end.

**Doubly linked list.** Each node knows its previous and next node. Keeping a head and tail permits O(1) append and traversal in either direction. Searching still costs O(n); unlinking an already located node updates both links.

Analogy: Train cars have couplings at both ends, allowing travel in either direction.

**Circular linked list.** The last node points to the first. Stop on returning to the start; waiting for `nullptr` would loop forever. Append costs O(1), while searching and removing by value cost O(n). This variant is singly linked and circular.

Analogy: A wheel of turns returns to the first person after serving the last.

Complete example: [main.cpp](03_DSA/03_Linked_Lists/01_Singly_Linked/main.cpp).

```cpp
#include "SinglyLinkedList.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    SinglyLinkedList list;
    if (!(list.values().empty() && !list.remove(99))) {
        return 1;
    }
    list.append(10);
    list.append(20);
    list.append(30);
    if (!(list.remove(20))) {
        return 1;
    }

    for (int value : list.values()) {
        cout << value << ' ';
    }
    cout << "\n";
    if (!(list.remove(10) && list.remove(30))) {
        return 1;
    }
}
```

[Topic and variant guide](03_DSA/03_Linked_Lists/README.md).

### 4. Stacks

Compare a vector implementation with the stack adapter. The integration example verifies that both produce `3 2 1`.

**A stack using vector.** A stack follows LIFO: last in, first out. Use `push_back`, `back` and `pop_back`; check `empty` before accessing or removing a value.

Analogy: A stack of plates accepts and removes plates at its top.

**The stack adapter.** `stack` exposes only stack operations: `push`, `top`, `pop`, `size` and `empty`. `pop` removes without returning a value; query `top` first. An adapter restricts operations on its underlying container.

Analogy: A box of plates with one opening at the top cannot expose the middle plate.

Complete example: [main.cpp](03_DSA/04_Stacks/02_With_Stack/main.cpp).

```cpp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<string> history;
    history.push("Write");
    history.push("Delete");
    if (!history.empty()) {

        cout << "Undo: " << history.top() << "\n";
        history.pop();
    }
}
```

[Topic and variant guide](03_DSA/04_Stacks/README.md).

### 5. Queues

Compare arrival order and priority order. The integration example produces `2 9 4` with FIFO and `9 4 2` with priority.

**FIFO queue.** `queue` processes values in arrival order: first in, first out. Add with `push`, inspect with `front` and remove with `pop`. Check `empty` before access.

Analogy: A line at a food stall serves the first arrival first.

**Priority queues and heaps.** `priority_queue` uses a heap. By default the largest value is at the top; `greater<int>` puts the smallest there. `top` costs O(1), insertion and removal O(log n). Equal priorities do not preserve arrival order.

Analogy: An emergency room serves patients by severity rather than arrival order.

Complete example: [main.cpp](03_DSA/05_Queues/01_With_Queue/main.cpp).

```cpp
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    queue<string> row;
    row.push("Ana");
    row.push("Luis");

    while (!row.empty()) {
        cout << "Serve: " << row.front() << "\n";
        row.pop();
    }
}
```

[Topic and variant guide](03_DSA/05_Queues/README.md).

### 6. Trees

Distinguish binary trees from binary search trees, then study traversal orders. The integration example inserts, searches, traverses and removes. Recursive examples use small trees; balancing and iterative traversal are extensions for great depths.

**Binary trees: roots, children and leaves.** A tree connects nodes without cycles. The root has no parent; leaves have no children. A binary tree allows at most two children per node. A binary tree need not order its values.

Analogy: An organization chart starts with one manager and branches into subordinates, at most two per manager here.

**Binary search trees (BST).** This BST places smaller values on the left and larger ones on the right, rejecting duplicates. Insertion, search and removal cost O(h), where h is height. Removing a node with two children replaces it with the smallest value in its right subtree. An unbalanced BST may become a chain.

Analogy: Each node in a number guide tells you whether to follow smaller or larger values.

**Tree traversals.** Preorder visits root, left, right. Inorder visits left, root, right. Postorder visits left, right, root. Inorder produces sorted values in a BST. Traversals take O(n), with an O(h) recursive stack plus the output vector.

Analogy: Visit a house and record each room before its annexes, between its annexes, or after them.

Complete example: [main.cpp](03_DSA/06_Trees/01_Binary_Tree/main.cpp).

```cpp
#include <iostream>
#include <memory>

using namespace std;

struct Node {
    int value;
    unique_ptr<Node> left;
    unique_ptr<Node> right;
    explicit Node(int value) : value(value) {
    }
};

int countNodes(const Node* node) {
    if (!node) {
        return 0;
    }
    return 1 + countNodes(node->left.get()) + countNodes(node->right.get());
}

int main() {
    auto root = make_unique<Node>(10);
    root->left = make_unique<Node>(20); // Binary, without the search-tree ordering rule.
    root->right = make_unique<Node>(5);

    cout << "Nodes: " << countNodes(root.get()) << "\n";
}
```

[Topic and variant guide](03_DSA/06_Trees/README.md).

### 7. Hash tables with unordered_map

`unordered_map` associates unique keys with values through hashing. Search and insertion cost O(1) on average and O(n) in the worst case. The library manages collisions and does not guarantee iteration order. `operator[]` can insert; use `find` for lookup alone.

Analogy: A receptionist turns a key into a locker number and distinguishes records when several keys collide.

Complete example: [main.cpp](03_DSA/07_Hash_Tables/main.cpp).

```cpp
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, string> students;
    students.emplace(101, "Ana");
    students.emplace(102, "Luis");
    auto found = students.find(101);
    cout << found->second << "\n";
    if (!(students.erase(102) == 1 && students.size() == 1)) {
        return 1;
    }
}
```

### 8. Graphs

Study representation, traversal and minimum costs. BFS and DFS ignore weights; Dijkstra uses them. The integration example compares traversals and obtains minimum cost 4 from 0 to 3. Free functions in these headers are inline to avoid multiple definitions when linking.

**Representing graphs.** A graph has vertices and edges. An adjacency list stores neighbors using O(V + E) space; an adjacency matrix uses O(V²). `Graph` stores directed edges with nonnegative weights. Add both directions for an undirected connection.

Analogy: Cities are vertices, roads are edges, and the cost of traveling a road is its weight.

**BFS: breadth-first search.** BFS uses a queue and visits by levels. Mark vertices when enqueueing to prevent repeated visits through cycles. Only vertices reachable from the start are visited. In unweighted graphs, levels express minimum edge counts. Time O(V + E), auxiliary memory O(V).

Analogy: Explore a city in rings, starting with nearby neighbors and then their neighbors.

**DFS: depth-first search.** DFS follows a branch as far as possible, then backtracks. Use recursion or an explicit stack. Visited markers prevent cycles. Time O(V + E), auxiliary memory O(V). Order depends on neighbor order; use an explicit stack for great depths.

Analogy: Explore a maze by following a hallway to its end, then returning to try the remaining hallways.

**Dijkstra: minimum-cost paths.** Dijkstra finds minimum distances for nonnegative weights. Use a minimum-priority queue, improve distances and discard outdated entries. `INFINITY_DISTANCE` means unreachable. Repeated queue entries give this implementation O((V + E) log(E + 2)) time and O(V + E) space. It returns costs, not routes.

Analogy: A courier compares total route costs and always considers the cheapest available alternative first.

Complete example: [main.cpp](03_DSA/08_Graphs/01_Representation/main.cpp).

```cpp
#include "../Graph.h"
#include <iostream>

using namespace std;
using namespace course;

int main() {
    Graph map(3);
    map.connect(0, 1, 5);
    map.connect(1, 0, 5); // Two-way road.
    map.connect(1, 2, 2); // One-way road.

    for (const auto& edge : map.neighbors(1)) {
        cout << "1 -> " << edge.destination << " cost " << edge.weight << "\n";
    }
}
```

[Topic and variant guide](03_DSA/08_Graphs/README.md).

### 9. Sorting algorithms

Study algorithms using the same input and compare time, memory and stability. Stability preserves the original order of elements with equal keys. The integration example checks five algorithms against `sort`, including empty input, duplicates, negatives and sorted values. Function pointers allow repeating the same check.

**Bubble sort.** Compare adjacent values and swap inverted pairs. Each pass moves the largest remaining value to the end. Average and worst-case time O(n²), best case O(n) for sorted data with the change flag. Additional memory O(1). Stable. Read `bubbleSort` in `../Sorts.h`.

Analogy: Large bubbles rise toward an end; each pass moves the largest number there.

**Selection sort.** Find the smallest pending value and swap it into the next position. Time O(n²), including sorted inputs; additional memory O(1). This implementation is not stable. Read `selectionSort` in `../Sorts.h`.

Analogy: Always take the smallest card from a pile and put it in the next free slot.

**Insertion sort.** Maintain a sorted left section and insert each new value by shifting larger ones. Average and worst-case time O(n²); O(n) for sorted inputs. Additional memory O(1). Stable. Read `insertionSort` in `../Sorts.h`.

Analogy: Sort a hand of cards by inserting each new card among the previous cards.

**Merge sort.** Split into halves, sort each half and merge them. Time O(n log n); auxiliary memory O(n) plus O(log n) recursive calls. Stable because ties select the left item first. Read `mergeSort` in `../Sorts.h`.

Analogy: Divide sheets between two helpers, then combine their sorted piles by choosing the smaller available sheet.

**Quick sort.** Choose a pivot, partition values and recursively sort the partitions. Usually O(n log n), but this last-element pivot can take O(n²) for sorted or equal inputs. The recursive stack can reach O(n). Not stable. Read `quickSort` in `../Sorts.h`.

Analogy: A pivot splits a line: smaller values move left and the rest move right; repeat within each group.

**Sorting with the standard library.** `sort` provides O(n log n) worst-case comparisons without stability guarantees. `stable_sort` preserves equivalent elements' order. The comparator must express a strict order: use `<`, not `<=`. A lambda `[](...) { ... }` defines a small function at its use site.

Analogy: Give the drawer to a tested sorting tool and tell it how to compare its objects.

Complete example: [main.cpp](03_DSA/09_Sorting/06_STD_Sort/main.cpp).

```cpp
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    int grade;
};

int main() {
    vector<int> numbers{3, 1, 2};
    sort(numbers.begin(), numbers.end());

    vector<Student> group{{"Ana", 8}, {"Eva", 9}, {"Luis", 8}};
    stable_sort(group.begin(), group.end(), [](const Student& a, const Student& b) {
        return a.grade < b.grade;
    });

    for (const auto& student : group) {
        cout << student.name << ": " << student.grade << "\n";
    }
}
```

[Topic and variant guide](03_DSA/09_Sorting/README.md).

### 10. Searching

Search first without ordering, then after sorting. The integration example compares both searches on sorted values and shows the original index of 8 changing from 0 to 4.

**Linear search.** Inspect values from the start until finding a match. No sorting is required. Time O(n), auxiliary memory O(1). `optional` holds a position or `nullopt` for absence. Check before using `*result`; index 0 is valid. In applications you can use `find` instead.

Analogy: Search a drawer for a key by checking every compartment.

**Binary search.** Requires ascending sorted data. Every comparison discards half of the range. Time O(log n), auxiliary memory O(1). Sorting has a separate cost. This version returns the first match; `lower_bound` is its standard alternative, while `binary_search` returns only existence.

Analogy: Open a sorted guide at its middle and decide which half could contain the requested number.

Complete example: [main.cpp](03_DSA/10_Searching/02_Binary_Search/main.cpp).

```cpp
#include "../Searches.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace course;

int main() {
    const vector<int> data{1, 3, 3, 5, 8};
    auto position = binarySearch(data, 3);

    if (position) {
        cout << "Index: " << *position << "\n";
    }
}
```

[Topic and variant guide](03_DSA/10_Searching/README.md).

### 11. Const and headers in DSA

A structure query can receive `const vector<int>&`, reading elements without copying or modifying the vector. The vector and result here are `const`. The header declares the operation and an `inline constexpr` constant, the implementation defines the algorithm with `count_if`, and main.cpp uses it. The query takes O(n) time and O(1) auxiliary space.

Lists, trees and graphs already have headers containing classes and operations. This lesson separates a query's declaration from implementation. Compare its signature with a sorting function taking `vector<int>&` to distinguish reading from modification.

Analogy: A query inspects a drawer through glass and counts items without changing their positions. Sorting requires opening the drawer and moving them.

Complete example: [main.cpp](03_DSA/11_Const_and_Headers/main.cpp).

```cpp
#include "Queries.h"
#include <iostream>

using namespace std;
using namespace course;

int main() {
    const vector<int> data{9, 4, 10, 6};
    const size_t count = countAbove(data, EXAMPLE_LIMIT);
    cout << "Values above " << EXAMPLE_LIMIT << ": " << count << "\n";
    for (const int value : data) {
        cout << value << ' ';
    }
    cout << "\n";
}
```

[Topic and variant guide](03_DSA/11_Const_and_Headers/README.md).

### 12. Integration: processing tasks and querying routes

Combine vector, linked list, stack, queue, priority queue, BST, hash table, graph, sorting and searching. Reuse the DSA headers. The queue defines processing order, the list keeps history, and the stack identifies the next undo action.

Analogy: A workshop receives jobs, processes them, keeps a history, organizes priorities and consults a delivery map.

Complete example: [main.cpp](03_DSA/12_Integration/main.cpp).

```cpp
#include "../03_Linked_Lists/01_Singly_Linked/SinglyLinkedList.h"
#include "../06_Trees/Tree.h"
#include "../08_Graphs/Graph.h"
#include "../09_Sorting/Sorts.h"
#include "../10_Searching/Searches.h"
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace course;

int main() {
    vector<int> ids{3, 1, 2};
    unordered_map<int, string> names{{1, "Read"}, {2, "Compile"}, {3, "Practice"}};
    queue<int> pending;
    priority_queue<int> urgent;
    for (int id : ids) {
        pending.push(id);
        urgent.push(id);
    }
    SinglyLinkedList history;
    stack<int> undo;
    Tree index;
    while (!pending.empty()) {
        int id = pending.front();
        pending.pop();
        history.append(id);
        undo.push(id);
        index.insert(id);
        cout << "Process: " << names.at(id) << "\n";
    }
    assert(history.values() == ids && undo.top() == 2);
    assert(urgent.top() == 3 && index.contains(2));
    mergeSort(ids);
    assert(ids == index.values());
    assert(binarySearch(ids, 2).value() == 1);

    Graph routes(3);
    routes.connect(0, 1, 4);
    routes.connect(0, 2, 1);
    routes.connect(2, 1, 1);
    assert(bfs(routes, 0).size() == 3 && dfs(routes, 0).size() == 3);
    assert(dijkstra(routes, 0).at(1) == 2);
    cout << "Last task (undo): " << names.at(undo.top()) << "\n";
    cout << "Minimum delivery cost 0 -> 1: " << dijkstra(routes, 0).at(1) << "\n";
}
```

## How the three areas connect

Start by reading data, making decisions and dividing work into functions. OOP groups data and operations into objects and controls who can modify them. DSA helps choose how to store those objects and which algorithms to use. DAO separates data access from application rules; it is not a programming paradigm.

An array is a drawer with fixed compartments; a vector can grow. A class may represent each record in that drawer. A DAO may manage the records, while a graph models routes between their locations. The block integration examples practice these connections.

## Good practices

Examples use `using namespace std;`, braces and one statement per line. `const` identifies data and queries that do not change state. Headers group declarations inside `namespace course`. Individual lessons do not use `assert`; algorithm and DAO integration examples use it to check results. Ordinary conditions validate input errors.

Manual `new/delete` appears in focused ownership exercises; prefer values, standard containers and `unique_ptr` for regular applications. Linked lists prevent copying that would duplicate node ownership. The BST is unbalanced, DFS is recursive, and the file DAO appends snapshots: these educational limits are explained alongside the code. See the [good-practices review](GOOD_PRACTICES.md).

## Final project

The [fourth folder](04_Integrated_Project/README.md) reserves the structure for an application combining OOP, DSA, DAO and headers. Its implementation remains for later.

The [Spanish version](../Español/README.md) follows the same order with matching translated examples.
