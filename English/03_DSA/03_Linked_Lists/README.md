# Linked lists

We will connect this topic’s pieces before solving its integration task. Each link contains the program, comments and a practice task with requirements.

## Singly linked list

We will build a chain of boxes called nodes. Each node stores a value and a pointer to the next node, like a note showing where the next box is. The list stores the first address; the last points to nullptr. To search we follow the notes one at a time and may visit all nodes. When removing a node we join its previous neighbor to the next before releasing the box. We can see those steps inside SinglyLinkedList.h.

[Commented program](01_Singly_Linked/main.cpp).

## Doubly linked list

We will add a second arrow to each node: one to the next and another to the previous node. This lets us traverse in both directions. We also keep the first and last addresses so appending adjusts a few arrows without traversing the list. When removing a node we repair both connections, like removing a train carriage linked at both ends. We can follow those pointer changes in DoublyLinkedList.h.

[Commented program](02_Doubly_Linked/main.cpp).

## Circular linked list

We will close the chain into a circle: the last node points back to the first. We can picture players taking repeated turns. Since we do not reach nullptr after one lap, we stop when we return to the start. We keep the last node to append with a few changes. Removing the only node leaves an empty list; removing any other node keeps the circle closed.

[Commented program](03_Circular/main.cpp).

## Linked lists

We will compare all three lists using the same numbers. In the singly linked list we follow one arrow, in the doubly linked list we can go back, and in the circular list we return to the beginning. We insert 10, 20 and 30, remove 20 and check what remains. The main difference is how we link nodes and when traversal stops. We can draw the same three boxes and change only their arrows to understand it.

[Commented program](main.cpp).

**Practice.** We will write an integrated program comparing three lists.

- We will insert the same five values into singly linked, doubly linked and circular lists.
- We will remove the same value from all three.
- We will display forward traversals and the doubly linked list in reverse.
- We will limit the circular list to one lap.
- We will try each list after emptying it.

[Back to the general guide](../../README.md).
