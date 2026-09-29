# Combining concepts: from a drawer to an inventory with views

We will connect this topic’s pieces before solving its integration task. Each link contains the program, comments and a practice task with requirements.

## 1. An array containing objects

We will store complete objects in an array. In Product products[3], each compartment contains a product with its name and price. We reuse Product.h from OOP. We can picture a drawer with three Minecraft blocks: each keeps its own data even though all share a type. We traverse through const Product& to read the original without copying or changing it. When the array ends, its contained objects end too.

[Commented program](01_Array_of_Classes/main.cpp).

**Practice.** Write a program with an array of products.

- Create three complete objects with names and prices.
- Traverse them through const references.
- Add their prices in cents.
- Display each product and the total.
- Explain what one array slot contains.

## 2. A struct contains a class; an array contains those structs

We will add available quantity to each product. With struct Record we group a Product and an integer quantity, then store several Record cards in an array. We can picture a compartment holding the product and a stock label. With records[0].product we reach the object, and with records[0].quantity the number. receiveOne takes Record& to change the original card: removing & would change only a copy.

[Commented program](02_Array_of_Structs_with_Classes/main.cpp).

**Practice.** Write a program that tracks stock per product.

- Create a struct containing a Product and a quantity.
- Store at least two records in an array.
- Receive units through a function taking a reference.
- Reject negative quantities and prevent exceeding the integer limit.
- Display the records after the change.

## 3. An array of cards pointing to integers

We will store addresses instead of integers. In int* addresses[3] we have three cards: each can point to a box outside the array. With *addresses[0] we follow the first card and change red; with addresses[0] = &blue we change only the card. Two cards can point to the same box, or hold nullptr when no box is selected. The array holds the pointers but does not delete the local integers they point to.

[Commented program](03_Array_of_Pointers/main.cpp).

**Practice.** Write a program with three address cards for two integers.

- Store addresses in an int* cards[3] array.
- Point two cards at the same integer.
- Change that integer through one card and read through the other.
- Leave one card as nullptr and check before following it.
- Show that changing an address does not change the previous contents.

## 4. A vector of pointers: an inventory view

We will select products without copying them. We store products in an array and their addresses in vector<Product*>. We call this selection a view: it can grow or show a product several times without creating new products. With Product*& we give selectProduct another label for the original pointer, allowing it to change the destination. Receiving only Product* would change a copy of the card. Growing the address vector does not move these array products; they must keep existing while we read them.

[Commented program](04_Vector_of_Pointers/main.cpp).

**Practice.** Write a program that displays a selection of products.

- Store three complete products in an array.
- Keep their addresses in a vector of pointers.
- Change a selection through a reference to a pointer.
- Display a product twice without copying it.
- Check that original products stay in place.

## 5. An array of arrays of pointers

We will arrange address cards in rows and columns. Product* slots[2][2] represents two rows of two addresses. With slots[0][1] we select a card; if it is not nullptr, we can follow it to the product. Two slots can show the same product, like two signs pointing to the same shop. Here we add const after * to fix the cards; we can still modify their products. A matrix is not Product**: it contains its rows, whereas a double pointer stores an address leading to another pointer.

[Commented program](05_Matrix_of_Pointers/main.cpp).

**Practice.** Write a product display using a matrix of pointers.

- Create two rows with two slots each.
- Include a nullptr slot and two slots pointing to one product.
- Display a notice for empty slots.
- Change a product and check both cards show the change.
- Count occupied slots without confusing them with distinct products.

## 6. Nodes inside an array, connected by pointers

We will store complete nodes in an array and link them with pointers. Each Node contains a Product and next, the next node's address. The boxes occupy positions 0, 1 and 2, but arrows can make us visit 0, 2 and 1. The last link is nullptr. The boxes belong to the array and were not created with new, so we do not use delete. We limit visits to three to detect an accidental circle. Manually copying these records would require rebuilding their arrows so they no longer point to the originals.

[Commented program](06_Array_of_Linked_Nodes/main.cpp).

**Practice.** Write a program that links nodes inside an array.

- Store three nodes containing products.
- Connect positions in the order 2, 0 and 1.
- Traverse from the starting node through next.
- Stop at nullptr or report exceeding the node count.
- Draw array positions separately from visit order.

## 7. A vector of owners and an observer pointer

We will separate the location of cards from that of products. In vector<unique_ptr<Product>>, each card is also responsible for releasing its product. When the vector needs more space it can move the cards; separately created products keep their addresses. With get we lend an address, not deletion responsibility. Removing the responsible card also destroys its product; before that we stop using every borrowed pointer. This differs from vector<Product>, where growth can move the products themselves.

[Commented program](07_Vector_of_Unique_Ptr/main.cpp).

**Practice.** Write a program with products managed by unique_ptr inside a vector.

- Create two products with make_unique.
- Obtain a reading pointer with get.
- Grow the vector’s capacity and check the product address.
- Clear every observer before removing its owner.
- Display how many products remain.

## 8. A class manages struct nodes

We will keep the chain and its rules inside Shelf. Each node contains a Product and a unique_ptr to the next node; the shelf is responsible for the first. From outside we request additions or queries without directly changing links. We can picture a shelf keeper arranging boxes and lending their labels for reading. first() and nextNode() lend addresses; getProduct() lends a read-only reference. Emptying the shelf invalidates those queries because their boxes no longer exist.

[Commented program](08_Class_with_Nodes/main.cpp).

**Practice.** Write a program with a class managing a product list.

- Keep the first node inside the class.
- Add three products through a public operation.
- Traverse them using const queries.
- Calculate the total value.
- Empty the list without reusing deleted-node addresses.

## 9. A vector contains classes managing nodes

We will store several shelves in a vector. Each shelf contains nodes and each node a product: we follow those layers one at a time. Growing the vector can move a shelf, so we clear pointers to the shelf itself before forcing that change. Its nodes were created separately and do not move when their manager changes location. We can therefore keep a node query while the node still exists. Emptying its shelf destroys the node, so we must stop using that query.

[Commented program](09_Vector_of_Classes_with_Nodes/main.cpp).

**Practice.** Write a program with a vector of shelves containing nodes.

- Create two shelves and add products to their lists.
- Distinguish a shelf pointer from a pointer to one of its nodes.
- Clear the shelf pointer before growing vector capacity.
- Read the node through its relocated owner.
- Clear the query before emptying its list.

## Integration: owners, views, matrices and sorting

We will combine the layers to display sorted products without moving their original boxes. We store shelves in a vector; each shelf contains nodes and each node a product. We collect node addresses in view and sort only those cards by price. Then we choose cards for a display matrix. One card may appear several times: counting occupied slots does not count distinct products. We calculate total value from the shelves so a repeated display does not count the product twice.

[Commented program](main.cpp).

**Practice.** Write an integrated inventory with shelves, nodes and views.

- Store shelves in a vector and their products in struct nodes.
- Create a read-only pointer view without copying products.
- Sort the view by name or price.
- Display part of it in a pointer matrix with empty slots.
- Change a selection through a reference to a pointer.
- Check that sorting the view leaves original order and totals unchanged.
- Explain which structure releases each object.

[Back to the general guide](../../README.md).
