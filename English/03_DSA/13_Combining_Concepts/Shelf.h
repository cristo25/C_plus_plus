// One shelf takes care of each chain of nodes so we do not delete it twice.
//
// Outside the shelf we can inspect nodes, but only the shelf changes their links.
//
// When a vector grows, it can change a shelf's location. We allow that change without copying its
// nodes: the new shelf takes care of the same chain.

// We share this class across steps 8, 9 and the integration example. We can define its functions
// inside the class and use this header from several files.
#ifndef COURSE_SHELF_H
#define COURSE_SHELF_H

// We use numeric_limits to check the largest allowed integer before adding.
#include <limits>
// We use unique_ptr to release its managed object automatically.
#include <memory>
// We report errors with messages, such as invalid_argument for an invalid value.
#include <stdexcept>
// We store and work with text using string.
#include <string>
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
        explicit Shelf(const string& label) : name(label) {
            if (name.empty()) {
                throw invalid_argument("The shelf needs a name");
            }
        }

        // We do not duplicate owners: each chain has one shelf responsible for it.
        Shelf(const Shelf&) = delete;
        Shelf& operator=(const Shelf&) = delete;
        // With && we receive the shelf that the vector relocates without copying its nodes.
        Shelf(Shelf&&) noexcept = default;

        ~Shelf() {
            clear();
        }

        void add(const Product& product) {
            auto newNode = make_unique<Node>(product);
            // swap exchanges address cards: the new node points to the previous head.
            newNode->next.swap(head);
            head.swap(newNode);
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
                // Put the current node aside and let the next one become the new head.
                unique_ptr<Node> current;
                current.swap(head);
                head.swap(current->next);
            }
        }
    };
}

#endif
