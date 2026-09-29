# Learn C++ step by step

A complete English learning route with **73 runnable programs**, matching the Spanish version. Folder names are numbered to establish study order.

## Start here

1. [Structured programming](01_Structured_Programming/README.md): data, decisions, loops, functions, arrays, strings, pointers, files and recursion.
2. [OOP](02_OOP/README.md): classes, encapsulation, composition, inheritance, polymorphism, memory, headers and DAO.
3. [DSA](03_DSA/README.md): complexity, vectors, linked lists, stacks, queues, trees, hash tables, graphs, sorting and searching.
4. [Integrated project](04_Integrated_Project/README.md): folders reserved for the combined application we will build later.

Structured programming and OOP organize programs. DSA studies structures and algorithms; DAO is a data-access pattern. They complement each other.

## How to study

1. Read each README for the concept, analogy, execution instructions, result and exercise.
2. Read main.cpp and predict the console output.
3. Compile and run it. Individual lessons show results without assertions; algorithm integration checks retain assertions.
4. Change the data and try the exercise. State-changing operations and input validation do not depend on assertions.
5. For topics with subfolders, finish the individual lessons before running the main.cpp in the parent topic folder. Complete the block integration exercise last.

## Compile

Use a C++17 compiler such as GCC. No external libraries or build system are required. In PowerShell, inside an example folder:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

The [headers lesson](02_OOP/08_Headers/README.md) has two implementation files:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Product.cpp -o program.exe
./program.exe
```

On Linux or macOS, replace `program.exe` with `program`. With Clang, replace `g++` with `clang++`. Each example is independent: **do not compile all main.cpp files together**. Relative includes refer to the source files; demonstration data files are created in the working directory.

## Pointer progression

Study addresses, values and lifetimes in [basic pointers](01_Structured_Programming/09_Basic_Pointers/README.md), then manual ownership and unique_ptr in [OOP memory](02_OOP/07_Memory_and_Pointers/README.md). Apply links and node cleanup in [linked lists](03_DSA/03_Linked_Lists/README.md) and unique ownership in trees.

## Conventions and review

Examples use `using namespace std;`. Headers keep it inside `namespace course`; examples that include those headers also use `using namespace course;`. See the [good-practices review](GOOD_PRACTICES.md). The [Spanish version](../Español/README.md) follows the same sequence.

## Structure

```text
English/
├── 01_Structured_Programming/
│   ├── 01_Hello_World/
│   ├── 02_Variables_and_Types/
│   ├── 03_Input_and_Output/
│   ├── 04_Conditionals/
│   │   ├── 01_If_Else/
│   │   └── 02_Switch/
│   ├── 05_Loops/
│   │   ├── 01_For/
│   │   ├── 02_While/
│   │   └── 03_Do_While/
│   ├── 06_Functions/
│   │   ├── 01_Parameters_and_Return/
│   │   └── 02_References/
│   ├── 07_Arrays/
│   │   ├── 01_One_Dimensional/
│   │   └── 02_Matrices/
│   ├── 08_Strings/
│   ├── 09_Basic_Pointers/
│   ├── 10_Files/
│   ├── 11_Recursion/
│   ├── 12_Const_and_Headers/
│   └── 13_Integration/
├── 02_OOP/
│   ├── 01_Classes_and_Objects/
│   ├── 02_Encapsulation/
│   ├── 03_Constructors_and_Destructors/
│   ├── 04_Composition/
│   ├── 05_Inheritance/
│   ├── 06_Polymorphism/
│   ├── 07_Memory_and_Pointers/
│   │   ├── 01_New_and_Delete/
│   │   └── 02_Unique_Ptr/
│   ├── 08_Headers/
│   ├── 09_DAO/
│   │   ├── 01_In_Memory_DAO/
│   │   └── 02_File_DAO/
│   └── 10_Integration/
├── 03_DSA/
│   ├── 01_Complexity/
│   ├── 02_Vectors/
│   │   ├── 01_Create_and_Traverse/
│   │   ├── 02_Insert_and_Erase/
│   │   └── 03_Vector_of_Objects/
│   ├── 03_Linked_Lists/
│   │   ├── 01_Singly_Linked/
│   │   ├── 02_Doubly_Linked/
│   │   └── 03_Circular/
│   ├── 04_Stacks/
│   │   ├── 01_With_Vector/
│   │   └── 02_With_Stack/
│   ├── 05_Queues/
│   │   ├── 01_With_Queue/
│   │   └── 02_Priority_Queue/
│   ├── 06_Trees/
│   │   ├── 01_Binary_Tree/
│   │   ├── 02_Binary_Search_Tree/
│   │   └── 03_Traversals/
│   ├── 07_Hash_Tables/
│   ├── 08_Graphs/
│   │   ├── 01_Representation/
│   │   ├── 02_BFS/
│   │   ├── 03_DFS/
│   │   └── 04_Dijkstra/
│   ├── 09_Sorting/
│   │   ├── 01_Bubble_Sort/
│   │   ├── 02_Selection_Sort/
│   │   ├── 03_Insertion_Sort/
│   │   ├── 04_Merge_Sort/
│   │   ├── 05_Quick_Sort/
│   │   └── 06_STD_Sort/
│   ├── 10_Searching/
│   │   ├── 01_Linear_Search/
│   │   └── 02_Binary_Search/
│   ├── 11_Const_and_Headers/
│   └── 12_Integration/
└── 04_Integrated_Project/
    ├── data/
    ├── include/
    └── src/
```

Simple topics contain README.md and main.cpp. Divided topics contain lesson subfolders, a topic README and an integration main.cpp beside the subfolders. Extra headers are reused by integration examples.

## Scope

Manual lists and sorting implementations teach their mechanisms. Prefer standard containers and algorithms when they cover an application requirement. Trees here are binary trees and unbalanced BSTs; graph weights are nonnegative; the file DAO is a snapshot demonstration without a database or concurrent access. The fourth block contains structure only; we will implement its application later.

## Const and headers in each block

- [Functions and constants in structured programming](01_Structured_Programming/12_Const_and_Headers/README.md).
- [Const objects and methods in OOP](02_OOP/08_Headers/README.md).
- [Read-only structure queries in DSA](03_DSA/11_Const_and_Headers/README.md).
