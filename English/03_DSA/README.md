# Data structures and algorithms

We will connect this topic’s pieces before solving its integration task. Each link contains the program, comments and a practice task with requirements.

## Complexity: time and space

We will compare how much work we do as data grows. Reaching a slot directly takes a fixed amount of work even with more slots (O(1); it does not mean exactly one step). Checking ten slots means ten visits, and checking twenty means twenty (O(n), where n is the slot count). By halving, we go from 8 to 1 in three divisions and from 16 to 1 in four (O(log n), where log n describes growth through halving). We call these abbreviations Big O notation: they describe growth, not exact seconds. We can also count extra data kept while doing the task; we call that auxiliary memory.

[Commented program](01_Complexity/main.cpp).

## Vectors

We will combine creation, editing and object records in a task list. Each Task stores its name and whether it is finished. We insert a task, mark another and remove a record. We can picture a notebook where we add and remove rows. The vector keeps the data together, but positions may change when inserting or erasing; we therefore distinguish a task's name from its current position.

[Commented program](02_Vectors/main.cpp).

## Linked lists

We will compare all three lists using the same numbers. In the singly linked list we follow one arrow, in the doubly linked list we can go back, and in the circular list we return to the beginning. We insert 10, 20 and 30, remove 20 and check what remains. The main difference is how we link nodes and when traversal stops. We can draw the same three boxes and change only their arrows to understand it.

[Commented program](03_Linked_Lists/main.cpp).

## Stacks

We will compare a stack built with vector against one using stack. We put 1, 2 and 3 into both and remove from the top. In both, 3 must come out first. We are practicing the removal order: that rule defines a stack even when we use different storage tools.

[Commented program](04_Stacks/main.cpp).

## Queues

We will put the same values into a normal queue and a priority queue. After storing 2, 9 and 4, the first keeps that order; the second serves 9 first. This helps us decide which rule an application needs: respecting arrival or choosing by importance. Changing the structure changes the service rule even with identical data.

[Commented program](05_Queues/main.cpp).

## Trees

We will integrate tree operations: insertion, search, traversal and removal. We use Tree.h to follow the same links in every case. First we check an empty tree, add values, compare its traversals and finally remove all nodes. We can picture maintaining a tree of folders: each change must preserve access to branches that still exist.

[Commented program](06_Trees/main.cpp).

## Hash tables with unordered_map

We will search by a key, like finding a student card by registration number. unordered_map connects a key to a value; here, a number to a name. Internally it uses a hash function, which calculates the group where a key should be sought. With find we search without creating a card; end() means it is missing. In a found card, first is the key and second the value. We do not expect cards to appear in order. Usually we inspect few entries, but many keys landing together may require many checks.

[Commented program](07_Hash_Tables/main.cpp).

## Graphs

We will use one map to answer different questions. With BFS we explore in layers; with DFS we follow a branch before returning; with Dijkstra we find the lowest total cost. We share Graph.h so every test uses the same map. We can compare traversal orders, but we do not treat BFS or DFS order as a list of costs: each tool answers a different question.

[Commented program](08_Graphs/main.cpp).

## Sorting algorithms

We will check five ways of sorting using identical inputs. We create a copy for each algorithm and compare its result with sort. We include empty, negative, repeated and already sorted data. We keep function addresses to call each algorithm in the same way: just as a pointer can point to a box, a function pointer can point to a task we can run. If a comparison fails, we display the problem and stop.

[Commented program](09_Sorting/main.cpp).

## Searching

We will compare one-by-one search with halving search. First we search unsorted data, then sort and try both methods on the same vector. The number stays the same, but sorting can change its position. We also count the preparation: building a sorted list is extra work, even if searching within it afterward is faster.

[Commented program](10_Searching/main.cpp).

## Const and headers in DSA

We will query a collection without changing it. With const vector<int>& we receive another label for the same vector, but only for reading. In Queries.h we announce the function; in Queries.cpp we traverse the values and count those above a limit. We need neither copying nor sorting. Doubling the data doubles the visits (O(n), with n elements). We add only a counter and a few variables (O(1) additional memory).

[Commented program](11_Const_and_Headers/main.cpp).

## Integration: processing tasks and querying routes

We will bring the structures together in a task-and-delivery workshop. We store tasks in a vector, serve them through a queue and record events in a list. With a stack we inspect the latest action that could be undone. We use a tree and an id table to practice queries, and sort numbers before searching by halves. Finally we use a graph to calculate routes. Each structure serves a different need; this example brings them together to show how data moves between them.

[Commented program](12_Integration/main.cpp).

## Integration: owners, views, matrices and sorting

We will combine the layers to display sorted products without moving their original boxes. We store shelves in a vector; each shelf contains nodes and each node a product. We collect node addresses in view and sort only those cards by price. Then we choose cards for a display matrix. One card may appear several times: counting occupied slots does not count distinct products. We calculate total value from the shelves so a repeated display does not count the product twice.

[Commented program](13_Combining_Concepts/main.cpp).

[Back to the general guide](../README.md).
