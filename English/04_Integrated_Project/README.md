# Campus library and routes

We will build a library where we can register books and organize deliveries between buildings. We will follow each operation from the menu to its data, using the classes and structures already studied.

This guide uses fragments. We can open the linked files to follow the whole program. The [Spanish version](../../Español/04_Proyecto_Integrador/README.md) contains the same application.

## 1. What the application does

We will choose operations from this menu. An ID is the number identifying a book; we use it to find the book even if its title changes.

| Option | Operation | Concepts used |
| --- | --- | --- |
| 1 | Show the catalog ordered by ID | Read-only pointer vector and sorting |
| 2 | Find a book by ID | Binary search over sorted IDs |
| 3, 4, 5 | Add, rename and remove books | OOP, validation, DAO and files |
| 6 | Undo the last catalog change | Stack of saved copies for undo |
| 7 | Request book delivery | Copied records and arrival-order queue |
| 8 | Process the next delivery | Graph, Dijkstra and path reconstruction |
| 9 | Inspect pending requests | Queue copying without consumption |
| 10 | View history forward or backward | Doubly linked list of indexes and message vector |
| 11 | Show the map and reachable buildings | Each building’s neighbors and exploration in layers |
| 0 | Close the session | Destructors and resource cleanup |

We save the catalog after each confirmed change. Pending deliveries, history and undo changes last only for the current session. When requesting delivery we copy the book record, preserving its title at that moment even if we later change or remove the catalog entry. Here we simulate deliveries without tracking physical book quantities.

## 2. Project organization

We will divide the work like a real library: someone serves the desk, someone keeps the catalog and someone reads the map. In the program we give each file group one responsibility.

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

In `.h` files we announce classes and operations; in `.cpp` files we write their steps. With `-Iinclude` we say where to find our headers. We reuse [BookDAO.h](../02_OOP/09_DAO/BookDAO.h), [DoublyLinkedList.h](../03_DSA/03_Linked_Lists/02_Doubly_Linked/DoublyLinkedList.h), [Searches.h](../03_DSA/10_Searching/Searches.h) and [Graph.h](../03_DSA/08_Graphs/Graph.h). We therefore keep this folder inside the course.

## 3. Compile and run

We open Git Bash in `English/04_Integrated_Project` and compile all the files forming this application:

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude src/main.cpp src/data/CatalogStore.cpp src/services/CampusMap.cpp src/services/Library.cpp src/ui/Console.cpp tests/SelfCheck.cpp -o build/library.exe
./build/library.exe
```

In PowerShell we create the folder with `New-Item -ItemType Directory -Force build`, then use the same compilation command. We run from the project folder so `data/catalog.txt` goes where intended. On Linux or macOS we can omit `.exe`.

```bash
./build/library.exe --demo
./build/library.exe --data "data/my_catalog.txt"
./build/library.exe --self-test
./build/library.exe --help
```

With `--demo` we practice with three books in memory. With `--data` we choose another file. With `--self-test` we run checks and finish without changing files. We choose one mode at a time. We need only C++17, its standard libraries and the course headers.

In `main` we receive command words through `argv`. For a path with accents or another alphabet, the terminal must supply UTF-8 text, a way to represent those characters. We can start with the default relative path; the program needs no Windows-specific functions.

## 4. A walkthrough to get started

We will run `--demo`. With option 1 we see books 10, 20 and 30 ordered by ID; with option 2 we find 20. Original records need not be stored in that order: we prepare a sorted selection for queries.

With option 7 we request book 10 from building 0 to building 4. We inspect the queue with 9 and process it with 8. We obtain:

```text
Library -> Engineering -> Laboratory -> Administration -> Residences | 7 minutes
```

We then add a book with 3 and undo the change with 6. With 10 we traverse history in both directions. For building 5 we report no route and do not queue that delivery. We also try `2abc` or an unknown option: we request a corrected value before continuing.

## 5. OOP and DAO: assigning responsibilities

In [Library.h](include/services/Library.h) we gather book and delivery rules. In [Console.h](include/ui/Console.h) we ask questions and show answers. This lets us change the menu without changing book storage.

With the DAO we gather creating, finding, updating and removing records. To save them we turn their data into text; we call that serialization. In [CatalogStore.h](include/data/CatalogStore.h) we offer two ways to keep them:

```cpp
class CatalogStore {
public:
    virtual ~CatalogStore() = default;
    virtual BookDAO load() const = 0;
    virtual void save(const BookDAO& dao) = 0;
};
```

With `MemoryStore` we keep them while the demonstration runs. With `FileStore` we save them to disk. We request `load` and `save` through a `CatalogStore` reference; thanks to `virtual`, we use the chosen variant's steps. This is the instrument idea again: one common request, different ways to fulfill it.

## 6. Ownership, references and pointers

We will distinguish who releases an object from who only reads it. In [main.cpp](src/main.cpp) a `unique_ptr<CatalogStore>` takes responsibility for the store. We pass references to objects needing it. We also pass `cin` and `cout` to the console to indicate where to read and write:

```cpp
Library library(*store);
Console console(library, cin, cout);
console.run();
```

We can picture boxes and labels. `*store` leads to the store's box; the reference hands over another label for that same box. We keep the store until after Library ends. When receiving `const Book&` or `const string&`, we can read the original without copying or changing it through that reference.

View pointers are address cards. A delivery instead holds its own record. Changing the catalog may make older address cards unusable; the delivery's copied record keeps its data.

## 7. Pointer vector and binary search

We will sort cards to query books without moving their original boxes. In [Library.cpp](src/services/Library.cpp) we collect book addresses in a vector and sort those addresses by ID:

```cpp
vector<const Book*> view;
for (const Book& book : dao.all()) {
    view.push_back(&book);
}
sort(view.begin(), view.end(), [](const Book* left, const Book* right) {
    return left->id < right->id;
});
```

The small function written with `[]` compares two books and decides which comes first. We call it a lambda. We then collect their IDs in the same order and search by halves:

```cpp
const auto position = binarySearch(ids, id);
if (!position) {
    return nullptr;
}
return view[*position];
```

The search returns `optional<size_t>`: a small box containing a position or nothing. Position zero also counts as found. For an empty result we return `nullptr`; otherwise we lend the corresponding book address. We use it before changing the catalog, because adding, removing, renaming or undoing replaces its books and makes old addresses unusable.

Once sorted, we discard about half the possible books at each step. If we start with 16, we keep 8, then 4, 2 and 1. Before searching, we must also collect and sort the cards; that takes work too.

## 8. Structs and the delivery queue

We will prepare one record per delivery. In [Delivery.h](include/models/Delivery.h) we store a book copy and the departure and arrival positions:

```cpp
struct Delivery {
    Book book;
    size_t source;
    size_t target;
};
```

Before adding it we check that the book and a route exist. We keep records in `queue<Delivery>` and serve in arrival order: first in, first out. We also call that rule FIFO. To inspect pending requests we traverse a copy of the queue, keeping the requests in place while displaying them.

When serving, we calculate the route, record the result and remove the first request. We return data owned by the completed delivery so we can still display it after removing the request from the queue.

## 9. Graph, BFS and Dijkstra

We will represent buildings with points and roads with connections. In [CampusMap.cpp](src/services/CampusMap.cpp) we keep names in a `vector<string>`; their positions are building numbers. In the graph we keep the roads leaving each building. To allow both directions we add a connection each way.

| Connection | Minutes |
| --- | --- |
| 0 Library ↔ 1 Laboratory | 4 |
| 0 Library ↔ 2 Engineering | 1 |
| 2 Engineering ↔ 1 Laboratory | 1 |
| 1 Laboratory ↔ 3 Administration | 3 |
| 2 Engineering ↔ 3 Administration | 6 |
| 3 Administration ↔ 4 Residences | 2 |

We leave building 5 isolated. With BFS we explore in layers to see which buildings we can reach. For the shortest travel time we use Dijkstra: we process the cheapest known candidate first and update when a better path appears.

```cpp
if (candidate < result.distances[edge.destination]) {
    result.distances[edge.destination] = candidate;
    result.predecessors[edge.destination] = current;
    queuePending.push({candidate, edge.destination});
}
```

In `predecessors` we remember which building led to each destination; that previous building is called its predecessor. `shortestPaths` keeps costs and predecessors; `dijkstra` returns only costs. We rebuild the route backward from the destination, then reverse it:

```cpp
while (cursor != source) {
    route.stops.push_back(cursor);
    const auto previous = result.predecessors[cursor];
    if (!previous) {
        throw logic_error("The route has an invalid predecessor link");
    }
    cursor = *previous;
}
```

From 0 to 4 we pass through 2, 1 and 3: we add `1 + 1 + 3 + 2 = 7`. For no route we return `nullopt`, an empty result. Traveling from a place to itself costs zero. We reject negative minutes and check that sums fit within the largest number we can store.

## 10. Doubly linked list and message vector

We will store messages and their viewing order in two structures:

```cpp
vector<string> events;
DoublyLinkedList order;
```

In the vector we keep each message's text. In each list node we keep its position, like a page number. If the vector moves to a larger space, those numbers still work because we only append messages; we neither erase nor reorder them.

```text
List:   [0] <-> [1] <-> [2]
         |       |       |
Vector: message message message
```

With the doubly linked list we move to the next or previous message. We release its nodes when finished. When the console requests history, we return copies of the text; it does not need to change or know the list's internal arrows.

## 11. Stack, candidate changes and saving

We will prepare each change in a catalog copy. If it follows the rules, we keep the previous state on a stack so we can undo. If writing fails, we remove that new saved state and retain the earlier catalog:

```cpp
undo.push(dao);
try {
    store.save(candidate);
} catch (...) {
    undo.pop();
    throw;
}
swap(dao, candidate);
```

With `try` we attempt saving; with `catch` we handle an error. `throw` passes it on so the console can display it. After saving we use `swap`: `dao` gets the new catalog, and `candidate` gets the old one. If saving fails, we do not make that exchange, so we keep the books we already had. To undo, we work in reverse change order: last in, first out, also called LIFO. Each copy needs space; for many books and changes, we could save only the data needed to reverse each operation.

In [CatalogStore.cpp](src/data/CatalogStore.cpp) we first write a temporary `.tmp` file. We then keep the previous file as a `.bak` backup and put the new one in place. If replacement fails, we try to restore the earlier file. If only the backup remains on reopening, we read it. For damaged data we report the issue and preserve the file for inspection.

We store text in this form:

```text
2
10
C++ fundamentals
20
Book with "quotes"
```

The first line gives the book count. We then use two lines per book: its ID and its title. This keeps spaces and quotation marks in the title. We allow up to 10,000 books, distinct positive IDs and nonempty titles up to 200 bytes. A byte is a unit of memory; some letters occupy several. We reject line breaks and other control characters in titles. We use this storage from one running program at a time; several applications writing together would need coordinated changes, for example through a database. The backup helps recovery but does not guarantee preserving the latest write during a power failure.

## 12. Input, errors and the runnable check

We will read each complete answer with `getline` in [Console.cpp](src/ui/Console.cpp). We then use `istringstream` from `<sstream>` as a reader for that text: we try to obtain an integer and check that no other character remains. This rejects `12abc`. When input ends, we close the session; we also call that end of input EOF. We do not save an unfinished operation.

In [SelfCheck.cpp](tests/SelfCheck.cpp) we try searches, routes, delivery order, undo, history and incorrect input. We also simulate a saving failure to check that the previous books remain. We use ordinary conditions that stay active when compiling the final version.

```bash
./build/library.exe --self-test
```

If everything matches, we finish with 0; for a failure we display the case and return 1. To try files we run without `--demo`, add a title containing quotes, close and reopen: we should recover the same title.

## 13. Costs and further practice

We will think about which tasks need more steps as the data grows. Searching ten books usually takes less work than searching a thousand. Each row describes what the program must visit or copy.

| Operation | What work it performs as data grows |
| --- | --- |
| Prepare the sorted view | Collects and sorts book addresses. More books mean more cards to arrange. |
| Search already sorted IDs | Discards half the candidates at each step. |
| Copy for undo | Copies each record and title; long titles need more space. |
| Add an item to history | Adjusts a few arrows without visiting earlier messages. |
| Inspect history | Visits each message and copies its text. |
| Inspect pending requests | Visits each request and copies its data. |
| BFS | Visits reachable buildings and checks the roads between them. |
| Dijkstra | Inspects connections and maintains a queue for selecting the cheapest candidate. More candidates need more adjustments, and a building may have repeated records. |
| Reconstruct the path | Follows route buildings backward from the target; it visits at most every building. |

While loading, we compare each book with those already read to detect repeated numbers. With many books, we repeat these comparisons many times. We can begin with a few books and observe every step; the [complexity lesson](../03_DSA/01_Complexity/main.cpp) names these patterns of growth.

## 14. Integration practice

**Practice.** Write an integrated library and delivery application.

- Organize models, data, services and interface into folders with .h and .cpp files.
- Add, find, update and remove books through a DAO.
- Search ids through a sorted view and binary search.
- Keep history in a doubly linked list and pending deliveries in a queue.
- Use a stack to undo catalog changes.
- Represent buildings as a graph and calculate routes with Dijkstra.
- Save data and restore it after restarting.
- Validate input and preserve the catalog when writing fails.

## 15. Why we use each library

Here we collect the tools appearing in the project. We can revisit the example introducing each before following an operation using it.

| Library | Why we use it |
| --- | --- |
| `<algorithm>` | We sort data with sort or reverse their order with reverse. |
| `<cstddef>` | We use size_t to count elements and represent nonnegative positions. |
| `<exception>` | We catch errors through exception and read their message with what(). |
| `<filesystem>` | We handle paths, folders and file renaming. |
| `<fstream>` | We read and save files using ifstream and ofstream. |
| `<istream>` | We receive an input source: keyboard, file or text in memory. |
| `<limits>` | We use numeric_limits to check the largest allowed integer before adding. |
| `<memory>` | We use unique_ptr to release its managed object automatically. |
| `<optional>` | We store a result that may be missing: optional holds a value or is empty. |
| `<ostream>` | We receive an output destination: screen, file or text in memory. |
| `<queue>` | We serve by arrival with queue or by importance with priority_queue. |
| `<sstream>` | We read or write text in memory as if it were a file. |
| `<stack>` | We store a stack: with stack, the last item in comes out first. |
| `<stdexcept>` | We report errors with messages, such as invalid_argument for an invalid value. |
| `<string>` | We store and work with text using string. |
| `<system_error>` | We check file-operation failures using error_code. |
| `<utility>` | We use swap to exchange two catalogs. |
| `<vector>` | We store a collection that can grow using vector. |
