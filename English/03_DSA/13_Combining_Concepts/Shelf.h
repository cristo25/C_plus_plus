// Shared header for steps 8, 9 and the integration example; in-class function definitions are inline.
#ifndef COURSE_SHELF_H
#define COURSE_SHELF_H

#include <limits>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include "../../02_OOP/08_Headers/Product.h"

namespace course {
    using namespace std;

    class Shelf {
    public:
        struct Node {
        private:
            Product product;
            unique_ptr<Node> next;
            // Only Shelf changes links; queries lend a const view of a node.
            friend class Shelf;

        public:
            // The parameter is read through a reference, but the node stores its own copy.
            explicit Node(const Product& other) : product(other) {
            }

            const Product& getProduct() const {
                return product;
            }

            const Node* nextNode() const {
                return next.get();
            }
        };

    private:
        string name;
        unique_ptr<Node> head;

    public:
        explicit Shelf(string label) : name(move(label)) {
            if (name.empty()) {
                throw invalid_argument("The shelf needs a name");
            }
        }

        // We do not duplicate owners. Moving transfers the chain and leaves the source head null.
        Shelf(const Shelf&) = delete;
        Shelf& operator=(const Shelf&) = delete;
        Shelf(Shelf&&) noexcept = default;

        Shelf& operator=(Shelf&& other) noexcept {
            if (this != &other) {
                clear();
                name = move(other.name);
                head = move(other.head);
            }
            return *this;
        }

        ~Shelf() {
            clear();
        }

        void add(const Product& product) {
            auto newNode = make_unique<Node>(product);
            // Insert at the front: new -> previous chain. Insertion order is reversed.
            newNode->next = move(head);
            head = move(newNode);
        }

        const string& getName() const {
            return name;
        }

        const Node* first() const {
            return head.get();
        }

        long long total() const {
            long long total = 0;
            const Node* cursor = first();
            while (cursor != nullptr) {
                const int price = cursor->getProduct().getPrice();
                if (total > numeric_limits<long long>::max() - price) {
                    throw overflow_error("The total exceeds the long long range");
                }
                total += price;
                cursor = cursor->nextNode();
            }
            return total;
        }

        void clear() noexcept {
            // Release one node at a time, without a chain of recursive destructors.
            while (head != nullptr) {
                // Detach the rest before destroying the current node by replacing head.
                auto next = move(head->next);
                head = move(next);
            }
        }
    };
}

#endif
