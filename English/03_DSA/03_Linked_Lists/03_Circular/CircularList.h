#ifndef COURSE_CIRCULAR_LIST_H
#define COURSE_CIRCULAR_LIST_H
#include <vector>

namespace course {
    using namespace std;

    class CircularList {
        struct Node {
            int value;
            Node* next;
        };
        Node* tail = nullptr; // The first node is tail->next when the list is nonempty.
    public:
        CircularList() = default;
        CircularList(const CircularList&) = delete;
        CircularList& operator=(const CircularList&) = delete;
        ~CircularList() {
            if (!tail) {
                return;
            }
            Node* current = tail->next;
            tail->next = nullptr; // Open the ring to destroy it as a chain.
            while (current) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
        void append(int value) {
            Node* newNode = new Node{value, nullptr};
            if (!tail) {
                // With one node, the next link points back to that same node.
                newNode->next = newNode;
            } else {
                newNode->next = tail->next;
                tail->next = newNode;
            }
            tail = newNode;
        }
        bool remove(int value) {
            if (!tail) {
                return false;
            }
            Node* previous = tail;
            Node* current = tail->next;
            do {
                if (current->value == value) {
                    // This identifies the only node; removing it leaves an empty list.
                    if (current == previous) {
                        tail = nullptr;
                    } else {
                        previous->next = current->next;
                        if (current == tail) {
                            tail = previous;
                        }
                    }
                    delete current;
                    return true;
                }
                previous = current;
                current = current->next;
            // Stop after returning to the first node; the ring has no ending nullptr.
            } while (current != tail->next);
            return false;
        }
        vector<int> values() const {
            vector<int> result;
            if (!tail) {
                return result;
            }
            Node* current = tail->next;
            do {
                result.push_back(current->value);
                current = current->next;
            } while (current != tail->next);
            return result;
        }
    };
} // namespace course

#endif
