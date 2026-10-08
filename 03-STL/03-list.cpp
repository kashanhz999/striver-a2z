/*
===============================================================================
 STL 03 - LIST (doubly linked list)
===============================================================================
 No input needed.

 list<T> is a DOUBLY LINKED LIST. Each element (node) stores its value plus
 a pointer to the previous and the next node:

     nullptr <- [10] <-> [20] <-> [30] -> nullptr
                 ^front           ^back

 vector vs list:
   vector -> elements side by side in memory
             + v[i] is O(1)
             - insert/erase at the front or middle is O(n) (elements must shift)
   list   -> nodes scattered in memory, joined by pointers
             + insert/erase ANYWHERE is O(1) once you have an iterator there
             + push_front / pop_front are O(1)
             - NO indexing: l[2] doesn't exist, you must walk there -> O(n)

 In DSA you'll mostly use vector/deque, but list matters for things like
 the LRU cache problem (list + unordered_map).
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

void print(const list<int> &l)
{
    for (int x : l) cout << x << " ";
    cout << "\n";
}

void explainList()
{
    list<int> l;

    // ---------------------------------------------------------------
    // 1. Add at both ends - all O(1)
    // ---------------------------------------------------------------
    l.push_back(20);           // {20}
    l.emplace_back(30);        // {20, 30}
    l.push_front(10);          // {10, 20, 30}   <- vector does NOT have push_front
    l.emplace_front(5);        // {5, 10, 20, 30}
    print(l);                  // 5 10 20 30

    cout << "front = " << l.front() << ", back = " << l.back()
         << ", size = " << l.size() << "\n";

    // ---------------------------------------------------------------
    // 2. Remove from both ends - O(1)
    // ---------------------------------------------------------------
    l.pop_front();             // {10, 20, 30}
    l.pop_back();              // {10, 20}
    print(l);                  // 10 20

    // ---------------------------------------------------------------
    // 3. Insert in the middle using an iterator
    //    No l.begin() + 2 here! List iterators can only move one step
    //    at a time (++ / --), or use next(it, k) / advance(it, k).
    // ---------------------------------------------------------------
    auto it = next(l.begin(), 1);     // points to 20
    l.insert(it, 15);                 // insert BEFORE 20 -> {10, 15, 20}
    print(l);

    // ---------------------------------------------------------------
    // 4. Erase
    // ---------------------------------------------------------------
    l.push_back(15);                  // {10, 15, 20, 15}
    l.remove(15);                     // removes ALL elements equal to 15 -> {10, 20}
    print(l);

    l.erase(l.begin());               // remove the element at the iterator -> {20}
    print(l);

    // ---------------------------------------------------------------
    // 5. Handy list-only member functions
    // ---------------------------------------------------------------
    list<int> m = {5, 3, 3, 1, 4, 4, 4, 2};
    m.sort();                         // list has its OWN sort (std::sort needs random access)
    print(m);                         // 1 2 3 3 4 4 4 5
    m.unique();                       // removes CONSECUTIVE duplicates -> 1 2 3 4 5
    print(m);
    m.reverse();                      // 5 4 3 2 1
    print(m);

    // Walk backwards with reverse iterators
    cout << "backwards: ";
    for (auto rit = m.rbegin(); rit != m.rend(); rit++) cout << *rit << " ";
    cout << "\n";

    // ---------------------------------------------------------------
    // 6. Same functions as vector: size, empty, clear, swap, front, back
    // ---------------------------------------------------------------
    m.clear();
    cout << "empty after clear? " << m.empty() << "\n";
}

int main()
{
    explainList();
    return 0;
}

/*
 EXPECTED OUTPUT:
 5 10 20 30
 front = 5, back = 30, size = 4
 10 20
 10 15 20
 10 20
 20
 1 2 3 3 4 4 4 5
 1 2 3 4 5
 5 4 3 2 1
 backwards: 1 2 3 4 5
 empty after clear? 1
*/
