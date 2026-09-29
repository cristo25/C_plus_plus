# Combining concepts: from a drawer to an inventory with views

Knowing what a pointer is does not yet tell you where to use it. Here we start with a need and change the representation when a new need appears. We keep `Product`, the class from the [OOP headers topic](../../02_OOP/08_Headers/Product.h), so we can focus on how the concepts combine.

Before starting, run [references](../../01_Structured_Programming/06_Functions/02_References/main.cpp) and [basic pointers](../../01_Structured_Programming/09_Basic_Pointers/main.cpp). Follow the steps; each `main.cpp` explains its operations in comments. Finish with this folder's [integration example](main.cpp).

## Route

| Step | Program | Decision we learn |
| --- | --- | --- |
| 1 | [Array of classes](01_Array_of_Classes/main.cpp) | Store complete objects |
| 2 | [Array of structs with classes](02_Array_of_Structs_with_Classes/main.cpp) | Group an object with its stock count |
| 3 | [Array of pointers](03_Array_of_Pointers/main.cpp) | Separate a card from its target |
| 4 | [Vector of pointers](04_Vector_of_Pointers/main.cpp) | Grow a view without copying products |
| 5 | [Matrix of pointers](05_Matrix_of_Pointers/main.cpp) | Organize views by rows and slots |
| 6 | [Array of linked nodes](06_Array_of_Linked_Nodes/main.cpp) | Separate physical location from logical order |
| 7 | [Vector of unique_ptr](07_Vector_of_Unique_Ptr/main.cpp) | Give each dynamic object an owner |
| 8 | [Class with struct nodes](08_Class_with_Nodes/main.cpp) | Encapsulate a chain and its operations |
| 9 | [Vector of classes with nodes](09_Vector_of_Classes_with_Nodes/main.cpp) | Group lists and distinguish what moves |

## 1. What does an array of classes actually store?

We want three products. `array<Product, 3>` is a drawer with three compartments: each contains a complete object with its name and price. The class defines each object; the array defines how many fit and how to visit them. We do not need addresses for every operation: a reference to a compartment is enough to inspect its product.

```cpp
const Product& product = products.at(0);
cout << product.getName() << "\n";
```

The reference does not create an extra product. `at(0)` checks the index; indexes start at zero. When the array's lifetime ends, so do those of its contained objects.

## 2. How do I add data belonging to the same record?

Now we need stock counts. A `Record` contains a `Product` and an integer. The array holds records; each record holds an object of a class. These are layers of composition, rather than competing concepts.

```cpp
struct Record {
    Product product;
    int quantity;
};

void receiveOne(Record& record) {
    if (record.quantity < 0 || record.quantity == numeric_limits<int>::max()) {
        throw invalid_argument("Invalid quantity");
    }
    ++record.quantity;
}
```

`records.at(0).product` reaches the object and `records.at(0).quantity` reaches the number. Passing the record by reference changes the original record. Passing it by value would change another record. `struct` has public access by default; `class` has private access. Both can have methods and contain objects of the other.

## 3. What changes when a compartment holds an address?

`array<int*, 3>` holds three cards, rather than three integers. The integer boxes are outside the drawer. `addresses.at(0) = &blue` changes a card; `*addresses.at(0) = 7` follows the card and changes its target integer. Before following a card, we must know its target exists.

```text
drawer of cards                     original boxes
slot 0: address of red ------------> red: 2
slot 1: address of blue -----------> blue: 5
slot 2: nullptr                     no target
```

The traditional form `int* cards[3]` is also an array of three pointers. We use `array` because it retains its size and provides `at()` and `size()`. In a declaration, `*` defines a pointer type; in an expression, it follows an address. Declare each variable on its own line: in `int* a, b;` only `a` would be a pointer.

## 4. How do I select products without copying them?

The inventory keeps the objects. `vector<Product*>` holds a selection of their addresses. It can grow, omit products or show one several times. It makes sense when we want a view of existing data, rather than new products.

The function `selectProduct(Product*& selection, Product& replacement)` needs to change the caller's card. Its first parameter is therefore a reference to a pointer. The second aliases the new product: `&replacement` obtains its address. With `Product* selection` we would only change a copy of the card.

Here the owner is a local `array` that stays in place. Reallocating the card vector does not relocate the products in that array. However, a reference to **a vector slot** would be invalidated by reallocation: distinguish the stored card from the box it points to.

## 5. What does nesting arrays of pointers mean?

A display has two rows with two slots each:

```cpp
array<array<Product*, 2>, 2> slots{};
```

Read from the inside out: `Product*` is a card; `array<Product*, 2>` is a row of two cards; the outer array has two rows. In this declaration, `{}` initializes every pointer to `nullptr`. The program assigns all four slots, including one with `nullptr`. `slots.at(row).at(column)` selects a card and `*slots.at(row).at(column)` reaches a product, provided the card has a valid target.

Such a matrix is not `Product**`. A double pointer describes two address levels; a nested array physically contains its rows. Counting occupied slots is also different from counting unique objects: two slots can display the same product.

`const array<Product*, 2>` prevents reassigning its cards, but permits changing their targets. `array<const Product*, 2>` permits changing the cards and provides read access to their targets. Both kinds of `const` can be combined.

## 6. Can a node live inside an array?

Yes. The node contains data and a link:

```cpp
struct Node {
    Product product;
    Node* next = nullptr;
};
```

The array owns the nodes. `next` only says which node to visit afterward. Linking `0 -> 2 -> 1` changes the logical traversal while the physical compartments stay in place. First choose a starting node, then read its data and follow its link; repeat until `nullptr`.

The visit limit detects a cycle in this three-node example. We never call `delete`: the nodes are array elements. Copying the array would copy addresses without rebuilding them; the copy's links would still point to the original nodes. This linked structure needs to preserve its array's location and lifetime, or rebuild its links.

## 7. Who destroys a dynamically created object?

`unique_ptr<Product>` is a card with responsibility: its owner destroys the object when released. `make_unique` creates the product; `get()` lends an address for observation; `move` transfers responsibility. An ordinary pointer obtained through `get()` does not receive that ownership.

`vector<unique_ptr<Product>>` can relocate its elements without moving their managed products. In the example we force reallocation with a larger capacity and verify that the product address remains the same. Then we clear the observer before erasing its owner.

In `vector<Product>`, products are the vector elements: reallocation invalidates their references and pointers. `reserve` only avoids further reallocations until capacity is exceeded; it does not make addresses permanent. Moving owners also does not protect against `erase`, `reset`, replacing an owner or destroying the structure: those operations can destroy the target.

## 8. What does the class managing nodes contribute?

[Shelf.h](Shelf.h) hides the first owner and the links. Each node contains a `Product` and a `unique_ptr<Node>` owning the next node. The chain looks like this:

```text
Shelf
  head: unique_ptr -----> Node [Product | next: unique_ptr]
                                             |
                                             v
                         Node [Product | next: nullptr]
```

`add()` creates a node and puts it before the chain: insertion order is reversed. `first()` and `nextNode()` lend `const Node*`; `getProduct()` lends `const Product&`. Queries can read without changing links. `friend` gives `Shelf` access to its node's private link for insertion and clearing; other users use public queries.

The class disables copying to avoid duplicating owners. It permits moving because transferring a chain does not require duplicating nodes. `clear()` releases one node at a time, avoiding long recursive destruction; move assignment first clears the old contents and guards against moving onto itself. The total uses `long long` and checks for overflow. These choices keep ownership consistent without changing the exercise's purpose.

Functions defined inside the class are `inline`; including this header does not require an additional `Shelf.cpp`. Product functions are defined in `Product.cpp`, which must be compiled and linked. Each program's comments provide its complete command.

## 9. What happens when these classes live inside a vector?

Now `vector<Shelf>` contains objects that in turn own nodes with products. During reallocation, the vector moves shelves. A `Shelf*` pointing to a previous slot is invalidated. A pointer to a managed node keeps its target because the node was not relocated: only its owner changed location.

The example clears the shelf pointer before forcing reallocation and inspects the shelf again through `at(0)`. It keeps a `const Node*` to demonstrate that the node stays in the same place. Before clearing that list it also clears this observer. A reference does not avoid these problems: its object must also stay alive and in place.

## Integration: sort the view, preserve the inventory

This folder's [main.cpp](main.cpp) combines the entire chain. It first builds owners, then traverses their nodes and lends addresses to a vector. It sorts that vector by price and puts some addresses in a matrix. The lists keep their order and products: we sorted cards, rather than objects.

The sorted output is `Pencil: 100`, `Notebook: 300`, `Book: 500`. The inventory totals 900 cents. The matrix has three occupied slots but only displays two distinct products, because it repeats the pencil. The integration check verifies these values and the original links' order.

```text
owners: vector<Shelf> -> Shelf -> Node -> Product
                                   ^
view: vector<const Node*> ----------|
matrix: array<array<const Node*, 2>, 2>
        |__________________________|
```

A view can be retained while the nodes are alive; deleting a node requires clearing its observers before using them again. A `nullptr` in another card does not repair a dangling address. The matrix is destroyed before the shelves because it was declared later in the same scope.

## How to choose the combination

Start with the operations: do I want to store data, group data that changes together, select existing objects, sort a view or link a traversal? Then choose who manages object lifetimes and who only observes. Finally decide what each function may change: a value, the original object, a pointer's destination or a read-only query.

Every problem does not need all these layers. A linked list here teaches nodes and ownership; a simple inventory usually needs only a vector of records. The logic of combining concepts lies in justifying each layer and being able to draw where the data lives, how you reach it and when it stops existing.
