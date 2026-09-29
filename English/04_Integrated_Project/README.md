# Campus library and routes

A console application for managing books and requesting deliveries between buildings. Its purpose is to connect course tools around concrete operations: inspecting, changing, saving, queueing, traversing and finding a route.

This guide's snippets show parts of the implementation, rather than independent programs. Follow the links to read complete declarations and methods; code comments also explain the decisions. The [Spanish version](../../Español/04_Proyecto_Integrador/README.md) has the same behavior.

## 1. What the application does

| Option | Operation | Concepts used |
| --- | --- | --- |
| 1 | Show the catalog ordered by ID | Read-only pointer vector and sorting |
| 2 | Find a book by ID | Binary search over sorted IDs |
| 3, 4, 5 | Add, rename and remove books | OOP, validation, DAO and files |
| 6 | Undo the last catalog change | LIFO stack of snapshots |
| 7 | Request book delivery | Structs, object copying and FIFO queue |
| 8 | Process the next delivery | Graph, Dijkstra and path reconstruction |
| 9 | Inspect pending requests | Queue copying without consumption |
| 10 | View history forward or backward | Doubly linked list of indexes and message vector |
| 11 | Show the map and reachable buildings | Adjacency lists and BFS |
| 0 | Close the session | Destructors and resource cleanup |

The catalog is saved after every committed change and undo operation. Requests, history and the stack belong to the current session. A request retains the book title at submission; later renaming or removing its catalog entry does not alter that request. We simulate delivery without tracking physical stock or borrowing.

## 2. Project organization

```text
04_Integrated_Project/
├── README.md
├── include/
│   ├── models/Delivery.h
│   ├── data/CatalogStore.h
│   ├── services/CampusMap.h
│   ├── services/Library.h
│   ├── ui/Console.h
│   └── testing/SelfCheck.h
├── src/
│   ├── main.cpp
│   ├── data/CatalogStore.cpp
│   ├── services/CampusMap.cpp
│   ├── services/Library.cpp
│   └── ui/Console.cpp
├── tests/SelfCheck.cpp
└── data/                        Catalog generated at runtime
```

| Part | Responsibility |
| --- | --- |
| Models | Describe a request, a route and a completed delivery |
| Store | Load and save the DAO in memory or in a file |
| Map | Connect buildings and calculate routes |
| Library | Apply rules and coordinate the catalog, queue, stack and history |
| Console | Request data, present results and show errors |
| main | Select an execution mode and connect objects |
| Check | Verify the main flows without manual interaction |

Headers declare contracts and `.cpp` files implement operations. Includes use `-Iinclude`; `.cpp` files are never included. We reuse [BookDAO.h](../02_OOP/09_DAO/BookDAO.h), [DoublyLinkedList.h](../03_DSA/03_Linked_Lists/02_Doubly_Linked/DoublyLinkedList.h), [Searches.h](../03_DSA/10_Searching/Searches.h) and [Graph.h](../03_DSA/08_Graphs/Graph.h), rather than copying them. Keep this project inside the course.

## 3. Compile and run

Open Git Bash **in this folder**, `English/04_Integrated_Project`. You need C++17 and `g++`:

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude src/main.cpp src/data/CatalogStore.cpp src/services/CampusMap.cpp src/services/Library.cpp src/ui/Console.cpp tests/SelfCheck.cpp -o build/library.exe
./build/library.exe
```

In PowerShell, create the folder with `New-Item -ItemType Directory -Force build`; the compilation command is the same. Run from the project root because the default catalog path is `data/catalog.txt`. On Linux or macOS you can omit `.exe`.

```bash
./build/library.exe --demo
./build/library.exe --data "data/my_catalog.txt"
./build/library.exe --self-test
./build/library.exe --help
```

`--demo` prepares three books in memory for practice without creating a catalog on disk. `--data` selects another file. `--self-test` runs the check and exits without changing files. These are alternative modes and cannot be combined. No additional libraries need to be installed.

On Windows, `main.cpp` obtains arguments through native Unicode APIs to preserve paths such as `Español` and names using other alphabets. That part is inside `#ifdef _WIN32`; other systems use `argv`. The rest of the application uses the standard library and course headers.

## 4. A walkthrough to get started

Run `--demo`. The catalog starts with IDs 10, 20 and 30, although its owning vector is not sorted. Choose option 1 to display them in order and option 2 to find ID 20.

Then choose option 7, enter book 10, source 0 and target 4. Inspect pending requests with 9 and process the request with 8. You will see:

```text
Library -> Engineering -> Laboratory -> Administration -> Residences | 7 minutes
```

Add a book with 3, inspect the catalog and undo with 6. Option 10 traverses history in both directions. Requesting delivery to building 5 reports no connection and does not enqueue an impossible request. Entering `2abc`, an out-of-range number or an unknown option requires correcting the input.

## 5. OOP and DAO: assigning responsibilities

[Library.h](include/services/Library.h) composes the DAO, map and session structures. It does not read the keyboard or print menus. [Console.h](include/ui/Console.h) provides that interface without deciding how to save books.

The existing DAO manages `Book`, enforces unique IDs and serializes titles containing spaces and quotes. [CatalogStore.h](include/data/CatalogStore.h) defines two actual ways to retain it:

```cpp
class CatalogStore {
public:
    virtual ~CatalogStore() = default;
    virtual BookDAO load() const = 0;
    virtual void save(const BookDAO& dao) = 0;
};
```

`MemoryStore` serves demonstration mode. `FileStore` serves persistent mode. The service works with a reference to the base class, and `virtual` selects the implementation. Inheritance and polymorphism arise from a concrete difference in the application.

## 6. Ownership, references and pointers

In [main.cpp](src/main.cpp), a `unique_ptr<CatalogStore>` owns the selected implementation. `Library` receives a reference; `Console` receives references to the library and streams. Objects are declared in that order and destroyed in reverse order:

```cpp
Library library(*store);
Console console(library, cin, cout);
console.run();
```

The store must outlive the library. `*store` accesses the managed object without transferring ownership. `const Book&` and `const string&` parameters inspect arguments without copying them. Storing a `Book` **as a value member** of a request does create an independent copy.

Imagine the DAO as a drawer of records, references as extra labels on its boxes and pointers as cards holding addresses. The sorted view holds cards; a request holds its own record. Changing the drawer can invalidate borrowed cards while the copied record continues to exist.

## 7. Pointer vector and binary search

[booksSorted()](src/services/Library.cpp) builds a read-only view:

```cpp
vector<const Book*> view;
for (const Book& book : dao.all()) {
    view.push_back(&book);
}
sort(view.begin(), view.end(), [](const Book* left, const Book* right) {
    return left->id < right->id;
});
```

Books are not copied and the DAO is not rearranged: we sort their addresses. Then `findById()` builds IDs from that view and calls the course binary search:

```cpp
const auto position = binarySearch(ids, id);
if (!position) {
    return nullptr;
}
return view.at(*position);
```

The essential condition is that IDs are sorted. `optional<size_t>` distinguishes absence from a valid index, including zero. The returned pointer observes a DAO book; it must not be used after adding, removing, renaming or undoing a change because we replace the entire catalog. The console uses it immediately; deliveries copy the book before any subsequent mutation.

Once IDs are sorted, each comparison discards half the candidates. Doubling the book count adds about one comparison to that search (O(log n), where n is the book count and log n describes growth through halving). However, this code first collects and sorts every book address. That preparation also counts: its comparison bound grows like the book count multiplied by the number of halving levels (O(n log n)). The entire query therefore takes more work than searching an already prepared view.

## 8. Structs and the delivery queue

[Delivery.h](include/models/Delivery.h) groups a record and two map positions:

```cpp
struct Delivery {
    Book book;
    size_t source;
    size_t target;
};
```

Before queueing, the service checks that the book exists and a route is available. A `queue<Delivery>` processes requests in arrival order: first in, first out. Viewing pending requests traverses a copy so inspecting them does not consume them.

Processing prepares a `CompletedDelivery`, records the result and then removes the queue front. The returned result owns its data; it is not a reference to an element we just removed.

## 9. Graph, BFS and Dijkstra

[CampusMap.cpp](src/services/CampusMap.cpp) maintains an `array<string, 6>` of names and an adjacency-list `Graph`. Array positions are vertex IDs. A bidirectional road is stored as two directed edges.

| Connection | Minutes |
| --- | --- |
| 0 Library ↔ 1 Laboratory | 4 |
| 0 Library ↔ 2 Engineering | 1 |
| 2 Engineering ↔ 1 Laboratory | 1 |
| 1 Laboratory ↔ 3 Administration | 3 |
| 2 Engineering ↔ 3 Administration | 6 |
| 3 Administration ↔ 4 Residences | 2 |

Annex 5 is isolated. BFS reports reachable buildings; it does not calculate minimum time when weights differ. Dijkstra uses a priority queue to improve known costs:

```cpp
if (candidate < result.distances.at(edge.destination)) {
    result.distances.at(edge.destination) = candidate;
    result.predecessors.at(edge.destination) = current;
    queuePending.push({candidate, edge.destination});
}
```

`shortestPaths()` adds predecessors to the existing algorithm. `dijkstra()` retains the earlier distances-only API for other course examples. The project reconstructs the path by following predecessors backward from the target, then reversing it:

```cpp
while (cursor != source) {
    route.stops.push_back(cursor);
    const auto previous = result.predecessors.at(cursor);
    if (!previous) {
        throw logic_error("The route has an invalid predecessor link");
    }
    cursor = *previous;
}
```

For 0 to 4, going through 2 improves the direct connection to 1: the cost is `1 + 1 + 3 + 2 = 7`. No route is represented by `nullopt`; going from a building to itself costs zero. Dijkstra requires nonnegative weights; the graph rejects negative weights and checks addition for overflow.

## 10. Doubly linked list and message vector

History combines two structures:

```cpp
vector<string> events;
DoublyLinkedList order;
```

The vector owns messages. Each list node holds a message index, rather than a pointer into the vector. If vector growth reallocates storage, indexes still work because we append messages without rearranging or deleting them. The list links that order and allows traversal in both directions.

```text
List:   [0] <-> [1] <-> [2]
         |       |       |
Vector: message message message
```

The course list releases its nodes in its destructor and disables owner copying. No node is exposed to the console. `history()` collects message copies by following indexes, so the interface does not need to know the internal links.

## 11. Stack, candidate changes and saving

A change operates on a DAO copy. If it breaks the rules, it never reaches saving. On commit, the stack retains the previous state; if the store fails, the new snapshot is removed and the catalog is not replaced:

```cpp
undo.push(dao);
try {
    store.save(candidate);
} catch (...) {
    undo.pop();
    throw;
}
dao = move(candidate);
```

Undo saves the previous state, installs it and only then removes the stack top. The stack is LIFO: the latest change is reversed first. Full snapshots are easy to follow, but memory grows with catalog size and change count; a larger application would benefit from inverse commands or a transactional log.

[CatalogStore.cpp](src/data/CatalogStore.cpp) writes a snapshot to `.tmp`, checks closing, moves the previous catalog to `.bak` and installs the new file. If replacement fails, it attempts to restore the previous file. If an interruption leaves only `.bak`, the next load reads it. A corrupt catalog is rejected and retained for inspection.

The format reuses DAO serialization:

```text
2
10 "C++ fundamentals"
20 "Book with \"quotes\""
```

The first line gives the number of books that follow. The limit is 10000, IDs are unique positive integers and titles contain text, no control characters and at most 200 bytes. Replacement with a backup is intended for a local single-process application; it does not replace database transactions or guarantee durability through power loss. Generated catalogs, `.tmp` and `.bak` files are not uploaded to the repository.

## 12. Input, errors and the runnable check

[Console.cpp](src/ui/Console.cpp) uses `getline` to avoid partial reads. It then converts the line to an integer and verifies that no characters remain. EOF ends the session even halfway through an operation; incomplete changes are never committed. Validation and save errors are displayed while the menu remains usable.

[SelfCheck.cpp](tests/SelfCheck.cpp) verifies empty and sorted catalog searching, routes and an isolated target, FIFO queue, LIFO stack, reverse history, independent requests, recovery after a simulated save failure, invalid input and EOF. Its conditions stay active with `NDEBUG`.

```bash
./build/library.exe --self-test
```

A successful check returns exit code 0; failure identifies the case and returns 1. To check persistence manually, run without `--demo`, add a title containing quotes, close and reopen: the catalog should retain it.

## 13. Costs and further practice

Here we count work and memory separately. Letters simply abbreviate quantities: n is the book count, h the history-message count, p the pending-request count, V the building count and E the connection count. Parenthesized notation summarizes how work grows; it does not give exact seconds or bytes.

| Operation | What work it performs as data grows |
| --- | --- |
| Prepare the sorted view | Collects and sorts addresses. The comparison bound combines the book count with the levels in repeated halving (O(n log n)). |
| Search already sorted IDs | Discards half the candidates each step; doubling the books adds about one comparison (O(log n)). |
| Copy for undo | Copies one record per book, plus all title characters (O(n) for records; longer titles also require more work and memory). |
| Append a history index | Adjusts a few links without traversing earlier messages (O(1)). |
| Inspect history | Visits its h messages and copies their text (O(h) visits, plus character copying). |
| Inspect pending requests | Visits its p requests and copies their data (O(p) visits, plus title copying). |
| BFS | Visits reachable buildings and inspects their connections; if all are reachable, it processes the entire map (O(V + E)). |
| Dijkstra | Inspects connections and maintains a queue for selecting the cheapest candidate. More candidates need more adjustments, and a building may have repeated records. |
| Reconstruct the path | Follows route buildings backward from the target; it visits at most all V buildings (O(V)). |

While loading, the DAO compares each new book with those already read to detect duplicate IDs. With n books, these checks accumulate: first a few, then more, and the work can grow like n multiplied by n (O(n²)). The project prioritizes reading and connecting its pieces; each cost follows a decision that can be changed for a concrete need.

For practice, change a weight and predict the route, connect the annex, try IDs at the beginning and end, or extend the check with another input error. Before adding a structure, explain which operation it would improve. A tree or hash table may serve another query pattern, but every current structure already supports an actual operation.
