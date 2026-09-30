// Hash tables with unordered_map
//
// We will search by a key, like finding a student card by registration number. unordered_map
// connects a key to a value; here, a number to a name. Internally it uses a hash function, which
// calculates the group where a key should be sought. With find we search without creating a card;
// end() means it is missing. In a found card, first is the key and second the value. We do not
// expect cards to appear in order. Usually we inspect few entries, but many keys landing together
// may require many checks.
//
// Practice: We will find students by their ID numbers.
// - We will store three student IDs and names in unordered_map.
// - We will look up one existing and one missing ID without creating new records.

#include <iostream>
// We store and work with text using string.
#include <string>
// We connect a key to a value for lookup, such as a student number and name.
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, string> students;
    students.emplace(101, "Ana");
    students.emplace(102, "Luis");
    // find reads without inserting a new key; here 101 exists because it was inserted above.
    auto found = students.find(101);
    cout << found->second << "\n";
    if (!(students.erase(102) == 1 && students.size() == 1)) {
        return 1;
    }
}
