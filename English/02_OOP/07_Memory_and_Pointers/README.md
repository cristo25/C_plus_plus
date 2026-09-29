# Memory and pointers in OOP

Connect ownership to object lifetime. The integration example owns a student through `unique_ptr` and queries it through a non-owning pointer.

## Study order

1. [Manual dynamic memory](01_New_and_Delete/main.cpp)
2. [Ownership with unique_ptr](02_Unique_Ptr/main.cpp)

After finishing the subfolders, read and run the `main.cpp` **in this folder**. It combines what you learned in the individual lessons.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Every subfolder has its own program. Compile one example at a time: each has its own `main` function.

To combine these concepts, follow the [route through arrays, views and classes with nodes](../../03_DSA/13_Combining_Concepts/README.md). It explains which pointers remain valid as a vector grows and which are invalidated.
