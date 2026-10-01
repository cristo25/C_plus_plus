// Integration: processing tasks and querying routes
//
// We will bring the structures together in a task-and-delivery workshop. We store tasks in a
// vector, serve them through a queue and record events in a list. With a stack we inspect the
// latest action that could be undone. We use a tree and an id table to practice queries, and sort
// numbers before searching by halves. Finally we use a graph to calculate routes. Each structure
// serves a different need; this example brings them together to show how data moves between them.
//
// Practice: We will organize tasks and routes in a workshop.
// - We will store tasks and serve them in arrival order.
// - We will find a task by ID and calculate a route between places.

#include "../03_Linked_Lists/01_Singly_Linked/SinglyLinkedList.h"
#include "../06_Trees/Tree.h"
#include "../08_Graphs/Graph.h"
#include "../09_Sorting/Sorts.h"
#include "../10_Searching/Searches.h"
#include <iostream>
// We serve by arrival with queue or by importance with priority_queue.
#include <queue>
// We store a stack: with stack, the last item in comes out first.
#include <stack>
// We store and work with text using string.
#include <string>
// We connect a key to a value for lookup, such as a student number and name.
#include <unordered_map>
// We store a collection that can grow using vector.
#include <vector>

using namespace std;
using namespace course;

int main() {
    vector<int> ids{3, 1, 2};
    unordered_map<int, string> names{{1, "Read"}, {2, "Compile"}, {3, "Practice"}};
    // The queue organizes work by arrival; the hash table maps each ID to its name.
    queue<int> pending;
    priority_queue<int> urgent;
    for (int id : ids) {
        pending.push(id);
        urgent.push(id);
    }
    SinglyLinkedList history;
    // The stack reads the last task; the list records history and the BST supports queries.
    stack<int> undo;
    Tree index;
    while (!pending.empty()) {
        int id = pending.front();
        pending.pop();
        history.append(id);
        undo.push(id);
        index.insert(id);
        cout << "Process: " << names[id] << "\n";
    }
    if (!(history.values() == ids && undo.top() == 2)) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    if (!(urgent.top() == 3 && index.contains(2))) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    mergeSort(ids);
    if (!(ids == index.values())) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    if (!(binarySearch(ids, 2).value() == 1)) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }

    // The graph models trips; Dijkstra computes the lowest delivery cost.
    Graph routes(3);
    routes.connect(0, 1, 4);
    routes.connect(0, 2, 1);
    routes.connect(2, 1, 1);
    if (!(bfs(routes, 0).size() == 3 && dfs(routes, 0).size() == 3)) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    if (!(dijkstra(routes, 0)[1] == 2)) {
        cerr << "The check did not produce the expected result.\n";
        return 1;
    }
    cout << "Last task (undo): " << names[undo.top()] << "\n";
    cout << "Minimum delivery cost 0 -> 1: " << dijkstra(routes, 0)[1] << "\n";
}
