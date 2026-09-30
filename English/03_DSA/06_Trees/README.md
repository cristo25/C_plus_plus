# Trees

We will connect this topic’s pieces before solving its integration task. Each link contains the program, comments and a practice task with requirements.

## Binary trees: roots, children and leaves

We will link nodes into branches. In a binary tree each node can have at most one left child and one right child. We call the first node the root and a node with no children a leaf. Here we are building the shape only: having two branches does not require sorted numbers. To count, we add the current node and both branches recursively. We use unique_ptr so each branch releases its nodes when finished.

[Commented program](01_Binary_Tree/main.cpp).

## Binary search trees (BST)

We will add a rule to the tree: smaller numbers go left and larger ones go right. When searching, we choose one branch and discard the other. We call this a binary search tree, or BST. Here we do not store duplicates. When removing a node with one child, we exchange the address cards with `swap`: the child takes the removed node's place without copying every box. With two children, we find a replacement that preserves the order. If the tree becomes a chain, we must traverse many nodes; calling it a tree does not guarantee fast searches.

[Commented program](02_Binary_Search_Tree/main.cpp).

## Tree traversals

We will visit the same tree in three orders. In preorder we read the node before its branches; in inorder we read left branch, node, then right branch; in postorder we leave the node until last. In a search tree, inorder displays sorted numbers. We can picture visiting the same rooms but recording each name on entry, midway or on exit. In all three cases we visit all nodes.

[Commented program](03_Traversals/main.cpp).

## Trees

We will integrate tree operations: insertion, search, traversal and removal. We use Tree.h to follow the same links in every case. First we check an empty tree, add values, compare its traversals and finally remove all nodes. We can picture maintaining a tree of folders: each change must preserve access to branches that still exist.

[Commented program](main.cpp).

**Practice.** We will write an integrated program managing numbers in a tree.

- We will add and search for numbers without duplicates.
- We will offer all three traversals.
- We will remove the root without losing other values.
- We will empty the tree and insert again.
- We will display a message when a number is missing.

[Back to the general guide](../../README.md).
