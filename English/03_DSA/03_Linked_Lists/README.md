# Linked lists

All three implementations store integers to focus on links and ownership. Manual `new/delete` teaches the mechanism; standard containers manage storage for common applications. The integration example uses all three headers and removes 20 from each list. Compare traversals, then remove the first node, the last node and the only node.

## Study order

1. [Singly linked list](01_Singly_Linked/README.md)
2. [Doubly linked list](02_Doubly_Linked/README.md)
3. [Circular linked list](03_Circular/README.md)

After finishing the subfolders, read and run the `main.cpp` **in this folder**. It combines what you learned in the individual lessons.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Every subfolder has its own program. Compile one example at a time: each has its own `main` function.
