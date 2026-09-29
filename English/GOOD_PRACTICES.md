# Good-practices review

## Applied corrections

- **Operations outside assert.** Creating, saving, loading, removing, inserting, depositing and withdrawing execute through ordinary conditions. Assertions check invariants; disabling them does not remove application operations.
- **Complete input validation.** Reject empty or whitespace-only names, ages outside 0 through 130, and lines such as `20abc`. User errors use conditions and messages rather than assertions.
- **Consistent DAO limit.** One constant sets the maximum of 10,000 books for creation and loading. Invalid loads preserve the prior catalog. Invalid or duplicate IDs and empty or multiline titles are rejected.
- **Header namespaces.** Every header declares its contents inside `namespace course`. Its `using namespace std;` stays there, after the includes. Implementation examples import the namespaces they use.

## Checked practices

- Private state where appropriate, const queries, composition and meaningful inheritance relationships.
- Virtual destructors in polymorphic bases and override in implementations.
- RAII using unique_ptr, values and file streams.
- Linked-list destructors with copying disabled to prevent duplicate node ownership. Traversals and removals cover empty, head, tail and single-node cases.
- Header guards, includes outside namespaces, and inline free functions defined in headers.
- Checked file opening, writing, closing and reading; append demonstrations preserve previous content.
- Empty-container checks before stack or queue access, documented iterator invalidation and binary-search preconditions.
- Sorting checks with empty inputs, duplicates, negatives and sorted data; graphs include cycles, isolated vertices and rejection of negative weights.

## Educational choices and limits

`using namespace std;` simplifies these lessons as requested. In large programs, name collisions may require limiting imports to a smaller scope. These headers avoid putting the directive in the global namespace.

Public attributes in the first class introduce objects before encapsulation. Manual new/delete remains to teach ownership and links; standard containers and RAII are preferred when they meet an application's requirements.

Early arithmetic examples use the documented small values and are not general utilities for the full int range. Deep unbalanced trees and recursive DFS can exhaust the call stack. The educational quick-sort pivot has O(n²) worst-case time. The DAO uses linear lookup and an append journal; it provides no concurrency or storage-failure recovery guarantees.

## Course readability

If, else, for, while and do-while controls use braces and multiline bodies, with one statement per line. Function bodies also span multiple lines.

Individual lessons and structured programming do not use assertions. Only DSA verification integration programs and the DAO integration example retain them. Ordinary conditions validate input errors. All three blocks explicitly teach const and headers, while changing variables remain mutable.
