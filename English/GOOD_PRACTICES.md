# Good practices in C++

When you write a program, think about whoever will read it later. On a work project, that could be a teammate fixing a bug or adding a feature; it could also be you returning to the code months later. I recommend building the habit of writing code that is easy to understand, review and change.

## Choose names that explain the data

A name should help the reader understand a value without searching for its declaration. `balanceCents`, `productCount` and `unitPrice` say more than `x`, `data` or `value2`. Name functions after their tasks too: `calculateAverage`, `findBook` or `registerStudent`.

```cpp
const int productCount = 3;
const int unitPriceCents = 1250;
const int totalCents = productCount * unitPriceCents;
```

These names identify both the operation and the unit used for money. A shared naming convention helps a team's files read like parts of the same project.

## Make blocks easy to follow

Use consistent indentation and give conditions, loops and functions clear bodies. Braces show which statements depend on a condition. They also make it easier to add a statement without accidentally placing it outside the block.

The reason is practical: during a review, someone needs to follow the program's flow and spot mistakes without first having to decipher its formatting.

## Initialize data and use const when appropriate

A local numeric variable needs a value before it can be read. Declare it near its use and give it an initial value. This reduces the chance of reading it before assigning valid data.

Use `const` when a value should not change after its declaration. It protects the value and communicates your intent. To read a vector or string without copying it, accept `const vector<int>&` or `const string&`. A function that needs to modify that data should allow it in its signature.

## Check data before using it

A user can enter text where you expect a number, leave a name blank or request an invalid operation. A file can be missing or contain incomplete data. Check these cases before calculating results or changing program state.

For example, a withdrawal should require a positive amount and sufficient balance. When an operation fails, explain what happened and preserve the previous data where possible. A real application should have a planned response to incorrect input.

## Give functions a clear task

Reading data, calculating a result and saving it are different responsibilities. Separating them lets you change one part without reviewing the entire program. It also makes a calculation easier to test with other inputs or reuse from another screen.

A function's name should describe its task. If explaining what it does is difficult, check whether it has accumulated too many responsibilities. Also avoid classes and layers that do not yet solve a concrete need.

## Protect class state

When a class controls data such as a balance or inventory, keep that data private and provide operations that check the rules before modifying it. This helps maintain valid state even when several parts of an application use the same object.

Query methods can be `const`. Consider composition first when connecting classes: a library has a catalog. Use inheritance when the relationship between types justifies it and using a derived object through its base interface makes sense.

## Separate declarations from implementation

A header lets readers see the operations a class or group of functions offers. The `.cpp` file contains their definitions. In a project with several files, this separation allows implementation work without making readers inspect it to understand the interface.

Include the `.h` and compile the required `.cpp` files. Use include guards and group names in a namespace when appropriate. Avoid putting `using namespace std;` at global scope in a header: it affects every file that includes it. In `.cpp` files, follow the project's convention and watch for name collisions.

## Make memory ownership clear

Before allocating memory, ask whether an ordinary variable or a container such as `vector` is enough. These options already manage their data's lifetime. If you need a dynamic object with one owner, `unique_ptr` helps release it automatically when its lifetime ends.

Learning `new` and `delete` helps explain memory, but managing it manually requires attention to every function exit. With RAII, an object manages the resource and its destructor releases it, including when an exception causes an exit. This reduces the paths where you could forget cleanup.

A pointer that only observes an object does not destroy it. Make sure the object is still alive before using that pointer; releasing its owner invalidates its observers.

## Choose structures for the operations you need

A vector is often a useful starting point for storing and traversing data. A queue expresses arrival order. A hash table may help retrieve information by key. The choice depends on how you will insert, search, traverse and remove.

Real projects also need to consider data volume and available memory. An algorithm convenient for ten elements can be expensive for a million. Implement lists and sorting algorithms to understand their mechanisms; when the standard library meets the requirement, use its implementations.

## Write comments that explain a decision

A useful comment explains why you chose something, which condition must hold or which detail could cause an error. Restating the instruction immediately below adds little.

```cpp
// Store the price in integer cents to avoid rounding errors.
const int priceCents = 1250;
```

Review comments when you change code. An outdated explanation can confuse someone trying to fix it.

## Check more than the expected case

Before finishing a program, try empty inputs, duplicate values, invalid input and allowed boundaries where relevant. A list should handle removing its only node; a search should be able to report that a value is absent.

Compile with warnings and review their messages. On a team, checking changes and asking for a review helps catch errors before someone else depends on that code.

For more on initialization, `const`, header organization and resource management, see the [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines).
