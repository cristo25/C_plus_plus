# Sorting algorithms

We will connect this topic’s pieces before solving its integration task. Each link contains the program, comments and a practice task with requirements.

## Bubble sort

We will sort by comparing neighbors. If the left value is larger, we swap their positions; after a pass the largest remaining value ends up at the end. We can picture large bubbles rising. If a pass makes no swaps, we are done. When values are reversed, we make many comparisons; doubling the number of values can make them grow to almost four times as many. Already sorted values need just one pass. The complete function is in Sorts.h.

[Commented program](01_Bubble_Sort/main.cpp).

## Selection sort

We will find the smallest remaining value and place it at the beginning of the unsorted section. Then we repeat with the rest. We can picture choosing the smallest book from a pile and placing it in a row. Even if the numbers are already sorted, we keep finding the smallest in each group. Ten numbers take many comparisons; twenty take about four times as many. Swapping distant positions can change the order of tied elements.

[Commented program](02_Selection_Sort/main.cpp).

## Insertion sort

We will sort like arranging a hand of cards. We take a new value and shift larger earlier values until there is room for it. This keeps the left section sorted. If the values are already sorted, we pass through once. If they are reversed, we shift many values and do more work. By not moving a value ahead of an equal one, we preserve the order of ties.

[Commented program](03_Insertion_Sort/main.cpp).

## Merge sort

We will divide a pile into halves until the groups are small, then join them in order. We can picture two helpers sorting their sheets: when joining them, we always take the smallest available sheet. This is merge sort. We need extra space for merging, and it grows with the number of values. Each level visits all values, and there are as many levels as repeated halvings. For a tie we take the left value first to preserve order.

[Commented program](04_Merge_Sort/main.cpp).

## Quick sort

We will choose one value as a reference for separating the rest; we call it the pivot. We put smaller values on one side and repeat within each group. This is quick sort. With evenly split groups, each level checks all values and the levels grow through halving. Here we choose the last value: with sorted or equal input, almost everything can stay on one side and cause repeated work. This choice helps us see why the pivot matters.

[Commented program](05_Quick_Sort/main.cpp).

## Sorting with the standard library

We will compare our work with tools C++ already provides in <algorithm>. sort orders a range between begin() and end(); end() marks the position after the last value. For student records we provide a function deciding which comes first. The small function written with [] is called a lambda: here it receives two students and compares their grades with <. stable_sort preserves the earlier order of ties. After understanding manual movements, we can use this tool for a complete task.

[Commented program](06_STD_Sort/main.cpp).

## Sorting algorithms

We will check five ways of sorting using identical inputs. We create a copy for each algorithm and compare its result with sort. We include empty, negative, repeated and already sorted data. We keep function addresses to call each algorithm in the same way: just as a pointer can point to a box, a function pointer can point to a task we can run. If a comparison fails, we display the problem and stop.

[Commented program](main.cpp).

**Practice.** We will write an integrated sorting program.

- We will apply bubble, selection, insertion, merge and quick sort to copies of the same data.
- We will compare their results.
- We will try empty input, one element, negatives, duplicates and reverse order.
- We will count comparisons in at least two algorithms.
- We will explain why the same output can require different work.

[Back to the general guide](../../README.md).
