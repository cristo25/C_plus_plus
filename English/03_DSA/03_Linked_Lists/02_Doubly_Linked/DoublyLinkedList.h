// With = delete we prevent copying the class so two objects cannot try to release the same nodes.

#ifndef COURSE_DOUBLY_LINKED_LIST_H
#define COURSE_DOUBLY_LINKED_LIST_H
// We store a collection that can grow using vector.
#include <vector>

namespace course {
    using namespace std;

    class DoublyLinkedList {
        // Each carriage knows its neighbors in both directions: we can travel forward and
        // backward.
        struct Node {
            int value;
            Node* previous;
            Node* next;
        };
        Node* head = nullptr;
        Node* tail = nullptr;

    public:
        DoublyLinkedList() = default;
        DoublyLinkedList(const DoublyLinkedList&) = delete;
        DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;
        ~DoublyLinkedList() {
            while (head) {
                Node* next = head->next;
                delete head;
                head = next;
            }
        }
        void append(int value) {
            // Keeping a tail pointer lets us append by adjusting a few links without traversing
            // other nodes (O(1): work that does not grow with list length).
            Node* newNode = new Node{value, tail, nullptr};
            if (tail) {
                tail->next = newNode;
            } else {
                head = newNode;
            }
            tail = newNode;
        }
        bool remove(int value) {
            Node* current = head;
            while (current && current->value != value) {
                current = current->next;
            }
            if (!current) {
                return false;
            }
            // Removal must repair both neighbors and update head or tail when removing an
            // endpoint.
            if (current->previous) {
                current->previous->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next) {
                current->next->previous = current->previous;
            } else {
                tail = current->previous;
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
        vector<int> reversed() const {
            vector<int> result;
            // Reverse traversal starts at the tail and follows previous links.
            for (Node* current = tail; current; current = current->previous) {
                result.push_back(current->value);
            }
            return result;
        }
    };
} // namespace course

#endif
