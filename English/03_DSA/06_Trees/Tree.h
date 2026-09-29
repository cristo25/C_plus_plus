#ifndef COURSE_TREE_H
#define COURSE_TREE_H
#include <memory>
#include <utility>
#include <vector>

namespace course {
    using namespace std;

    enum class Traversal {
        Preorder,
        Inorder,
        Postorder
    };

    class Tree {
        struct Node {
            int value;
            unique_ptr<Node> left;
            unique_ptr<Node> right;
            explicit Node(int value) : value(value) {
            }
        };
        unique_ptr<Node> root;

        static bool insertAt(unique_ptr<Node>& node, int value) {
            if (!node) {
                node = make_unique<Node>(value);
                return true;
            }
            if (value == node->value) {
                return false;
            }
            return insertAt(value < node->value ? node->left : node->right, value);
        }
        static bool removeAt(unique_ptr<Node>& node, int value) {
            if (!node) {
                return false;
            }
            if (value < node->value) {
                return removeAt(node->left, value);
            }
            if (value > node->value) {
                return removeAt(node->right, value);
            }
            if (!node->left) {
                auto replacement = move(node->right);
                node = move(replacement);
            } else if (!node->right) {
                auto replacement = move(node->left);
                node = move(replacement);
            } else {
                const Node* successor = node->right.get();
                while (successor->left) {
                    successor = successor->left.get();
                }
                node->value = successor->value;
                removeAt(node->right, successor->value);
            }
            return true;
        }
        static void traverse(const Node* node, Traversal order, vector<int>& output) {
            if (!node) {
                return;
            }
            if (order == Traversal::Preorder) {
                output.push_back(node->value);
            }
            traverse(node->left.get(), order, output);
            if (order == Traversal::Inorder) {
                output.push_back(node->value);
            }
            traverse(node->right.get(), order, output);
            if (order == Traversal::Postorder) {
                output.push_back(node->value);
            }
        }

    public:
        // ponytail: unbalanced BST, O(n) worst case; use AVL if height matters.
        bool insert(int value) {
            return insertAt(root, value);
        }
        bool remove(int value) {
            return removeAt(root, value);
        }
        bool contains(int value) const {
            const Node* current = root.get();
            while (current) {
                if (value == current->value) {
                    return true;
                }
                current = value < current->value ? current->left.get() : current->right.get();
            }
            return false;
        }
        vector<int> values(Traversal order = Traversal::Inorder) const {
            vector<int> output;
            traverse(root.get(), order, output);
            return output;
        }
    };
} // namespace course

#endif
