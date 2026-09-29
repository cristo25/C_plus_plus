# Sorting algorithms

Study algorithms using the same input and compare time, memory and stability. Stability preserves the original order of elements with equal keys. The integration example checks five algorithms against `sort`, including empty input, duplicates, negatives and sorted values. Function pointers allow repeating the same check.

## Study order

1. [Bubble sort](01_Bubble_Sort/README.md)
2. [Selection sort](02_Selection_Sort/README.md)
3. [Insertion sort](03_Insertion_Sort/README.md)
4. [Merge sort](04_Merge_Sort/README.md)
5. [Quick sort](05_Quick_Sort/README.md)
6. [Sorting with the standard library](06_STD_Sort/README.md)

After finishing the subfolders, read and run the `main.cpp` **in this folder**. It combines what you learned in the individual lessons.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Every subfolder has its own program. Compile one example at a time: each has its own `main` function.
