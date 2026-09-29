#ifndef COURSE_SINGLY_LINKED_LIST_H
#define COURSE_SINGLY_LINKED_LIST_H
#include <vector>

namespace course {
    using namespace std;

    class SinglyLinkedList {
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
            // ponytail: appending costs O(n); keep a tail pointer if insertion cost matters.
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
                previous->next = current->next;
            } else {
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
