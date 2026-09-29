# Vectors

We will connect this topic’s pieces before solving its integration task. Each link contains the program, comments and a practice task with requirements.

## Creating and traversing a vector

We will use a drawer whose number of slots can grow: vector<int>, from <vector>. With push_back we add at the end; with size we check how many values it holds. We visit the numbers to add them. When reserved space fills up, the vector can move to another block with its data; old addresses no longer work. Usually adding at the end takes little work; spreading those moves across many insertions keeps average work per insertion bounded (amortized O(1): we spread growth costs across many operations).

[Commented program](01_Create_and_Traverse/main.cpp).

## Inserting and erasing in vectors

We will open and remove spaces in the middle of a vector. With begin() we obtain a position pointing to the start; begin() + 1 points to the second element. We call this way of pointing to a position an iterator. insert places a value and shifts later ones; erase removes a value and closes the gap. This may move nearly all n elements (O(n)). After changing the vector we obtain needed positions again. Before pop_back we check empty so we do not remove from an empty vector.

[Commented program](02_Insert_and_Erase/main.cpp).

## Vectors of objects

We will store complete records inside the vector. With struct Student we group a name and a grade, like two boxes on one card. vector<Student> holds those cards and push_back adds another. With const auto& we read each card without copying it: auto lets C++ infer the type, & gives another label for the same object, and const prevents changes through that label. We use a dot to choose a field on the card.

[Commented program](03_Vector_of_Objects/main.cpp).

## Vectors

We will combine creation, editing and object records in a task list. Each Task stores its name and whether it is finished. We insert a task, mark another and remove a record. We can picture a notebook where we add and remove rows. The vector keeps the data together, but positions may change when inserting or erasing; we therefore distinguish a task's name from its current position.

[Commented program](main.cpp).

**Practice.** Write an integrated task program using vector.

- Store each task name and status in a struct.
- Add one task at the end and another in the middle.
- Mark a task as finished.
- Remove a task and display the rest.
- Check positions before using them.

[Back to the general guide](../../README.md).
