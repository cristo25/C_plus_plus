# Queues

Compare arrival order and priority order. The integration example produces `2 9 4` with FIFO and `9 4 2` with priority.

## Study order

1. [FIFO queue](01_With_Queue/main.cpp)
2. [Priority queues and heaps](02_Priority_Queue/main.cpp)

After finishing the subfolders, read and run the `main.cpp` **in this folder**. It combines what you learned in the individual lessons.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Every subfolder has its own program. Compile one example at a time: each has its own `main` function.
