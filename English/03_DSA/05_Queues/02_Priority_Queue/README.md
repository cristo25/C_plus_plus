# Priority queues and heaps

## What you will learn

`priority_queue` uses a heap. By default the largest value is at the top; `greater<int>` puts the smallest there. `top` costs O(1), insertion and removal O(log n). Equal priorities do not preserve arrival order.

## Analogy

An emergency room serves patients by severity rather than arrival order.

## Run the example

Open a terminal **in this folder**. Use a compiler supporting C++17.

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
./program.exe
```

Output: `Highest priority: 9` and `Lowest cost: 2`.

## Practice

Remove every value from both queues. Explain why a heap is not a fully sorted vector.
