// Integration: processing tasks and querying routes
//
// Combine vector, linked list, stack, queue, priority queue, BST, hash table, graph, sorting and
// searching. Reuse the DSA headers. The queue defines processing order, the list keeps history,
// and the stack identifies the next undo action.
//
// Analogy: A workshop receives jobs, processes them, keeps a history, organizes priorities and
// consults a delivery map.
//
// Compile in this folder: g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o program.exe
//
// Run: ./program.exe
//
// Practice: Add a fourth task and update the checks. Which structure would you choose for
// history alone? This demonstration combines structures to practice, not because every one is
// needed for that single requirement.

#include "../03_Linked_Lists/01_Singly_Linked/SinglyLinkedList.h"
#include "../06_Trees/Tree.h"
#include "../08_Graphs/Graph.h"
#include "../09_Sorting/Sorts.h"
#include "../10_Searching/Searches.h"
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
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
        cout << "Process: " << names.at(id) << "\n";
    }
    // assert checks an integration result; it does not perform application operations.
    assert(history.values() == ids && undo.top() == 2);
    assert(urgent.top() == 3 && index.contains(2));
    mergeSort(ids);
    assert(ids == index.values());
    assert(binarySearch(ids, 2).value() == 1);

    // The graph models trips; Dijkstra computes the lowest delivery cost.
    Graph routes(3);
    routes.connect(0, 1, 4);
    routes.connect(0, 2, 1);
    routes.connect(2, 1, 1);
    assert(bfs(routes, 0).size() == 3 && dfs(routes, 0).size() == 3);
    assert(dijkstra(routes, 0).at(1) == 2);
    cout << "Last task (undo): " << names.at(undo.top()) << "\n";
    cout << "Minimum delivery cost 0 -> 1: " << dijkstra(routes, 0).at(1) << "\n";
}
