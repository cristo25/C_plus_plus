# Object-oriented programming

We will connect this topic’s pieces before solving its integration task. Each link contains the program, comments and a practice task with requirements.

## Classes and objects

We will bring together data and actions that belong to the same thing. We can picture a class as the blueprint for a Minecraft block: it describes the data and actions of each block created from it. Each actual block would be an object. In this program we use Bicycle: we store color and speed, and pedal increases the speed. We create red and blue separately; pedaling red does not change blue. We call the stored data attributes and the functions inside the class methods. With public we allow main to use them.

[Commented program](01_Classes_and_Objects/main.cpp).

## Encapsulation and const

We will protect a savings-box balance. Instead of allowing any change from main, we keep it inside the class and provide deposit and withdraw operations. Each function checks its rules before changing the balance. We call this encapsulation: keeping data and its rules behind controlled operations. Inside class, members are private unless we write public. With balance() const we can read without changing the savings: const after a function promises to respect the object's data.

[Commented program](02_Encapsulation/main.cpp).

## Constructors, destructors

We will observe when an object starts and ends. Its constructor has the class name and prepares its data; in Session it stores the user and announces entry. Its destructor has ~ before the name and runs when the object's lifetime ends. We can picture opening a shop and closing it when leaving. Here the braces mark that stay: reaching their closing brace displays the exit message. Later we will use the same idea to release memory and close files automatically.

[Commented program](03_Constructors_and_Destructors/main.cpp).

## Composition

We will build one thing using another as a part. A Car has an Engine, so we store an Engine object inside Car. We call this relationship composition. From main we ask the car to start, and the car turns on its engine. We can picture a block containing an inventory: having a part does not mean being that part. When the car's lifetime ends, its contained engine ends too.

[Commented program](04_Composition/main.cpp).

## Inheritance

We will describe a more specific version of something we already have. An ElectricBicycle is still a Bicycle, but it also has a battery. With : public Bicycle we retain the bicycle's public operations and add our own. We call this relationship inheritance. In assist we check the battery before spending it and pedaling. This fits an “is a” relationship; for “has a part” we use the composition from the previous lesson.

[Commented program](05_Inheritance/main.cpp).

## Polymorphism and abstract classes

We will request the same action from different objects. With play we ask an Instrument to make a sound, but a Guitar and a Drum answer differently. We call this polymorphism. With virtual we allow each instrument its own answer; with = 0 we leave that answer unspecified in the general class; with override we check that the new function matches the one being replaced. We pass a reference to use the original instrument. A virtual destructor allows cleaning up the complete object if we later delete it through an Instrument pointer.

[Commented program](06_Polymorphism/main.cpp).

## Memory and pointers in OOP

We will apply pointers to a Student object. We create the student with make_unique and lend its address with get. With observer->getName() we follow that address and call a student function; -> means following the pointer and using the dot. Calling reset releases the student. The borrowed address then becomes unusable: we must stop using it and set it to nullptr. The borrowed pointer is never responsible for deleting the student.

[Commented program](07_Memory_and_Pointers/main.cpp).

## Const, headers and compiling multiple files

We will separate a class so several programs can use it. In Product.h we show its stored data and available operations; in Product.cpp we write how those operations work. From main we create a Product with a name and price. We store prices as whole cents to avoid small decimal-rounding differences. With const we protect the object and its queries. To run it we compile main.cpp together with Product.cpp; including the .h only announces the functions, not their bodies.

[Commented program](08_Headers/main.cpp).

## DAO: separating data access

We will follow the catalog's whole workflow: create books, change a title, remove a book and restore saved data. Here we use stringstream from <sstream> as a temporary notebook in memory: we can write into it and read back without creating a disk file. We then try input with repeated ids. Our rule is simple: if we cannot restore every record correctly, we keep the catalog we already had.

[Commented program](09_DAO/main.cpp).

## Integration: a library using objects

We will build a small library with several cooperating classes. Library contains a DAO for storing books. A View decides how to show them: DetailView prints their details and SummaryView shows the count. We request the catalog in the same way even when changing views. This brings together composition, protected data, const queries and polymorphism. With unique_ptr we make clear who releases the view when we stop using it.

[Commented program](10_Integration/main.cpp).

[Back to the general guide](../README.md).
