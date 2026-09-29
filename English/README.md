# Learn C++ step by step

We will start with variables, decisions and loops. Then we will build objects and connect data through arrays, lists, trees and graphs. We will finish with a library and route application. At each step we connect the explanation with names and operations in the program.

## Study order

1. [Structured programming](#structured-programming).
2. [Object-oriented programming](#object-oriented-programming).
3. [Data structures and algorithms](#data-structures-and-algorithms).
4. [Integrated project](04_Integrated_Project/README.md).

We have 84 programs. Within a topic we follow the numbered subfolders and then the integration example beside them. We first read the comments, predict what will happen and run the example. We then solve its practice task: the statement and requirements also appear inside main.cpp.

## Compile and run

To turn code into a program we use a C++17 compiler such as g++. We open Git Bash or PowerShell in the example folder and run:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

With `-std=c++17` we choose the C++ version; with `-Wall -Wextra -pedantic` we request warnings that help find mistakes; with `-o` we choose the output program name. We compile one main.cpp at a time because each example has its own starting point.

When we split work across files, we compile their `.cpp` files together. For example, in the OOP headers lesson:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Product.cpp -o program.exe
./program.exe
```

We include the `.h` to learn which functions are available, and add the `.cpp` files to the command to include their bodies. Each program's comments contain its complete command. On Linux or macOS we can use `program` without `.exe`.

## Libraries and symbols as we encounter them

A library groups tools already available in C++. With `#include` we state which ones we need. We start with `<iostream>` for screen and keyboard; we add `<string>` for text, `<fstream>` for files and `<vector>` for growing collections. Fixed-size arrays use brackets and need no extra library. Beside each additional include we explain why we use it.

With `using namespace std;` we can write `cout`, `string` and `vector` using those short names. In some headers we group our functions inside `namespace course`, like a folder of names to avoid confusing them with others. With `using namespace course;` we can use those names in the example.

In later topics we encounter `auto`: we let C++ infer the type from the value. It does not change what we store. With `size_t` we represent nonnegative counts and positions. With `.at(position)` we read a vector slot and get an error if it does not exist; with `[]` we must check the boundary ourselves. Traditional arrays use only brackets.

We can also read the [good practices guide](GOOD_PRACTICES.md), where we connect these habits with teamwork.

## Structured programming

### 01.01. Your first program

We will start by displaying a message. We can picture the program as a recipe: inside main we write the steps, and with cout we send text to the screen. We put text in quotation marks; \n starts a new output line. With return 0 we indicate that the program finished successfully. Compiling turns this text file into a program the computer can run.

Complete example: [main.cpp](01_Structured_Programming/01_Hello_World/main.cpp).

```cpp
#include <iostream>

// Lets us write cout without the standard namespace prefix.
using namespace std;

// Execution starts in main; returning 0 reports success.
int main() {
    cout << "Hello, C++!\n";
    return 0;
}
```

**Practice.** Write a program that displays an introduction card.

- Show a name and a course of study on separate lines.
- Add a welcome message.
- Finish without requesting input yet.

### 01.02. Variables, types and operators

We will store data in variables. We can picture each variable as a named box: int stores whole numbers, double and float store numbers with decimal places, char stores one character, bool stores true or false, and string stores text. In count we store the number of notebooks; we multiply it by price to get total. With const we protect a value that should stay unchanged. Dividing whole numbers drops the decimal part: 5 / 2 gives 2, whereas 5.0 / 2 gives 2.5.

Complete example: [main.cpp](01_Structured_Programming/02_Variables_and_Types/main.cpp).

```cpp
#include <iostream>
// We store and work with text using string.
#include <string>

using namespace std;

int main() {
    // const protects unchanged data; quantity remains a variable we can modify.
    const string product = "Notebook";
    int count = 3;
    const double price = 12.5;
    const char category = 'A';
    const bool available = count > 0;
    const double total = count * price;

    cout << product << ": " << total << "\n";
    cout << category << " available: " << boolalpha << available << "\n";
    // Two integers use integer division: 5 / 2 is 2. A double operand preserves the fraction.
    cout << "Integer division: " << 5 / 2 << "\n";
    cout << "Floating-point division: " << 5.0 / 2 << "\n";
}
```

**Practice.** Write a program that calculates a purchase total.

- Store a product name, quantity and price.
- Calculate and display a total with decimal places.
- Use const for a price that stays unchanged during the program.

### 01.03. Reading and displaying input

We will ask for a name and an age. With cout we display the question; with getline(cin, name) we store everything up to Enter, including spaces in a full name. With cin >> age we try to read a whole number. Before using it, we check that reading succeeded and the age is between 0 and 130. We also check the remaining text to reject input such as 20abc. In find_first_not_of(" \t\r") we look for something other than spaces, tabs or a carriage return; string::npos means that nothing was found. This keeps us from accepting a name made only of spaces. We will study if in the next lesson; here we use it to stop when input is incorrect.

Complete example: [main.cpp](01_Structured_Programming/03_Input_and_Output/main.cpp).

```cpp
#include <iostream>
// We store and work with text using string.
#include <string>

using namespace std;

int main() {
    string name;
    int age = 0;
    cout << "Name: ";
    // We read up to Enter so a full name can contain spaces.
    if (!getline(cin, name) || name.find_first_not_of(" \t\r") == string::npos) {
        cerr << "Invalid name.\n";
        return 1;
    }
    cout << "Age: ";
    // With >> we try to store an integer. If reading fails, we show the error.
    if (!(cin >> age) || age < 0 || age > 130) {
        cerr << "Invalid age.\n";
        return 1;
    }
    // We check the rest of the same line: 20abc is not a valid age.
    string remainder;
    getline(cin, remainder);
    if (cin.bad() || remainder.find_first_not_of(" \t\r") != string::npos) {
        cerr << "Invalid age.\n";
        return 1;
    }
    cout << "Hello, " << name << ". You are " << age << " years old.\n";
}
```

**Practice.** Write a program that registers a person.

- Ask for a full name, city and age.
- Allow spaces in the name and city.
- Show a message if the name is missing or the age is invalid.
- Display a card with the valid details.

### 01.04.01. Decisions with if and else

We will choose which instructions to run. With if we ask a question, such as whether someone is at least 18. If the answer is true, we enter its braces; with else we handle the other case. We can join questions: && requires both to be true, || requires at least one, and ! reverses an answer. We can picture two doors: the condition decides which one we take.

Complete example: [main.cpp](01_Structured_Programming/04_Conditionals/01_If_Else/main.cpp).

**Practice.** Write a program that decides entry to an event.

- Store an age and whether an adult accompanies the visitor.
- Allow adults or accompanied minors to enter.
- Display the reason for the decision.
- Try ages 17 and 18.

### 01.04.02. Choosing with switch

We will choose a drink using a number. With switch we compare that number against each case, like choosing from a menu. With break we leave the switch after handling an option; with default we respond when none matches. This is useful for a fixed set of options, such as 1, 2 and 3. In this example we return the drink directly with return: we leave the function, so those cases do not need break.

Complete example: [main.cpp](01_Structured_Programming/04_Conditionals/02_Switch/main.cpp).

**Practice.** Write a program with a three-drink menu.

- Assign a number to each drink.
- Display the selected name and price.
- Report an unknown option.
- Use break to finish each case.

### 01.04. Conditionals

We will combine both ways of making decisions. First we choose a price with switch; then we use if to apply a student discount. The price function receives the option and discount eligibility. For an unknown option we return -1 as an agreed error signal. We separate two questions: what is being bought and which discount applies.

Complete example: [main.cpp](01_Structured_Programming/04_Conditionals/main.cpp).

```cpp
#include <iostream>

using namespace std;

int price(int option, bool isStudent) {
    int base = 0;
    // switch selects a price by option; break prevents falling through to the next case.
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
    // After choosing the price, apply the discount only when its condition holds.
    if (isStudent) {
        base -= 5;
    }
    return base;
}

int main() {

    cout << "Drink 2 with discount: " << price(2, true) << "\n";
}
```

**Practice.** Write an integrated program that prices a cinema ticket.

- Choose among three ticket types with switch.
- Apply a discount with if when eligible.
- Reject unknown options.
- Display the original price, discount and total.

### 01.05.01. Repeating with for

We will repeat a task with for. Inside its parentheses we give the counter's starting value, the condition for continuing and the change after each turn. We can picture five numbered lockers: we inspect one, move ahead and repeat until the last. ++ increases the counter by one; the instructions inside the braces run each time.

Complete example: [main.cpp](01_Structured_Programming/05_Loops/01_For/main.cpp).

**Practice.** Write a program that displays the seven times table.

- Use a counter from 1 to 10.
- Calculate each multiplication inside the for loop.
- Show each operation and result on its own line.

### 01.05.02. Repeating with while

We will repeat while a condition holds. With while we check before entering: if it is already false, we make no turns. We can picture a savings box that receives money until a target is reached. Inside the loop we change the savings; if the checked value never changes, we might repeat forever.

Complete example: [main.cpp](01_Structured_Programming/05_Loops/02_While/main.cpp).

**Practice.** Write a program that simulates weekly savings.

- Start with zero savings.
- Add 25 each week until reaching at least 110.
- Count weeks and display savings after each one.
- Show why the final amount can exceed the target.

### 01.05.03. Repeating with do while

We will make at least one attempt before asking whether to continue. In do while we run the braces first and check the condition afterward. We can picture trying a key and only then deciding whether another attempt is needed. Even if the first check is false, we have already made one turn.

Complete example: [main.cpp](01_Structured_Programming/05_Loops/03_Do_While/main.cpp).

**Practice.** Write a program that simulates up to three attempts.

- Display the attempt message inside do.
- Increase the counter each turn.
- Stop after three attempts.
- Try starting the counter at 3.

### 01.05. Loops

We will use all three loops in one task. With for we collect amounts from several days; with while we remove groups of ten until finished; with do while we show at least one notice. We can picture a shop: we receive orders, deliver them and finally report completion. We choose each loop according to when its condition needs checking.

Complete example: [main.cpp](01_Structured_Programming/05_Loops/main.cpp).

```cpp
#include <iostream>

using namespace std;

int main() {
    int total = 0;
    // for combines initialization, condition and update. This loop accumulates three days of
    // work.
    for (int day = 1; day <= 3; ++day) {
        total += day * 10;
    }
    int deliveries = 0;
    // while checks the condition before each delivery.
    while (total > 0) {
        total -= 10;
        ++deliveries;
    }
    int notices = 0;
    // do executes the body at least once and checks its condition afterward.
    do {
        ++notices;
    } while (notices < 1);

    cout << "Deliveries: " << deliveries << ", notices: " << notices << "\n";
}
```

**Practice.** Write an integrated program that organizes deliveries.

- Add orders from three days with for.
- Handle orders one at a time with while.
- Show at least one final notice with do while.
- Count and display completed orders.

### 01.06.01. Functions: parameters and return values

We will put a calculation in a function. We can picture a small machine: it receives ingredients, does its work and returns a result. We call the inputs parameters; with return we hand back the result. When we receive an int by value, we work with a copy: changing it inside the function does not change the original variable.

Complete example: [main.cpp](01_Structured_Programming/06_Functions/01_Parameters_and_Return/main.cpp).

**Practice.** Write a program that converts minutes to seconds.

- Create a function that receives the minutes.
- Return the result with return.
- Call it with three different values.
- Display the results from main.

### 01.06.02. Value, reference and const reference

We will compare a copy with a reference. If a variable is a box, passing by value hands over another box with the same contents. With int& we attach another label to the original box: changing the value through that label changes the original. A reference stays attached to the same box from its creation; assigning another value changes the contents, not the box it refers to. With const int& we can read through the label but cannot write. The box must keep existing while we use it.

Complete example: [main.cpp](01_Structured_Programming/06_Functions/02_References/main.cpp).

```cpp
#include <iostream>
// We store and work with text using string.
#include <string>

using namespace std;

// By value: the function receives a separate box containing a copy.
void changeCopy(int copy) {
    copy = 99;
    cout << "Inside the copy: " << copy << "\n";
}

// By reference: this name is another label attached to the original box.
void changeOriginal(int& box) {
    ++box;
}

// const prevents modifying the string through this parameter; no copy is made.
size_t length(const string& text) {
    return text.size();
}

int main() {
    int box = 4;
    changeCopy(box);
    cout << "Original after passing by value: " << box << "\n";

    // No & at the call: the parameter declaration determines how it is passed.
    changeOriginal(box);
    cout << "Original after passing by reference: " << box << "\n";

    int& alias = box;
    int other = 8;
    // Assigning to the alias changes box. It does not rebind the alias to other.
    alias = other;
    ++alias;
    cout << "Box through alias: " << box << "; other: " << other << "\n";

    const int& readonly = box;
    // The const view does not freeze box: the original name can still modify it.
    box = 12;
    cout << "Const view observes: " << readonly << "\n";

    const string text = "C++";
    cout << "Length without copying: " << length(text) << "\n";
}
```

**Practice.** Write a program that compares three ways of receiving a balance.

- Create a function that receives int and changes only its copy.
- Create another that receives int& and changes the original balance.
- Create a read-only query with const int&.
- Display the balance before and after each call.

### 01.06. Functions

We will combine functions that calculate with functions that modify. First we obtain a subtotal from price and quantity. Then we pass the total by reference to apply a coupon to that same variable. We can picture a cash register: one task calculates and another updates the amount. This lets us follow each step without putting everything inside main.

Complete example: [main.cpp](01_Structured_Programming/06_Functions/main.cpp).

```cpp
#include <iostream>

using namespace std;

// Value parameters are copies; return sends the result back.
int subtotal(int count, int price) {
    return count * price;
}
// int& aliases the original total: the discount changes the variable in main.
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

**Practice.** Write an integrated purchase program with a coupon.

- Calculate the subtotal in a function that returns a number.
- Apply the discount through a reference to the total.
- Keep the discount from making the total negative.
- Display the subtotal and final total.

### 01.07.01. One-dimensional arrays

We will store several whole numbers in one drawer. With int drawer[4] we reserve four compartments of the same type. We count from zero: drawer[0] is the first and drawer[3] the last. Brackets choose a slot; they do not check that it exists, so we never use drawer[4]. We visit the slots to add their values and then change the second. This array has a fixed size and needs no additional library.

Complete example: [main.cpp](01_Structured_Programming/07_Arrays/01_One_Dimensional/main.cpp).

**Practice.** Write a program that works with five grades.

- Store them in an int grades[5] array.
- Visit only positions 0 through 4.
- Calculate the sum and a decimal average.
- Display the highest grade.

### 01.07.02. Matrices

We will move from one drawer to a cabinet with several drawers. In int cabinet[2][3] we have two rows and three columns. We choose a row first and then a slot: cabinet[1][2] is the third slot in the second row. We use one loop for rows and another for their values. Both start at zero and stop before leaving the cabinet.

Complete example: [main.cpp](01_Structured_Programming/07_Arrays/02_Matrices/main.cpp).

**Practice.** Write a program that displays a two-row, three-column matrix.

- Store six numbers in an array with two bracket pairs.
- Display each row on its own line.
- Calculate the sum of each row separately.
- Keep every row and column access inside the array.

### 01.07. Arrays

We will combine a one-dimensional array with a matrix. In grades we store two students with three grades each; in averages we store one result per student. We visit a row, add its grades and divide by three. With static_cast<double> we treat the sum as a decimal number before dividing, keeping the fractional part of the average.

Complete example: [main.cpp](01_Structured_Programming/07_Arrays/main.cpp).

```cpp
#include <iostream>

using namespace std;

int main() {
    // Each row holds one student's three grades; positions start at zero.
    int grades[2][3]{{8, 9, 10}, {7, 8, 9}};
    double averages[2]{};
    for (size_t row = 0; row < 2; ++row) {
        int sum = 0;
        for (int grade : grades[row]) {
            sum += grade;
        }
        // Convert the sum to double so the average keeps its fractional part.
        averages[row] = static_cast<double>(sum) / 3;
    }

    for (double average : averages) {
        cout << average << "\n";
    }
}
```

**Practice.** Write an integrated student-grade program.

- Store three students with four grades each in a matrix.
- Store the three averages in another array.
- Display each average and whether the student passed.
- Keep grades between 0 and 10.

### 01.08. Strings

We will work with text using string. We can picture a necklace where each bead is a letter or symbol. With + we join text, with size we count positions, and with find we look for a part. If the search returns string::npos, that part was not found. Only after checking do we use substr to take a piece. Here we use simple text; an accented letter can occupy more than one position depending on how it is stored.

Complete example: [main.cpp](01_Structured_Programming/08_Strings/main.cpp).

```cpp
#include <iostream>
// We store and work with text using string.
#include <string>

using namespace std;

int main() {
    string name = "Ana";
    string greeting = "Hello, " + name;
    // find returns the index of the matching text, or string::npos when absent.
    auto position = greeting.find(name);

    cout << greeting << "\n";
    if (position != string::npos) {
        // Extract the substring only after checking that a match exists.
        cout << greeting.substr(position) << "\n";
    }
}
```

**Practice.** Write a program that finds a word inside a sentence.

- Store the sentence and word in string variables.
- Display the position when found.
- Show a message when find returns string::npos.
- Extract the piece only if it was found.

### 01.09. Pointers: a box, a card and a card pointing to another card

First we will distinguish a value from its address. A variable such as int is a box holding a whole number; a pointer is also a variable, but it holds another box's address. We can picture a finger pointing to the data. With & we obtain that address; with * we follow it to read or change the value. Copying a pointer copies the address, not the box. With int** we store a pointer's address: we follow two signs to reach the number.

A reference is another label for the same box; a pointer can change destinations or hold nullptr, meaning it points nowhere. This helps us select a product or link nodes in lists, trees and graphs. We do not need new memory to point to an existing variable. Before following a pointer we check that it has a destination and that the data still exists: an address does not keep the box alive or automatically become nullptr when the box disappears.

Complete example: [main.cpp](01_Structured_Programming/09_Basic_Pointers/main.cpp).

```cpp
#include <iostream>

using namespace std;

// The address card is copied; the integer it points to is still the original.
void addViaPointer(int* address) {
    if (address != nullptr) {
        ++*address;
    }
}

void redirectCopy(int* address, int& other) {
    // Only the local copy of the card is redirected. The caller's pointer does not change.
    address = &other;
    cout << "Local copy's destination: " << *address << "\n";
}

void redirectReference(int*& address, int& other) {
    // int*& aliases the caller's card: we can change its destination.
    address = &other;
}

void redirectDouble(int** address, int& other) {
    // int** holds a card's address. *address is that card, not the integer.
    if (address != nullptr) {
        *address = &other;
    }
}

int main() {
    cout << boolalpha;
    int box = 10;
    int anotherBox = 20;

    // &box obtains its address; int* declares a card pointing to an integer.
    int* address = &box;
    int* alias = address;
    *address = 25;
    cout << "Two cards, one box: " << *alias << "\n";

    addViaPointer(address);
    addViaPointer(nullptr);
    cout << "Box after int*: " << box << "\n";

    redirectCopy(address, anotherBox);
    cout << "Original card still points to box: " << (address == &box) << "\n";

    redirectReference(address, anotherBox);
    cout << "Reference redirected the card: " << (address == &anotherBox) << "\n";

    // &address points to the pointer variable. Dereferencing it twice would reach the integer.
    redirectDouble(&address, box);
    cout << "Double pointer returned it to box: " << (address == &box) << "\n";

    const int* readonly = &box;
    // The value cannot be changed through readonly; the card can change destination.
    readonly = &anotherBox;
    cout << "Reading through const int*: " << *readonly << "\n";

    int* const fixedAddress = &box;
    // The card cannot be redirected; the value at its destination can be modified.
    *fixedAddress = 30;
    cout << "Writing through int* const: " << box << "\n";

    // nullptr does not destroy box or clear other cards. Each observer is independent.
    address = nullptr;
    alias = nullptr;
}
```

**Practice.** Write a program that selects between two integers with a pointer.

- Create two variables and a pointer to one of them.
- Change a value through * and display the original variable.
- Change the pointer destination and display both integers.
- Assign nullptr at the end and check it before reading.
- Draw the boxes and arrows after each change.

### 01.10. Reading and writing files

We will keep text after the program ends. We can think of memory as a whiteboard and a file as a notebook we put away. With ofstream we open the notebook for writing; with ifstream we open it for reading. Both tools come from <fstream>. We use ios::app to add lines at the end without erasing earlier ones. We check that opening and saving succeeded; when reading reaches the end, eof tells us there is no more data.

Complete example: [main.cpp](01_Structured_Programming/10_Files/main.cpp).

```cpp
// We read and save files using ifstream and ofstream.
#include <fstream>
#include <iostream>
// We store and work with text using string.
#include <string>

using namespace std;

int main() {
    const string path = "notes_demo.txt";
    {
        // ios::app appends to preserve lines that already exist.
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
    // Writing has finished: open a reading stream for the same file.
    ifstream input(path);
    if (!input) {
        cerr << "Could not read.\n";
        return 1;
    }
    string line;
    while (getline(input, line)) {
        cout << line << "\n";
    }
    // Reaching the end is normal; a different reading failure must be reported.
    if (!input.eof()) {
        cerr << "Read error.\n";
        return 1;
    }
}
```

**Practice.** Write a program that saves and reads reminders.

- Append a reminder to a text file.
- Check that the file opened and saved successfully.
- Read and display all its lines.
- Run twice and check that both reminders remain.

### 01.11. Recursion

We will solve a task by calling the same function with a smaller case; we call this recursion. Here we calculate a factorial: 4! means 4 times 3 times 2 times 1. In factorial(n) we multiply n by factorial(n - 1). We stop calls when n is 0 or 1, whose result is 1. We can picture boxes inside boxes: we open them down to the smallest and then return, combining results. We limit n to 12 so the result fits in int. With throw we report invalid data; with try and catch we catch that report and display it.

Complete example: [main.cpp](01_Structured_Programming/11_Recursion/main.cpp).

```cpp
#include <iostream>
// We report errors with messages, such as invalid_argument for an invalid value.
#include <stdexcept>

using namespace std;

int factorial(int n) {
    if (n < 0 || n > 12) {
        throw invalid_argument("Use a number between 0 and 12");
    }
    // Base case: 0! and 1! equal 1. Without a stopping case, recursion would not end.
    if (n <= 1) {
        return 1;
    }
    // Each call solves a smaller problem; returning calls multiply their results.
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

**Practice.** Write a program that calculates a sum recursively.

- Create a function that adds from 1 to n.
- Define a case that ends without another call.
- Use a smaller value on each call.
- Try 0, 1 and 5 and explain how the result returns.

### 01.12. Const and headers in structured programming

We will split a program into files. In Grades.h we list the functions we can use; in Grades.cpp we write their steps; from main.cpp we call them. We can picture the .h as a menu and the .cpp as the kitchen. With const we protect the grades from accidental changes. We also pass their count: when receiving an array as a parameter, the function needs that count to know where to stop. With #ifndef, #define and #endif we avoid reading the same header twice inside a file being compiled.

Complete example: [main.cpp](01_Structured_Programming/12_Const_and_Headers/main.cpp).

```cpp
#include "Grades.h"
#include <iostream>

using namespace std;
using namespace course;

int main() {
    const int grades[3]{8, 9, 10};
    double average = 0;
    // We receive true for valid grades; the average is written through a reference.
    if (!calculateAverage(grades, 3, average)) {
        cerr << "Grades must be between 0 and 10.\n";
        return 1;
    }
    cout << "Average: " << average << "\n";
    if (hasPassed(average)) {
        cout << "Passed\n";
    } else {
        cout << "Failed\n";
    }
}
```

**Practice.** Write a grade program split across three files.

- Declare functions in a .h and write their bodies in another .cpp.
- Receive a const grade array together with its count.
- Calculate the average and highest grade without modifying the grades.
- Display from main whether the average reaches the passing grade.
- Compile both .cpp files together.

### 01.13. Integration: a grade report

We will bring the lessons together in a report. We store grades in an array, calculate their average with a function and use a condition to decide whether the student passed. With observer we store the result's address: *observer reads that same average. We then build a text line and append it to a file. We can follow the data all the way through: grades, calculation, decision, message and saved notebook.

Complete example: [main.cpp](01_Structured_Programming/13_Integration/main.cpp).

```cpp
// We read and save files using ifstream and ofstream.
#include <fstream>
#include <iostream>
// We store and work with text using string.
#include <string>

using namespace std;

bool average(const int grades[], int count, double& outputAverage) {
    if (count <= 0) {
        return false;
    }
    long long sum = 0;
    for (int index = 0; index < count; ++index) {
        const int grade = grades[index];
        if (grade < 0 || grade > 10) {
            return false;
        }
        sum += grade;
    }
    outputAverage = static_cast<double>(sum) / count;
    return true;
}

int main() {
    const int grades[3]{8, 9, 10};
    double result = 0;
    if (!average(grades, 3, result)) {
        cerr << "Invalid grades.\n";
        return 1;
    }
    // This pointer reads the average without modifying it or owning its memory.
    const double* observer = &result;

    string status;
    if (*observer >= 6) {
        status = "Passed";
    } else {
        status = "Failed";
    }
    const string report = "Ana: " + to_string(*observer) + " - " + status;
    // The report combines an array, function, condition, string and file in one workflow.
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

**Practice.** Write an integrated school-report program.

- Store names and three grades per student using string and arrays.
- Calculate averages and highest grades with functions.
- Use a reference to update a value and a pointer to read another.
- Classify each average with if and display the report.
- Save reports without erasing earlier ones.
- Separate declarations and functions into a .h and a .cpp.

## Object-oriented programming

### 02.01. Classes and objects

We will bring together data and actions that belong to the same thing. We can picture a class as the blueprint for a Minecraft block: it describes the data and actions of each block created from it. Each actual block would be an object. In this program we use Bicycle: we store color and speed, and pedal increases the speed. We create red and blue separately; pedaling red does not change blue. We call the stored data attributes and the functions inside the class methods. With public we allow main to use them.

Complete example: [main.cpp](02_OOP/01_Classes_and_Objects/main.cpp).

```cpp
#include <iostream>
// We store and work with text using string.
#include <string>

using namespace std;

// The class is a blueprint; each object has its own color and speed.
class Bicycle {
// These public attributes introduce objects; the next lesson protects their state.
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

**Practice.** Write a program with a Minecraft-inspired Block class.

- Store a name, a texture as text and a hardness value.
- Create two objects with different data.
- Add an action that reduces hardness without making it negative.
- Show that changing one block does not change the other.

### 02.02. Encapsulation and const

We will protect a savings-box balance. Instead of allowing any change from main, we keep it inside the class and provide deposit and withdraw operations. Each function checks its rules before changing the balance. We call this encapsulation: keeping data and its rules behind controlled operations. Inside class, members are private unless we write public. With balance() const we can read without changing the savings: const after a function promises to respect the object's data.

Complete example: [main.cpp](02_OOP/02_Encapsulation/main.cpp).

```cpp
#include <iostream>

using namespace std;

class PiggyBank {
    int balanceCents = 0; // Integer cents avoid rounding errors.
// balance is private by default in class. Only validated methods can change it.
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
    // const after the parentheses promises that this query does not modify the object.
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

**Practice.** Write a program with a savings box that protects its balance.

- Keep the balance private.
- Accept positive deposits and withdrawals within the balance.
- Return whether each operation succeeded.
- Read the balance through a const method.
- Try withdrawing more than the available money.

### 02.03. Constructors, destructors

We will observe when an object starts and ends. Its constructor has the class name and prepares its data; in Session it stores the user and announces entry. Its destructor has ~ before the name and runs when the object's lifetime ends. We can picture opening a shop and closing it when leaving. Here the braces mark that stay: reaching their closing brace displays the exit message. Later we will use the same idea to release memory and close files automatically.

Complete example: [main.cpp](02_OOP/03_Constructors_and_Destructors/main.cpp).

```cpp
#include <iostream>
// We store and work with text using string.
#include <string>

using namespace std;

class Session {
    string user;

public:
    // The constructor initializes the object; explicit prevents unexpected implicit conversions.
    explicit Session(const string& name) : user(name) {
        cout << "Enter " << user << "\n";
    }
    // The destructor runs automatically when the object's lifetime ends.
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

**Practice.** Write a program that shows the lifetime of two sessions.

- Store a name when constructing each object.
- Display a message in each constructor and destructor.
- Create both objects inside the same braces.
- Record the order of their messages when leaving.

### 02.04. Composition

We will build one thing using another as a part. A Car has an Engine, so we store an Engine object inside Car. We call this relationship composition. From main we ask the car to start, and the car turns on its engine. We can picture a block containing an inventory: having a part does not mean being that part. When the car's lifetime ends, its contained engine ends too.

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
    // Composition: a Car HAS an Engine. Its lifetime is tied to the car's lifetime.
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

**Practice.** Write a program with a chest containing an inventory.

- Create an Inventory class with an item count.
- Store an Inventory as part of Chest.
- Add a chest operation that reads the count.
- Create two chests and check that their inventories are independent.

### 02.05. Inheritance

We will describe a more specific version of something we already have. An ElectricBicycle is still a Bicycle, but it also has a battery. With : public Bicycle we retain the bicycle's public operations and add our own. We call this relationship inheritance. In assist we check the battery before spending it and pedaling. This fits an “is a” relationship; for “has a part” we use the composition from the previous lesson.

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

// Inheritance: an electric bicycle IS a bicycle and reuses its public operations.
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

**Practice.** Write a program with an electric bicycle.

- Keep a Bicycle class’s operations through inheritance.
- Add a battery with an initial charge.
- Prevent assistance when the battery is too low.
- Display speed and charge after several attempts.

### 02.06. Polymorphism and abstract classes

We will request the same action from different objects. With play we ask an Instrument to make a sound, but a Guitar and a Drum answer differently. We call this polymorphism. With virtual we allow each instrument its own answer; with = 0 we leave that answer unspecified in the general class; with override we check that the new function matches the one being replaced. We pass a reference to use the original instrument. A virtual destructor allows cleaning up the complete object if we later delete it through an Instrument pointer.

Complete example: [main.cpp](02_OOP/06_Polymorphism/main.cpp).

```cpp
#include <iostream>
// We store and work with text using string.
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
```

**Practice.** Write a program that plays three instruments.

- Keep a general Instrument class with a virtual sound function.
- Create three classes that return different sounds.
- Use one play function for all three objects.
- Give the general class a virtual destructor.

### 02.07.01. Manual dynamic memory

We will create a box while the program is running. With new int(42) we reserve space for an integer and receive its address. We store that address in number and read 42 through *number. The box does not disappear merely because we stop using the pointer variable: here we must release it exactly once with delete. We then set number to nullptr to avoid reusing the address. We never use delete on an ordinary local variable or follow a pointer after releasing its data.

Complete example: [main.cpp](02_OOP/07_Memory_and_Pointers/01_New_and_Delete/main.cpp).

**Practice.** Write a program that allocates an integer and changes its value.

- Create the integer with new and store its address.
- Display and modify it through the pointer.
- Release it exactly once with delete.
- Set the pointer to nullptr and never read the released data.

### 02.07.02. Ownership with unique_ptr

We will give one tool responsibility for releasing the box. With unique_ptr from <memory>, we keep that responsibility alongside the address. make_unique creates the data; get lends us its address for reading. That borrowed pointer must not release it. With move from <utility>, we transfer responsibility to newOwner and leave the old owner empty. When the new owner ends, the integer is released automatically. This helps us avoid forgetting delete.

Complete example: [main.cpp](02_OOP/07_Memory_and_Pointers/02_Unique_Ptr/main.cpp).

**Practice.** Write a program that transfers responsibility for a value.

- Create an integer with make_unique.
- Read it through a pointer obtained with get.
- Transfer it to another unique_ptr with move.
- Check that the old owner is empty.
- Stop using the borrowed pointer before the data is released.

### 02.07. Memory and pointers in OOP

We will apply pointers to a Student object. We create the student with make_unique and lend its address with get. With observer->getName() we follow that address and call a student function; -> means following the pointer and using the dot. Calling reset releases the student. The borrowed address then becomes unusable: we must stop using it and set it to nullptr. The borrowed pointer is never responsible for deleting the student.

Complete example: [main.cpp](02_OOP/07_Memory_and_Pointers/main.cpp).

```cpp
#include <iostream>
// We use unique_ptr to release its managed object automatically.
#include <memory>
// We store and work with text using string.
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
    // get returns an observer: unique_ptr remains the owner and releases the object.
    const Student* observer = owner.get();

    cout << observer->getName() << "\n";
    // reset destroys the object. The observer can no longer be dereferenced afterward.
    owner.reset();
    observer = nullptr;
}
```

**Practice.** Write an integrated program with an object managed by unique_ptr.

- Create a class with a name and a const query.
- Create an object with make_unique and observe it with get.
- Display its name using ->.
- Clear the observer before calling reset.
- Explain which variable released the object.

### 02.08. Const, headers and compiling multiple files

We will separate a class so several programs can use it. In Product.h we show its stored data and available operations; in Product.cpp we write how those operations work. From main we create a Product with a name and price. We store prices as whole cents to avoid small decimal-rounding differences. With const we protect the object and its queries. To run it we compile main.cpp together with Product.cpp; including the .h only announces the functions, not their bodies.

Complete example: [main.cpp](02_OOP/08_Headers/main.cpp).

```cpp
#include "Product.h"
#include <iostream>

using namespace std;
using namespace course;

int main() {
    // A const object allows only methods that respect its state, such as these queries.
    const Product notebook("Notebook", 1250);

    cout << notebook.getName() << ": " << notebook.getPrice() << " cents\n";
}
```

**Practice.** Write a program with a Product class split into files.

- Store a name and a private price in cents.
- Declare the class in Product.h and its functions in Product.cpp.
- Read both values through const methods.
- Create two products from main and display their details.
- Reject a negative price.

### 02.09.01. In-memory DAO and CRUD

We will bring storing, finding, updating and removing books together in BookDAO. We can picture a catalog keeper: we request a book by its id, a number identifying it. DAO is the usual name for a class dedicated to data access. Here we keep books in a vector, so they disappear when the program ends. find lends a pointer to a book, or returns nullptr if it is missing. We check before reading it; after changing the catalog we find it again because the vector may move its books.

Complete example: [main.cpp](02_OOP/09_DAO/01_In_Memory_DAO/main.cpp).

**Practice.** Write an in-memory book catalog.

- Create books with positive ids and nonempty titles.
- Prevent duplicate ids.
- Find, update and remove by id.
- Check the pointer before displaying a result.
- Report missing books.

### 02.09.02. Persisting a DAO in a file

We will save the catalog in a file so we can retrieve it later. First we ask the DAO to write its books and then read them into another catalog. We append a complete copy each run; while reading, we keep the last complete copy. If data is invalid, we report it without replacing the catalog with an incomplete reading. To try that case we use istringstream: a tool from <sstream> that reads text already in memory as if it came from a file. This lets us test damaged input without damaging the real file.

Complete example: [main.cpp](02_OOP/09_DAO/02_File_DAO/main.cpp).

**Practice.** Write a catalog that can be saved and restored.

- Save at least two books in a file.
- Check for opening, writing and reading errors.
- Restore the books in another DAO object.
- Try titles containing spaces and quotation marks.
- Reject incomplete input while preserving the previous catalog.

### 02.09. DAO: separating data access

We will follow the catalog's whole workflow: create books, change a title, remove a book and restore saved data. Here we use stringstream from <sstream> as a temporary notebook in memory: we can write into it and read back without creating a disk file. We then try input with repeated ids. Our rule is simple: if we cannot restore every record correctly, we keep the catalog we already had.

Complete example: [main.cpp](02_OOP/09_DAO/main.cpp).

```cpp
#include "BookDAO.h"
#include <iostream>
// We read or write text in memory as if it were a file.
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
    // Simulate a file in memory to save and restore without creating disk data.
    stringstream file;
    if (!(original.save(file))) {
        return 1;
    }
    BookDAO copy;
    if (!(copy.load(file))) {
        return 1;
    }
    if (!(copy.all().size() == 1)) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    if (!(copy.findById(2)->title == "Objects and \"classes\"")) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    istringstream duplicates("2\n2 \"One\"\n2 \"Two\"\n");
    if (copy.load(duplicates)) {
        return 1;
    }
    if (!(copy.all().size() == 1)) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    cout << copy.findById(2)->title << "\n";
}
```

**Practice.** Write an integrated program that manages and restores books.

- Create three books, change a title and remove one.
- Save the result and load it into a second catalog.
- Compare restored books with the originals.
- Try a duplicate id and incomplete input.
- Keep previous data if loading fails.

### 02.10. Integration: a library using objects

We will build a small library with several cooperating classes. Library contains a DAO for storing books. A View decides how to show them: DetailView prints their details and SummaryView shows the count. We request the catalog in the same way even when changing views. This brings together composition, protected data, const queries and polymorphism. With unique_ptr we make clear who releases the view when we stop using it.

Complete example: [main.cpp](02_OOP/10_Integration/main.cpp).

```cpp
#include "../09_DAO/BookDAO.h"
#include <iostream>
// We use unique_ptr to release its managed object automatically.
#include <memory>
// We store and work with text using string.
#include <string>

using namespace std;
using namespace course;

class Library {
    // Composition: the library delegates storage to the DAO.
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
    // Polymorphism lets one interface show details or a summary; unique_ptr manages its
    // lifetime.
    unique_ptr<View> view = make_unique<DetailView>();

    cout << view->render(library.catalog());
    view = make_unique<SummaryView>();

    cout << view->render(library.catalog());
}
```

**Practice.** Write an integrated OOP library application.

- Separate classes and functions into .h and .cpp files.
- Store books through a DAO contained in Library.
- Offer detail and summary views through a shared base class.
- Reject duplicate ids and empty titles.
- Use const for read-only queries.
- Save and restore the catalog from a file.

## Data structures and algorithms

### 03.01. Complexity: time and space

We will compare how much work we do as data grows. Reaching a slot directly takes a fixed amount of work even with more slots (O(1); it does not mean exactly one step). Checking ten slots means ten visits, and checking twenty means twenty (O(n), where n is the slot count). By halving, we go from 8 to 1 in three divisions and from 16 to 1 in four (O(log n), where log n describes growth through halving). We call these abbreviations Big O notation: they describe growth, not exact seconds. We can also count extra data kept while doing the task; we call that auxiliary memory.

Complete example: [main.cpp](03_DSA/01_Complexity/main.cpp).

```cpp
#include <iostream>

using namespace std;

int halvingSteps(int n) {
    int steps = 0;
    while (n > 1) {
        // Each iteration halves what remains: 1024 reaches 1 in ten divisions. Starting with twice
        // as many, 2048, only adds one division (O(log n) growth, with n as the initial amount).
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

**Practice.** Write a program that compares two ways of counting work.

- Count visits when traversing 8, 16 and 32 elements.
- Count the divisions needed to reduce each number to 1.
- Display both results in a table.
- Explain in words why they grow differently.

### 03.02.01. Creating and traversing a vector

We will use a drawer whose number of slots can grow: vector<int>, from <vector>. With push_back we add at the end; with size we check how many values it holds. We visit the numbers to add them. When reserved space fills up, the vector can move to another block with its data; old addresses no longer work. Usually adding at the end takes little work; spreading those moves across many insertions keeps average work per insertion bounded (amortized O(1): we spread growth costs across many operations).

Complete example: [main.cpp](03_DSA/02_Vectors/01_Create_and_Traverse/main.cpp).

**Practice.** Write a program that gathers quantities in a vector.

- Start with two numbers and append three more with push_back.
- Display the element count.
- Traverse them to calculate a sum and average.
- Check that it is not empty before dividing.

### 03.02.02. Inserting and erasing in vectors

We will open and remove spaces in the middle of a vector. With begin() we obtain a position pointing to the start; begin() + 1 points to the second element. We call this way of pointing to a position an iterator. insert places a value and shifts later ones; erase removes a value and closes the gap. This may move nearly all n elements (O(n)). After changing the vector we obtain needed positions again. Before pop_back we check empty so we do not remove from an empty vector.

Complete example: [main.cpp](03_DSA/02_Vectors/02_Insert_and_Erase/main.cpp).

**Practice.** Write a program that edits a list of numbers.

- Insert a number between two others.
- Remove the first and display the result.
- Remove the last only when elements remain.
- Display the vector after each operation.

### 03.02.03. Vectors of objects

We will store complete records inside the vector. With struct Student we group a name and a grade, like two boxes on one card. vector<Student> holds those cards and push_back adds another. With const auto& we read each card without copying it: auto lets C++ infer the type, & gives another label for the same object, and const prevents changes through that label. We use a dot to choose a field on the card.

Complete example: [main.cpp](03_DSA/02_Vectors/03_Vector_of_Objects/main.cpp).

**Practice.** Write a program that stores student records.

- Group name and grade in a struct.
- Store at least three students in a vector.
- Traverse records through const references.
- Display students whose grade is at least 6.

### 03.02. Vectors

We will combine creation, editing and object records in a task list. Each Task stores its name and whether it is finished. We insert a task, mark another and remove a record. We can picture a notebook where we add and remove rows. The vector keeps the data together, but positions may change when inserting or erasing; we therefore distinguish a task's name from its current position.

Complete example: [main.cpp](03_DSA/02_Vectors/main.cpp).

```cpp
#include <iostream>
// We store and work with text using string.
#include <string>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;

struct Task {
    string name;
    bool done;
};

int main() {
    vector<Task> tasks{{"Read", false}, {"Practice", false}};
    // Inserting in the middle shifts following elements; the vector preserves their order.
    tasks.insert(tasks.begin() + 1, {"Compile", false});
    tasks.at(0).done = true;
    tasks.erase(tasks.begin());
    for (const auto& task : tasks) {
        cout << task.name << "\n";
    }
}
```

**Practice.** Write an integrated task program using vector.

- Store each task name and status in a struct.
- Add one task at the end and another in the middle.
- Mark a task as finished.
- Remove a task and display the rest.
- Check positions before using them.

### 03.03.01. Singly linked list

We will build a chain of boxes called nodes. Each node stores a value and a pointer to the next node, like a note showing where the next box is. The list stores the first address; the last points to nullptr. To search we follow the notes one at a time and may visit all n nodes (O(n)). When removing a node we join its previous neighbor to the next before releasing the box. We can see those steps inside SinglyLinkedList.h.

Complete example: [main.cpp](03_DSA/03_Linked_Lists/01_Singly_Linked/main.cpp).

```cpp
#include "SinglyLinkedList.h"
#include <iostream>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;
using namespace course;

int main() {
    SinglyLinkedList list;
    if (!(list.values().empty() && !list.remove(99))) {
        return 1;
    }
    // The nodes will form 10 -> 20 -> 30; the header implements the links.
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

**Practice.** Write a program with a singly linked list.

- Add three numbers using nodes and links.
- Display them by following the links.
- Remove a middle node without losing the others.
- Try an empty list and removing its last node.
- Release every node when it leaves the list.

### 03.03.02. Doubly linked list

We will add a second arrow to each node: one to the next and another to the previous node. This lets us traverse in both directions. We also keep the first and last addresses so appending adjusts a few arrows without traversing the list (O(1)). When removing a node we repair both connections, like removing a train carriage linked at both ends. We can follow those pointer changes in DoublyLinkedList.h.

Complete example: [main.cpp](03_DSA/03_Linked_Lists/02_Doubly_Linked/main.cpp).

**Practice.** Write a program with a doubly linked list.

- Store three numbers and display both directions.
- Remove the middle node and traverse again.
- Try removing the first and last nodes.
- Check that backward links agree with forward links.

### 03.03.03. Circular linked list

We will close the chain into a circle: the last node points back to the first. We can picture players taking repeated turns. Since we do not reach nullptr after one lap, we stop when we return to the start. We keep the last node to append with a few changes (O(1)). Removing the only node leaves an empty list; removing any other node keeps the circle closed.

Complete example: [main.cpp](03_DSA/03_Linked_Lists/03_Circular/main.cpp).

**Practice.** Write a program that organizes turns in a circular list.

- Add three players identified by number.
- Display exactly one lap of turns.
- Remove a player without breaking the circle.
- Try one remaining player and then empty the list.

### 03.03. Linked lists

We will compare all three lists using the same numbers. In the singly linked list we follow one arrow, in the doubly linked list we can go back, and in the circular list we return to the beginning. We insert 10, 20 and 30, remove 20 and check what remains. The main difference is how we link nodes and when traversal stops. We can draw the same three boxes and change only their arrows to understand it.

Complete example: [main.cpp](03_DSA/03_Linked_Lists/main.cpp).

**Practice.** Write an integrated program comparing three lists.

- Insert the same five values into singly linked, doubly linked and circular lists.
- Remove the same value from all three.
- Display forward traversals and the doubly linked list in reverse.
- Limit the circular list to one lap.
- Try each list after emptying it.

### 03.04.01. A stack using vector

We will use a vector like a stack of plates: we add and remove only at the top. With push_back we add, with back we inspect the last value, and with pop_back we remove it. The last item in is the first out. Before reading or removing we check that the stack is not empty. If we need the removed value, we save it before pop_back because that operation does not return it.

Complete example: [main.cpp](03_DSA/04_Stacks/01_With_Vector/main.cpp).

**Practice.** Write a program that removes numbers like a stack of plates.

- Append four numbers to a vector.
- Always inspect and remove the last one.
- Display the numbers in removal order.
- Avoid reading or removing from an empty stack.

### 03.04.02. The stack adapter

We will use stack, the <stack> tool that directly provides stack operations. push adds at the top, top reads the top, and pop removes it. We can picture an undo history: the last action we performed is the first one we examine. Here we show which action would be undone; removing it from history does not itself change a real document.

Complete example: [main.cpp](03_DSA/04_Stacks/02_With_Stack/main.cpp).

```cpp
#include <iostream>
// We store a stack: with stack, the last item in comes out first.
#include <stack>
// We store and work with text using string.
#include <string>

using namespace std;

int main() {
    stack<string> history;
    history.push("Write");
    history.push("Delete");
    if (!history.empty()) {

        // top reads the last value; pop removes it without returning the value.
        cout << "Undo: " << history.top() << "\n";
        history.pop();
    }
}
```

**Practice.** Write a program that displays actions waiting to be undone.

- Store three action descriptions in stack<string>.
- Display the latest action before removing it.
- Remove all in reverse arrival order.
- Report when no actions remain.

### 03.04. Stacks

We will compare a stack built with vector against one using stack. We put 1, 2 and 3 into both and remove from the top. In both, 3 must come out first. We are practicing the removal order: that rule defines a stack even when we use different storage tools.

Complete example: [main.cpp](03_DSA/04_Stacks/main.cpp).

**Practice.** Write an integrated program comparing two stacks.

- Add the same values to a vector and a stack.
- Inspect both tops before removing.
- Check that each step removes the same value.
- Finish with both stacks empty.

### 03.05.01. FIFO queue

We will serve a line in arrival order. With queue from <queue>, we add at the back using push, inspect the first using front and remove it using pop. We can picture people waiting at a service desk. Before serving we check empty. We also call “first in, first out” FIFO; those letters simply abbreviate the same rule.

Complete example: [main.cpp](03_DSA/05_Queues/01_With_Queue/main.cpp).

```cpp
#include <iostream>
// We serve by arrival with queue or by importance with priority_queue.
#include <queue>
// We store and work with text using string.
#include <string>

using namespace std;

int main() {
    queue<string> row;
    row.push("Ana");
    row.push("Luis");

    // The front person arrived first; reading and removing require a nonempty queue.
    while (!row.empty()) {
        cout << "Serve: " << row.front() << "\n";
        row.pop();
    }
}
```

**Practice.** Write a program that serves a line of people.

- Store at least three names in queue<string>.
- Display who is at the front before removing them.
- Serve in arrival order.
- Report when the line becomes empty.

### 03.05.02. Priority queues and heaps

We will serve by importance instead of arrival. priority_queue puts the highest-priority value at the top: for integers this is normally the largest. To choose the smallest, such as a cost, we use greater<int>, a comparison rule from <functional>. We can picture a hospital's urgent cases: arriving first does not always mean being served first. With top we inspect the next value and with pop we remove it; data must be present.

Complete example: [main.cpp](03_DSA/05_Queues/02_Priority_Queue/main.cpp).

**Practice.** Write a program that compares priorities and costs.

- Store 2, 9 and 4 in two priority queues.
- Remove the largest first in one and the smallest first in the other.
- Display all values in both orders.
- Check for data before top or pop.

### 03.05. Queues

We will put the same values into a normal queue and a priority queue. After storing 2, 9 and 4, the first keeps that order; the second serves 9 first. This helps us decide which rule an application needs: respecting arrival or choosing by importance. Changing the structure changes the service rule even with identical data.

Complete example: [main.cpp](03_DSA/05_Queues/main.cpp).

**Practice.** Write an integrated request-service program.

- Store the same priority numbers in queue and priority_queue.
- Display each full service order.
- Add a new request after serving one.
- Explain which fits a ticket desk and which fits urgent cases.

### 03.06.01. Binary trees: roots, children and leaves

We will link nodes into branches. In a binary tree each node can have at most one left child and one right child. We call the first node the root and a node with no children a leaf. Here we are building the shape only: having two branches does not require sorted numbers. To count, we add the current node and both branches recursively. We use unique_ptr so each branch releases its nodes when finished.

Complete example: [main.cpp](03_DSA/06_Trees/01_Binary_Tree/main.cpp).

```cpp
#include <iostream>
// We use unique_ptr to release its managed object automatically.
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
    // An empty branch contributes zero; each node counts itself plus its two children's nodes.
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

**Practice.** Write a program that builds a five-node binary tree.

- Create a root and branches with at most two children per node.
- Draw which node belongs to each branch.
- Count nodes with a recursive function.
- Check that an empty branch contributes zero.

### 03.06.02. Binary search trees (BST)

We will add a rule to the tree: smaller numbers go left and larger ones go right. When searching, we choose one branch and discard the other. We call this a binary search tree, or BST. Here we do not store duplicates. When removing a node with two children, we find a replacement that preserves the ordering. If the tree becomes a chain, we must traverse many nodes; calling it a tree does not guarantee fast searches.

Complete example: [main.cpp](03_DSA/06_Trees/02_Binary_Search_Tree/main.cpp).

**Practice.** Write a program with a binary search tree.

- Insert seven distinct numbers.
- Search for a present and a missing number.
- Remove a leaf, a node with one child and a node with two children.
- Display sorted values after each removal.

### 03.06.03. Tree traversals

We will visit the same tree in three orders. In preorder we read the node before its branches; in inorder we read left branch, node, then right branch; in postorder we leave the node until last. In a search tree, inorder displays sorted numbers. We can picture visiting the same rooms but recording each name on entry, midway or on exit. In all three cases we visit all n nodes (O(n)).

Complete example: [main.cpp](03_DSA/06_Trees/03_Traversals/main.cpp).

**Practice.** Write a program showing three traversals of one tree.

- Build a tree with at least seven nodes.
- Display preorder, inorder and postorder separately.
- Predict all outputs with a drawing before running.
- Check that each node appears once per traversal.

### 03.06. Trees

We will integrate tree operations: insertion, search, traversal and removal. We use Tree.h to follow the same links in every case. First we check an empty tree, add values, compare its traversals and finally remove all nodes. We can picture maintaining a tree of folders: each change must preserve access to branches that still exist.

Complete example: [main.cpp](03_DSA/06_Trees/main.cpp).

**Practice.** Write an integrated program managing numbers in a tree.

- Add and search for numbers without duplicates.
- Offer all three traversals.
- Remove the root without losing other values.
- Empty the tree and insert again.
- Display a message when a number is missing.

### 03.07. Hash tables with unordered_map

We will search by a key, like finding a student card by registration number. unordered_map connects a key to a value; here, a number to a name. Internally it uses a hash function, which calculates the group where a key should be sought. With find we search without creating a card; end() means it is missing. In a found card, first is the key and second the value. We do not expect cards to appear in order. Usually we inspect few entries, but many keys landing together may require many checks.

Complete example: [main.cpp](03_DSA/07_Hash_Tables/main.cpp).

```cpp
#include <iostream>
// We store and work with text using string.
#include <string>
// We connect a key to a value for lookup, such as a student number and name.
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, string> students;
    students.emplace(101, "Ana");
    students.emplace(102, "Luis");
    // find reads without inserting a new key; here 101 exists because it was inserted above.
    auto found = students.find(101);
    cout << found->second << "\n";
    if (!(students.erase(102) == 1 && students.size() == 1)) {
        return 1;
    }
}
```

**Practice.** Write a student directory keyed by registration number.

- Store three distinct numbers and names.
- Search with find and check whether the result is end().
- Remove a number and search for it again.
- Report a missing number without creating a new entry.

### 03.08.01. Representing graphs

We will draw places joined by roads. We call each place a vertex, each connection an edge, and the whole arrangement a graph. In connect we give the source, destination and cost. For travel both ways we add both directions. We keep a neighbor list per place: memory grows with places and roads (O(V + E), where V counts vertices and E counts edges). Another option is a table with one slot per pair of places: five places need 25 slots and ten need 100 (O(V²), meaning V multiplied by V).

Complete example: [main.cpp](03_DSA/08_Graphs/01_Representation/main.cpp).

```cpp
#include "../Graph.h"
#include <iostream>

using namespace std;
using namespace course;

int main() {
    Graph map(3);
    // An edge is a trip from source to destination; the third argument is its cost.
    map.connect(0, 1, 5);
    map.connect(1, 0, 5); // Two-way road.
    map.connect(1, 2, 2); // One-way road.

    for (const auto& edge : map.neighbors(1)) {
        cout << "1 -> " << edge.destination << " cost " << edge.weight << "\n";
    }
}
```

**Practice.** Write a program representing four places and their roads.

- Create a graph with four vertices.
- Add one-way roads and a two-way road.
- Store a nonnegative cost per road.
- Display each place’s neighbors.
- Draw the same map using circles and arrows.

### 03.08.02. BFS: breadth-first search

We will explore a map in layers. We visit the start, then its neighbors, then their neighbors. We keep pending places in a queue to preserve that order. We call this BFS, or breadth-first search. We mark each place when adding it so we do not repeat it, even with roads back. We reach only places connected to the start. A full traversal checks the places and roads (O(V + E), with V places and E connections).

Complete example: [main.cpp](03_DSA/08_Graphs/02_BFS/main.cpp).

**Practice.** Write a program that traverses a map in layers with BFS.

- Create five places, including one isolated place.
- Use a queue for pending places.
- Mark visited places to prevent repeats.
- Display the order from a start and explain why the isolated place is absent.

### 03.08.03. DFS: depth-first search

We will follow a path as far as possible and then return to try another. We can picture exploring a maze. We call this DFS, or depth-first search. Here we use recursion to remember where to return. We mark visited places so we do not go around forever. The order can differ from BFS even though both reach the same places. A full traversal grows with the map’s V places and E roads (O(V + E)).

Complete example: [main.cpp](03_DSA/08_Graphs/03_DFS/main.cpp).

**Practice.** Write a program that explores a map with DFS.

- Create several paths and one leading back to the start.
- Mark visited places.
- Display the traversal without repeating places.
- Compare its order with BFS on the same map.

### 03.08.04. Dijkstra: minimum-cost paths

We will look for the path with the lowest total cost. We can picture roads labeled in minutes: fewer roads do not always mean earlier arrival. With Dijkstra we keep the best known cost and use a priority queue to process the cheapest candidate first. When we find an improvement, we update its cost. This version requires nonnegative costs. INFINITY_DISTANCE is a marker for a route not yet found, not a real number of minutes. dijkstra returns costs; shortestPaths also remembers where we came from so a route can be rebuilt.

Complete example: [main.cpp](03_DSA/08_Graphs/04_Dijkstra/main.cpp).

**Practice.** Write a program that finds the lowest cost between places.

- Create a map with nonnegative costs.
- Include an indirect route cheaper than a direct one.
- Calculate costs from a start with Dijkstra.
- Report an unreachable destination.
- Draw and add up the cheapest route by hand to check it.

### 03.08. Graphs

We will use one map to answer different questions. With BFS we explore in layers; with DFS we follow a branch before returning; with Dijkstra we find the lowest total cost. We share Graph.h so every test uses the same map. We can compare traversal orders, but we do not treat BFS or DFS order as a list of costs: each tool answers a different question.

Complete example: [main.cpp](03_DSA/08_Graphs/main.cpp).

**Practice.** Write an integrated school-route program.

- Store at least five buildings and travel minutes between them.
- Display BFS and DFS from the same building.
- Calculate lowest costs with Dijkstra.
- Include a disconnected building and report when it is unreachable.
- Keep the graph and its operations in a header.

### 03.09.01. Bubble sort

We will sort by comparing neighbors. If the left value is larger, we swap their positions; after a pass the largest remaining value ends up at the end. We can picture large bubbles rising. If a pass makes no swaps, we are done. With n values we may repeat many comparisons, roughly like n times n (O(n²)); already sorted data needs only one pass (O(n)). The complete function is in Sorts.h.

Complete example: [main.cpp](03_DSA/09_Sorting/01_Bubble_Sort/main.cpp).

**Practice.** Write a program that bubble-sorts numbers.

- Include negatives and duplicates.
- Compare neighbors and swap reversed pairs.
- Stop when a pass makes no changes.
- Display the vector before and after.

### 03.09.02. Selection sort

We will find the smallest remaining value and place it at the beginning of the unsorted section. Then we repeat with the rest. We can picture choosing the smallest book from a pile and placing it in a row. Even if numbers are already sorted, we keep finding each group’s minimum; with n values, work grows roughly like n times n (O(n²)). Swapping distant positions can change the order of tied elements.

Complete example: [main.cpp](03_DSA/09_Sorting/02_Selection_Sort/main.cpp).

**Practice.** Write a program that selection-sorts numbers.

- Find the position of the smallest remaining value.
- Swap it with the first position of the unsorted section.
- Display the array after each pass.
- Try sorted data and duplicates.

### 03.09.03. Insertion sort

We will sort like arranging a hand of cards. We take a new value and shift larger earlier values until there is room for it. This keeps the left section sorted. For already sorted data we move through once (O(n), with n values); shifting many values each time can make work grow like n times n (O(n²)). By not moving a value ahead of an equal one, we preserve the order of ties.

Complete example: [main.cpp](03_DSA/09_Sorting/03_Insertion_Sort/main.cpp).

**Practice.** Write a program that insertion-sorts numbers.

- Keep the left side of the vector sorted.
- Save the current value before shifting larger ones.
- Show where each new value ends up.
- Try a sorted list and a reversed list.

### 03.09.04. Merge sort

We will divide a pile into halves until the groups are small, then join them in order. We can picture two helpers sorting their sheets: when joining them, we always take the smallest available sheet. This is merge sort. We need extra mixing space that grows with the n values (O(n) additional memory). Each level visits all values, and there are as many levels as repeated halvings (O(n log n), with n values and log n levels). For a tie we take the left value first to preserve order.

Complete example: [main.cpp](03_DSA/09_Sorting/04_Merge_Sort/main.cpp).

**Practice.** Write a program that merge-sorts numbers.

- Divide until groups contain one element.
- Merge two sorted groups into extra storage.
- Take the left value first when tied.
- Draw the divisions and merges for six numbers.

### 03.09.05. Quick sort

We will choose one value as a reference for separating the rest; we call it the pivot. We put smaller values on one side and repeat within each group. This is quick sort. With evenly split groups, each level checks the n values and the levels grow through halving (O(n log n)). Here we choose the last value: with sorted or equal input, almost everything can stay on one side and cause repeated work (O(n²), like n times n). This choice helps us see why the pivot matters.

Complete example: [main.cpp](03_DSA/09_Sorting/05_Quick_Sort/main.cpp).

**Practice.** Write a program that quick-sorts numbers.

- Choose and identify the pivot at each step.
- Separate smaller values before processing the groups.
- Try mixed, sorted and equal data.
- Draw a case where one group is almost empty.

### 03.09.06. Sorting with the standard library

We will compare our work with tools C++ already provides in <algorithm>. sort orders a range between begin() and end(); end() marks the position after the last value. For student records we provide a function deciding which comes first. The small function written with [] is called a lambda: here it receives two students and compares their grades with <. stable_sort preserves the earlier order of ties. After understanding manual movements, we can use this tool for a complete task.

Complete example: [main.cpp](03_DSA/09_Sorting/06_STD_Sort/main.cpp).

```cpp
// We use sort, stable_sort to sort or change data order.
#include <algorithm>
#include <iostream>
// We store and work with text using string.
#include <string>
// We store a collection that can grow using vector.
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
    // stable_sort preserves the original order of ties: Ana stays before Luis.
    stable_sort(group.begin(), group.end(), [](const Student& a, const Student& b) {
        return a.grade < b.grade;
    });

    for (const auto& student : group) {
        cout << student.name << ": " << student.grade << "\n";
    }
}
```

**Practice.** Write a program that sorts student records.

- Store name and grade in a vector of structs.
- Sort by grade with a comparison function.
- Use stable_sort to preserve the order of ties.
- Display the result and check two equal grades.

### 03.09. Sorting algorithms

We will check five ways of sorting using identical inputs. We create a copy for each algorithm and compare its result with sort. We include empty, negative, repeated and already sorted data. We keep function addresses to call each algorithm in the same way: just as a pointer can point to a box, a function pointer can point to a task we can run. If a comparison fails, we display the problem and stop.

Complete example: [main.cpp](03_DSA/09_Sorting/main.cpp).

**Practice.** Write an integrated sorting program.

- Apply bubble, selection, insertion, merge and quick sort to copies of the same data.
- Compare their results.
- Try empty input, one element, negatives, duplicates and reverse order.
- Count comparisons in at least two algorithms.
- Explain why the same output can require different work.

### 03.10.01. Linear search

We will search by checking a drawer one slot at a time. We do not need to sort first: we move until we find the value or reach the end. We may visit all n elements (O(n)). To return the result we use optional: a small box from <optional> that either holds a position or is empty. We check that it holds something before reading *position. Position zero is valid and must not be confused with “not found”.

Complete example: [main.cpp](03_DSA/10_Searching/01_Linear_Search/main.cpp).

**Practice.** Write a program that searches numbers one by one.

- Search without sorting the vector.
- Return the first matching position.
- Distinguish position zero from a missing result.
- Try the first, last, repeated and missing values.

### 03.10.02. Binary search

We will search an already sorted list. We look at the middle and decide which half could contain the number. We can picture numbered pages: for a smaller page, we discard the right half. Reducing 16 candidates to 8, 4, 2 and 1 takes four divisions; starting with 32 adds just one (O(log n), where n counts candidates and log n describes the divisions). This version finds the first match. We receive a position or an empty result and check which before reading it.

Complete example: [main.cpp](03_DSA/10_Searching/02_Binary_Search/main.cpp).

```cpp
#include "../Searches.h"
#include <iostream>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;
using namespace course;

int main() {
    // The data is already sorted: each comparison can discard half of the remaining range.
    const vector<int> data{1, 3, 3, 5, 8};
    auto position = binarySearch(data, 3);

    if (position) {
        cout << "Index: " << *position << "\n";
    }
}
```

**Practice.** Write a program that searches by halving.

- Use numbers sorted from smallest to largest.
- Show how the search boundaries change.
- Find the first match among duplicates.
- Report missing data.
- Explain why unsorted input cannot be treated the same way.

### 03.10. Searching

We will compare one-by-one search with halving search. First we search unsorted data, then sort and try both methods on the same vector. The number stays the same, but sorting can change its position. We also count the preparation: building a sorted list is extra work, even if searching within it afterward is faster.

Complete example: [main.cpp](03_DSA/10_Searching/main.cpp).

**Practice.** Write an integrated searching program.

- Search several values with linear search.
- Create a sorted copy for binary search.
- Compare whether both find each value.
- Show how sorting changes positions.
- Also try an empty vector.

### 03.11. Const and headers in DSA

We will query a collection without changing it. With const vector<int>& we receive another label for the same vector, but only for reading. In Queries.h we announce the function; in Queries.cpp we traverse the values and count those above a limit. We need neither copying nor sorting. Doubling the data doubles the visits (O(n), with n elements). We add only a counter and a few variables (O(1) additional memory).

Complete example: [main.cpp](03_DSA/11_Const_and_Headers/main.cpp).

```cpp
#include "Queries.h"
#include <iostream>

using namespace std;
using namespace course;

int main() {
    const vector<int> data{9, 4, 10, 6};
    // The query receives const vector<int>&: count without copying or changing the data.
    const size_t count = countAbove(data, EXAMPLE_LIMIT);
    cout << "Values above " << EXAMPLE_LIMIT << ": " << count << "\n";
    for (const int value : data) {
        cout << value << ' ';
    }
    cout << "\n";
}
```

**Practice.** Write a query program split across files.

- Declare a function in a .h and write it in a .cpp.
- Receive a vector through const vector<int>&.
- Count values below a limit using a loop.
- Return zero for an empty vector.
- Check that the original data stayed unchanged.

### 03.12. Integration: processing tasks and querying routes

We will bring the structures together in a task-and-delivery workshop. We store tasks in a vector, serve them through a queue and record events in a list. With a stack we inspect the latest action that could be undone. We use a tree and an id table to practice queries, and sort numbers before searching by halves. Finally we use a graph to calculate routes. Each structure serves a different need; this example brings them together to show how data moves between them.

Complete example: [main.cpp](03_DSA/12_Integration/main.cpp).

```cpp
#include "../03_Linked_Lists/01_Singly_Linked/SinglyLinkedList.h"
#include "../06_Trees/Tree.h"
#include "../08_Graphs/Graph.h"
#include "../09_Sorting/Sorts.h"
#include "../10_Searching/Searches.h"
#include <iostream>
// We serve by arrival with queue or by importance with priority_queue.
#include <queue>
// We store a stack: with stack, the last item in comes out first.
#include <stack>
// We store and work with text using string.
#include <string>
// We connect a key to a value for lookup, such as a student number and name.
#include <unordered_map>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;
using namespace course;

int main() {
    vector<int> ids{3, 1, 2};
    unordered_map<int, string> names{{1, "Read"}, {2, "Compile"}, {3, "Practice"}};
    // The queue organizes work by arrival; the hash table maps each ID to its name.
    queue<int> pending;
    priority_queue<int> urgent;
    for (int id : ids) {
        pending.push(id);
        urgent.push(id);
    }
    SinglyLinkedList history;
    // The stack reads the last task; the list records history and the BST supports queries.
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
    if (!(history.values() == ids && undo.top() == 2)) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    if (!(urgent.top() == 3 && index.contains(2))) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    mergeSort(ids);
    if (!(ids == index.values())) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    if (!(binarySearch(ids, 2).value() == 1)) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }

    // The graph models trips; Dijkstra computes the lowest delivery cost.
    Graph routes(3);
    routes.connect(0, 1, 4);
    routes.connect(0, 2, 1);
    routes.connect(2, 1, 1);
    if (!(bfs(routes, 0).size() == 3 && dfs(routes, 0).size() == 3)) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    if (!(dijkstra(routes, 0).at(1) == 2)) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    cout << "Last task (undo): " << names.at(undo.top()) << "\n";
    cout << "Minimum delivery cost 0 -> 1: " << dijkstra(routes, 0).at(1) << "\n";
}
```

**Practice.** Write an integrated task-and-route program.

- Store ids and names for at least four tasks.
- Serve arrivals with a queue and keep history in a list.
- Inspect the latest task through a stack.
- Sort ids and find one through binary search.
- Represent deliveries with a graph and calculate Dijkstra costs.
- Explain each structure’s responsibility.

### 03.13.01. 1. An array containing objects

We will store complete objects in an array. In Product products[3], each compartment contains a product with its name and price. We reuse Product.h from OOP. We can picture a drawer with three Minecraft blocks: each keeps its own data even though all share a type. We traverse through const Product& to read the original without copying or changing it. When the array ends, its contained objects end too.

Complete example: [main.cpp](03_DSA/13_Combining_Concepts/01_Array_of_Classes/main.cpp).

**Practice.** Write a program with an array of products.

- Create three complete objects with names and prices.
- Traverse them through const references.
- Add their prices in cents.
- Display each product and the total.
- Explain what one array slot contains.

### 03.13.02. 2. A struct contains a class; an array contains those structs

We will add available quantity to each product. With struct Record we group a Product and an integer quantity, then store several Record cards in an array. We can picture a compartment holding the product and a stock label. With records[0].product we reach the object, and with records[0].quantity the number. receiveOne takes Record& to change the original card: removing & would change only a copy.

Complete example: [main.cpp](03_DSA/13_Combining_Concepts/02_Array_of_Structs_with_Classes/main.cpp).

**Practice.** Write a program that tracks stock per product.

- Create a struct containing a Product and a quantity.
- Store at least two records in an array.
- Receive units through a function taking a reference.
- Reject negative quantities and prevent exceeding the integer limit.
- Display the records after the change.

### 03.13.03. 3. An array of cards pointing to integers

We will store addresses instead of integers. In int* addresses[3] we have three cards: each can point to a box outside the array. With *addresses[0] we follow the first card and change red; with addresses[0] = &blue we change only the card. Two cards can point to the same box, or hold nullptr when no box is selected. The array holds the pointers but does not delete the local integers they point to.

Complete example: [main.cpp](03_DSA/13_Combining_Concepts/03_Array_of_Pointers/main.cpp).

**Practice.** Write a program with three address cards for two integers.

- Store addresses in an int* cards[3] array.
- Point two cards at the same integer.
- Change that integer through one card and read through the other.
- Leave one card as nullptr and check before following it.
- Show that changing an address does not change the previous contents.

### 03.13.04. 4. A vector of pointers: an inventory view

We will select products without copying them. We store products in an array and their addresses in vector<Product*>. We call this selection a view: it can grow or show a product several times without creating new products. With Product*& we give selectProduct another label for the original pointer, allowing it to change the destination. Receiving only Product* would change a copy of the card. Growing the address vector does not move these array products; they must keep existing while we read them.

Complete example: [main.cpp](03_DSA/13_Combining_Concepts/04_Vector_of_Pointers/main.cpp).

**Practice.** Write a program that displays a selection of products.

- Store three complete products in an array.
- Keep their addresses in a vector of pointers.
- Change a selection through a reference to a pointer.
- Display a product twice without copying it.
- Check that original products stay in place.

### 03.13.05. 5. An array of arrays of pointers

We will arrange address cards in rows and columns. Product* slots[2][2] represents two rows of two addresses. With slots[0][1] we select a card; if it is not nullptr, we can follow it to the product. Two slots can show the same product, like two signs pointing to the same shop. Here we add const after * to fix the cards; we can still modify their products. A matrix is not Product**: it contains its rows, whereas a double pointer stores an address leading to another pointer.

Complete example: [main.cpp](03_DSA/13_Combining_Concepts/05_Matrix_of_Pointers/main.cpp).

**Practice.** Write a product display using a matrix of pointers.

- Create two rows with two slots each.
- Include a nullptr slot and two slots pointing to one product.
- Display a notice for empty slots.
- Change a product and check both cards show the change.
- Count occupied slots without confusing them with distinct products.

### 03.13.06. 6. Nodes inside an array, connected by pointers

We will store complete nodes in an array and link them with pointers. Each Node contains a Product and next, the next node's address. The boxes occupy positions 0, 1 and 2, but arrows can make us visit 0, 2 and 1. The last link is nullptr. The boxes belong to the array and were not created with new, so we do not use delete. We limit visits to three to detect an accidental circle. Manually copying these records would require rebuilding their arrows so they no longer point to the originals.

Complete example: [main.cpp](03_DSA/13_Combining_Concepts/06_Array_of_Linked_Nodes/main.cpp).

**Practice.** Write a program that links nodes inside an array.

- Store three nodes containing products.
- Connect positions in the order 2, 0 and 1.
- Traverse from the starting node through next.
- Stop at nullptr or report exceeding the node count.
- Draw array positions separately from visit order.

### 03.13.07. 7. A vector of owners and an observer pointer

We will separate the location of cards from that of products. In vector<unique_ptr<Product>>, each card is also responsible for releasing its product. When the vector needs more space it can move the cards; separately created products keep their addresses. With get we lend an address, not deletion responsibility. Removing the responsible card also destroys its product; before that we stop using every borrowed pointer. This differs from vector<Product>, where growth can move the products themselves.

Complete example: [main.cpp](03_DSA/13_Combining_Concepts/07_Vector_of_Unique_Ptr/main.cpp).

**Practice.** Write a program with products managed by unique_ptr inside a vector.

- Create two products with make_unique.
- Obtain a reading pointer with get.
- Grow the vector’s capacity and check the product address.
- Clear every observer before removing its owner.
- Display how many products remain.

### 03.13.08. 8. A class manages struct nodes

We will keep the chain and its rules inside Shelf. Each node contains a Product and a unique_ptr to the next node; the shelf is responsible for the first. From outside we request additions or queries without directly changing links. We can picture a shelf keeper arranging boxes and lending their labels for reading. first() and nextNode() lend addresses; getProduct() lends a read-only reference. Emptying the shelf invalidates those queries because their boxes no longer exist.

Complete example: [main.cpp](03_DSA/13_Combining_Concepts/08_Class_with_Nodes/main.cpp).

**Practice.** Write a program with a class managing a product list.

- Keep the first node inside the class.
- Add three products through a public operation.
- Traverse them using const queries.
- Calculate the total value.
- Empty the list without reusing deleted-node addresses.

### 03.13.09. 9. A vector contains classes managing nodes

We will store several shelves in a vector. Each shelf contains nodes and each node a product: we follow those layers one at a time. Growing the vector can move a shelf, so we clear pointers to the shelf itself before forcing that change. Its nodes were created separately and do not move when their manager changes location. We can therefore keep a node query while the node still exists. Emptying its shelf destroys the node, so we must stop using that query.

Complete example: [main.cpp](03_DSA/13_Combining_Concepts/09_Vector_of_Classes_with_Nodes/main.cpp).

**Practice.** Write a program with a vector of shelves containing nodes.

- Create two shelves and add products to their lists.
- Distinguish a shelf pointer from a pointer to one of its nodes.
- Clear the shelf pointer before growing vector capacity.
- Read the node through its relocated owner.
- Clear the query before emptying its list.

### 03.13. Integration: owners, views, matrices and sorting

We will combine the layers to display sorted products without moving their original boxes. We store shelves in a vector; each shelf contains nodes and each node a product. We collect node addresses in view and sort only those cards by price. Then we choose cards for a display matrix. One card may appear several times: counting occupied slots does not count distinct products. We calculate total value from the shelves so a repeated display does not count the product twice.

Complete example: [main.cpp](03_DSA/13_Combining_Concepts/main.cpp).

```cpp
// We use sort to sort or change data order.
#include <algorithm>
#include <iostream>
// We use numeric_limits to check the largest allowed integer before adding.
#include <limits>
// We report errors with messages, such as invalid_argument for an invalid value.
#include <stdexcept>
// We store a collection that can grow using vector.
#include <vector>
#include "Shelf.h"

using namespace std;
using namespace course;

// Reference to a card: change the caller's selection. The target is read-only.
void selectProduct(const Shelf::Node*& selection, const Shelf::Node* replacement) {
    selection = replacement;
}

long long total(const vector<Shelf>& shelves) {
    long long total = 0;
    for (const Shelf& shelf : shelves) {
        const long long subtotal = shelf.total();
        if (total > numeric_limits<long long>::max() - subtotal) {
            throw overflow_error("The inventory exceeds the long long range");
        }
        total += subtotal;
    }
    return total;
}

int main() {
    // First construct the owners: vector -> shelves -> nodes -> products.
    vector<Shelf> shelves;
    shelves.emplace_back("Stationery");
    shelves.at(0).add(Product("Notebook", 300));
    shelves.at(0).add(Product("Pencil", 100));
    shelves.emplace_back("Books");
    shelves.at(1).add(Product("Book", 500));

    // Then borrow addresses. Lists contain objects; the view contains only cards.
    vector<const Shelf::Node*> view;
    for (const Shelf& shelf : shelves) {
        const Shelf::Node* cursor = shelf.first();
        while (cursor != nullptr) {
            view.push_back(cursor);
            cursor = cursor->nextNode();
        }
    }

    // Sorting the view moves cards without changing links or moving products.
    sort(view.begin(), view.end(), [](const Shelf::Node* left, const Shelf::Node* right) {
        return left->getProduct().getPrice() < right->getProduct().getPrice();
    });
    for (const Shelf::Node* cursor : view) {
        cout << cursor->getProduct().getName() << ": "
             << cursor->getProduct().getPrice() << "\n";
    }

    const Shelf::Node* selection = nullptr;
    selectProduct(selection, view.at(0));
    // The matrix displays two unique products in three slots: selection appears twice.
    const Shelf::Node* const slots[2][2]{
        {selection, nullptr},
        {view.at(1), selection}
    };
    size_t occupied = 0;
    for (const auto& row : slots) {
        for (const Shelf::Node* cursor : row) {
            if (cursor != nullptr) {
                ++occupied;
            }
        }
    }

    // Integration check: the inventory and its links kept their data and order.
    const long long before = total(shelves);
    if (view.size() != 3 || before != 900 || occupied != 3 ||
        selection->getProduct().getPrice() != 100 ||
        shelves.at(0).first()->getProduct().getPrice() != 100 ||
        shelves.at(0).first()->nextNode()->getProduct().getPrice() != 300) {
        cerr << "The integration example produced an unexpected result\n";
        return 1;
    }
    cout << "Inventory in cents: " << before << "\n";
    cout << "Occupied slots (may repeat products): " << occupied << "\n";

    // Clear the selection and view. They do not delete nodes because they are not owners.
    selection = nullptr;
    view.clear();
    // At scope exit, the matrix is destroyed before the shelves; no observer outlives its nodes.
}
```

**Practice.** Write an integrated inventory with shelves, nodes and views.

- Store shelves in a vector and their products in struct nodes.
- Create a read-only pointer view without copying products.
- Sort the view by name or price.
- Display part of it in a pointer matrix with empty slots.
- Change a selection through a reference to a pointer.
- Check that sorting the view leaves original order and totals unchanged.
- Explain which structure releases each object.

## Integrated project

We will build a campus library and route application. From a menu we add books, search by id, organize deliveries and inspect routes. We divide the work: Console talks to the user, Library applies rules, the DAO stores books and CampusMap calculates routes. We reuse course headers to connect classes, lists, stacks, queues, searches and graphs. We can follow a request from entry to recording; each file handles part of that journey. The project guide explains the pieces with code fragments.

[Guide by sections](04_Integrated_Project/README.md).

**Practice.** Write an integrated library and delivery application.

- Organize models, data, services and interface into folders with .h and .cpp files.
- Add, find, update and remove books through a DAO.
- Search ids through a sorted view and binary search.
- Keep history in a doubly linked list and pending deliveries in a queue.
- Use a stack to undo catalog changes.
- Represent buildings as a graph and calculate routes with Dijkstra.
- Save data and restore it after restarting.
- Validate input and preserve the catalog when writing fails.
