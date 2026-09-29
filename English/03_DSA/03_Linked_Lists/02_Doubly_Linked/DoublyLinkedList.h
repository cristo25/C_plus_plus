#ifndef COURSE_DOUBLY_LINKED_LIST_H
#define COURSE_DOUBLY_LINKED_LIST_H
#include <vector>

namespace course {
    using namespace std;

    class DoublyLinkedList {
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
            for (Node* current = tail; current; current = current->previous) {
                result.push_back(current->value);
            }
            return result;
        }
    };
} // namespace course

#endif
