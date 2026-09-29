# Good practices in C++

When we program, we also write for whoever reads the code later. At work we share projects with others and may return to them months later. We will care for names, rules and layout so we can understand the code without guessing.

## We choose names that explain the data

With `balanceCents` we know what we store and its unit. With `x` we would need another explanation. We also name functions by their task: `calculateAverage` or `findBook`. In a team we agree on a convention so we recognize data across files.

```cpp
const int productCount = 3;
const int unitPriceCents = 1250;
const int totalCents = productCount * unitPriceCents;
```

Here we store money as whole cents to avoid small rounding differences when calculating with decimal numbers.

## We make blocks visible

We separate instructions into lines and indent inside braces. We can then see what depends on a condition and what repeats. During review we can spot a misplaced instruction without first deciphering its formatting.

```cpp
if (balanceCents >= priceCents) {
    balanceCents -= priceCents;
    cout << "Purchase completed\n";
}
```

## We give initial values and protect what stays unchanged

Before reading a variable we give it a value, such as `int count = 0;`. If a value should stay unchanged, we use `const`: we write our intention and C++ helps us respect it.

To read a vector without copying it, we use `const vector<int>&`. We can picture lending a read-only label for the same drawer. If we need to change it, we receive a reference that allows writing and make that clear in the function name.

## We check data before using it

We may receive letters where we expect a number, an empty name or a request to withdraw more money than available. A file may also be missing. We check these situations before calculating or changing data.

If we cannot finish an operation, we display what happened and keep previous information when possible. In a working application, this prevents incorrect input from damaging valid data.

## We give each function a clear task

We separate reading, calculating and saving. We can then change one part without reviewing the whole program or try a calculation without opening a complete menu. We create classes and functions when they organize a concrete responsibility.

If a class controls a savings box, we keep its balance private and offer deposit and withdrawal operations. Each operation checks its rules. To combine parts we use composition: a library has a catalog. To describe a specific version we use inheritance: an electric bicycle is a bicycle.

## We divide projects between headers and cpp files

In the `.h` we announce the functions and classes we can use; in the `.cpp` we write their steps. We can picture the header as a menu and the cpp as the kitchen. This lets a teammate use a function without reading every detail.

We include the `.h` and compile the required `.cpp` files together. With `#ifndef`, `#define` and `#endif` we avoid processing a header twice while compiling one file. With `namespace` we group names as if in a folder.

In the course's `.cpp` files we use `using namespace std;`. Inside headers we keep it within our own namespace so we do not change the available names in every file including that header.

## We make clear who releases each object

First we check whether an ordinary variable, array or vector is enough. If we need a separate object created while running, we can use `unique_ptr` to give it one owner responsible for releasing it. A pointer obtained through `get()` only borrows its address, not that responsibility.

We learn `new` and `delete` to understand reserving and releasing memory. We can then use objects that perform cleanup when their lifetime ends. We call this idea RAII: we connect the lifetime of something we use, such as an open file, to the object managing it. Cleanup can then occur even when we leave because of an error.

An address does not keep its destination alive. If we release a box, we stop using every card pointing to it; those cards do not turn into `nullptr` by themselves.

## We choose a structure for the task

To store and traverse data we can begin with a vector. To serve by arrival we use a queue; to revisit the latest action, a stack. To connect places with roads we use a graph. We choose based on the operations we need.

First we build lists and sorting algorithms to understand their steps. In a working application we can also use tools C++ already provides when they meet the need. We consider data volume: visiting ten elements and visiting a million require different amounts of work.

## We explain decisions and try boundaries

A comment helps us understand why we chose something or which detail needs care. In the course we also use analogies to connect a new instruction to a familiar idea. We update comments when the program changes.

We try empty data, repeated numbers, incorrect input and allowed boundaries. A list must become empty after removing its only node; a search must report missing data. We compile with warnings and read their messages. In a team we also ask for another review: someone may spot an error we missed.

We can explore these habits further in the [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines).
