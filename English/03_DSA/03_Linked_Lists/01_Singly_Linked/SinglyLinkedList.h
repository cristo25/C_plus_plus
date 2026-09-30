// With = delete we prevent copying the class so two objects cannot try to release the same nodes.

#ifndef COURSE_SINGLY_LINKED_LIST_H
#define COURSE_SINGLY_LINKED_LIST_H
// We store a collection that can grow using vector.
#include <vector>

namespace course {
    using namespace std;

    class SinglyLinkedList {
        // Each card stores a value and the next card's address; nullptr ends the chain.
        struct Node {
            int value;
            Node* next;
        };
        Node* head = nullptr;

    public:
        SinglyLinkedList() = default;
        SinglyLinkedList(const SinglyLinkedList&) = delete; // Do not duplicate node owners.
        SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;
        ~SinglyLinkedList() {
            while (head) {
                // Save the next link before destroying the node; after delete its contents
                // cannot be read.
                Node* next = head->next;
                delete head;
                head = next;
            }
        }
        void append(int value) {
            Node* newNode = new Node{value, nullptr};
            if (!head) {
                head = newNode;
                return;
            }
            // We follow the chain until we reach the last node.
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        bool remove(int value) {
            Node* current = head;
            Node* previous = nullptr;
            while (current && current->value != value) {
                previous = current;
                current = current->next;
            }
            if (!current) {
                return false;
            }
            if (previous) {
                // The previous node skips to the removed node's successor: repair the chain
                // before freeing memory.
                previous->next = current->next;
            } else {
                // When removing the first node, the list's entry must point to the second.
                head = current->next;
            }
            delete current;
            return true;
        }
        vector<int> values() const {
            vector<int> result;
            for (Node* current = head; current; current = current->next) {
                result.push_back(current->value);
            }
            return result;
        }
    };
} // namespace course

#endif
