# Combining concepts: from a drawer to an inventory with views

We will connect this topic’s pieces before solving its integration task. Each link contains the program, comments and a practice task with requirements.

## 1. An array containing objects

We will store complete objects in an array. In Product products[3], each compartment contains a product with its name and price. We reuse Product.h from OOP. We can picture a drawer with three Minecraft blocks: each keeps its own data even though all share a type. We traverse through const Product& to read the original without copying or changing it. When the array ends, its contained objects end too.

[Commented program](01_Array_of_Classes/main.cpp).

**Practice.** We will write a program with an array of products.

- We will create three complete objects with names and prices.
- We will traverse them through const references.
- We will add their prices in cents.
- We will display each product and the total.
- We will explain what one array slot contains.

## 2. A struct contains a class; an array contains those structs

We will add available quantity to each product. With struct Record we group a Product and an integer quantity, then store several Record cards in an array. We can picture a compartment holding the product and a stock label. With records[0].product we reach the object, and with records[0].quantity the number. receiveOne takes Record& to change the original card: removing & would change only a copy.

[Commented program](02_Array_of_Structs_with_Classes/main.cpp).

**Practice.** We will write a program that tracks stock per product.

- We will create a struct containing a Product and a quantity.
- We will store at least two records in an array.
- We will receive units through a function taking a reference.
- We will reject negative quantities and prevent exceeding the integer limit.
- We will display the records after the change.

## 3. An array of cards pointing to integers

We will store addresses instead of integers. In int* addresses[3] we have three cards: each can point to a box outside the array. With *addresses[0] we follow the first card and change red; with addresses[0] = &blue we change only the card. Two cards can point to the same box, or hold nullptr when no box is selected. The array holds the pointers but does not delete the local integers they point to.

[Commented program](03_Array_of_Pointers/main.cpp).

**Practice.** We will write a program with three address cards for two integers.

- We will store addresses in an int* cards[3] array.
- We will point two cards at the same integer.
- We will change that integer through one card and read through the other.
- We will leave one card as nullptr and check before following it.
- We will show that changing an address does not change the previous contents.

## 4. A vector of pointers: an inventory view

We will select products without copying them. We store products in an array and their addresses in vector<Product*>. We call this selection a view: it can grow or show a product several times without creating new products. With Product*& we give selectProduct another label for the original pointer, allowing it to change the destination. Receiving only Product* would change a copy of the card. Growing the address vector does not move these array products; they must keep existing while we read them.

[Commented program](04_Vector_of_Pointers/main.cpp).

**Practice.** We will write a program that displays a selection of products.

- We will store three complete products in an array.
- We will keep their addresses in a vector of pointers.
- We will change a selection through a reference to a pointer.
- We will display a product twice without copying it.
- We will check that original products stay in place.

## 5. An array of arrays of pointers

We will arrange address cards in rows and columns. Product* slots[2][2] represents two rows of two addresses. With slots[0][1] we select a card; if it is not nullptr, we can follow it to the product. Two slots can show the same product, like two signs pointing to the same shop. Here we add const after * to fix the cards; we can still modify their products. A matrix is not Product**: it contains its rows, whereas a double pointer stores an address leading to another pointer.

[Commented program](05_Matrix_of_Pointers/main.cpp).

**Practice.** We will write a product display using a matrix of pointers.

- We will create two rows with two slots each.
- We will include a nullptr slot and two slots pointing to one product.
- We will display a notice for empty slots.
- We will change a product and check both cards show the change.
- We will count occupied slots without confusing them with distinct products.

## 6. Nodes inside an array, connected by pointers

We will store complete nodes in an array and link them with pointers. Each Node contains a Product and next, the next node's address. The boxes occupy positions 0, 1 and 2, but arrows can make us visit 0, 2 and 1. The last link is nullptr. The boxes belong to the array and were not created with new, so we do not use delete. We limit visits to three to detect an accidental circle. Manually copying these records would require rebuilding their arrows so they no longer point to the originals.

[Commented program](06_Array_of_Linked_Nodes/main.cpp).

**Practice.** We will write a program that links nodes inside an array.

- We will store three nodes containing products.
- We will connect positions in the order 2, 0 and 1.
- We will traverse from the starting node through next.
- We will stop at nullptr or report exceeding the node count.
- We will draw array positions separately from visit order.

## 7. A vector of owners and an observer pointer

We will separate the location of cards from that of products. In vector<unique_ptr<Product>>, each card is also responsible for releasing its product. When the vector needs more space it can move the cards; separately created products keep their addresses. With get we lend an address, not deletion responsibility. Removing the responsible card also destroys its product; before that we stop using every borrowed pointer. This differs from vector<Product>, where growth can move the products themselves.

[Commented program](07_Vector_of_Unique_Ptr/main.cpp).

**Practice.** We will write a program with products managed by unique_ptr inside a vector.

- We will create two products with make_unique.
- We will obtain a reading pointer with get.
- We will grow the vector’s capacity and check the product address.
- We will clear every observer before removing its owner.
- We will display how many products remain.

## 8. A class manages struct nodes

We will keep the chain and its rules inside Shelf. We can picture a shelf keeper arranging boxes and lending their labels for reading. Each node contains a Product and a unique_ptr to the next node; the shelf is responsible for the first. When adding, we use `swap` to exchange address cards: the new node points to the old chain and the shelf points to the new node. From outside we request additions or queries without directly changing links. first() and nextNode() lend addresses; getProduct() lends a read-only reference. Emptying the shelf makes those queries unusable because their boxes no longer exist.

[Commented program](08_Class_with_Nodes/main.cpp).

**Practice.** We will write a program with a class managing a product list.

- We will keep the first node inside the class.
- We will add three products through a public operation.
- We will traverse them using const queries.
- We will calculate the total value.
- We will empty the list without reusing deleted-node addresses.

## 9. A vector contains classes managing nodes

We will store several shelves in a vector. Each shelf contains nodes and each node a product: we follow those layers one at a time. Growing the vector can move a shelf, so we clear pointers to the shelf itself before adding another shelf. Its nodes were created separately and do not move when their manager changes location. We can therefore keep a node query while the node still exists. Emptying its shelf destroys the node, so we must stop using that query.

[Commented program](09_Vector_of_Classes_with_Nodes/main.cpp).

**Practice.** We will write a program with a vector of shelves containing nodes.

- We will create two shelves and add products to their lists.
- We will distinguish a shelf pointer from a pointer to one of its nodes.
- We will clear the shelf pointer before growing vector capacity.
- We will read the node through its relocated owner.
- We will clear the query before emptying its list.

## Integration: owners, views, matrices and sorting

We will combine the layers to display sorted products without moving their original boxes. We store shelves in a vector; each shelf contains nodes and each node a product. We collect node addresses in view and sort only those cards by price. Then we choose cards for a display matrix. One card may appear several times: counting occupied slots does not count distinct products. We calculate total value from the shelves so a repeated display does not count the product twice.

[Commented program](main.cpp).

**Practice.** We will write an integrated inventory with shelves, nodes and views.

- We will store shelves in a vector and their products in struct nodes.
- We will create a read-only pointer view without copying products.
- We will sort the view by name or price.
- We will display part of it in a pointer matrix with empty slots.
- We will change a selection through a reference to a pointer.
- We will check that sorting the view leaves original order and totals unchanged.
- We will explain which structure releases each object.

[Back to the general guide](../../README.md).
