/*
===============================================================================
 STL 08 - SET, MULTISET, UNORDERED_SET
===============================================================================
 No input needed.

 A set stores UNIQUE elements and lets you check "is x present?" quickly.

 | container            | order       | duplicates | insert/find/erase     | internals         |
 |----------------------|-------------|------------|-----------------------|-------------------|
 | set<T>               | SORTED      | no         | O(log n)              | red-black tree    |
 | multiset<T>          | SORTED      | YES        | O(log n)              | red-black tree    |
 | unordered_set<T>     | no order    | no         | O(1) avg, O(n) worst  | hash table        |

 Pick:
   - only need "seen before?"          -> unordered_set (fastest)
   - need sorted order / lower_bound   -> set
   - need sorted AND duplicates        -> multiset
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

template <typename C>
void print(const string &label, const C &c)
{
    cout << label;
    for (auto x : c) cout << x << " ";
    cout << "\n";
}

void explainSet()
{
    cout << "--- set ---\n";
    set<int> st;
    st.insert(5);
    st.insert(1);
    st.emplace(3);
    st.insert(5);                         // duplicate -> ignored
    st.insert(2);
    print("set: ", st);                   // 1 2 3 5   (always sorted)
    cout << "size = " << st.size() << "\n";

    // find -> iterator to the element, or st.end() if not present
    if (st.find(3) != st.end()) cout << "3 found\n";
    if (st.find(4) == st.end()) cout << "4 not found\n";

    // count -> 1 if present, 0 if not (for set)
    cout << "count(2) = " << st.count(2) << ", count(9) = " << st.count(9) << "\n";

    // erase by value or by iterator
    st.erase(2);                          // {1, 3, 5}
    st.erase(st.begin());                 // removes smallest -> {3, 5}
    print("after erases: ", st);

    // smallest / largest
    set<int> s2 = {10, 20, 30, 40, 50};
    cout << "smallest = " << *s2.begin() << ", largest = " << *s2.rbegin() << "\n";

    // lower_bound(x): first element >= x
    // upper_bound(x): first element >  x
    cout << "lower_bound(25) = " << *s2.lower_bound(25) << "\n";   // 30
    cout << "lower_bound(30) = " << *s2.lower_bound(30) << "\n";   // 30
    cout << "upper_bound(30) = " << *s2.upper_bound(30) << "\n";   // 40
    // (if no such element, they return s2.end() - check before using *)

    // erase a range [first, last)
    s2.erase(s2.find(20), s2.find(40));   // removes 20, 30 -> {10, 40, 50}
    print("after range erase: ", s2);

    // Descending set
    set<int, greater<int>> desc = {3, 1, 4, 1, 5};
    print("descending set: ", desc);      // 5 4 3 1

    // NOTE: you cannot change an element in place (it would break the order).
    //       erase the old value and insert the new one instead.
}

void explainMultiset()
{
    cout << "--- multiset ---\n";
    multiset<int> ms = {1, 1, 1, 2, 3, 3};
    print("multiset: ", ms);              // 1 1 1 2 3 3
    cout << "count(1) = " << ms.count(1) << "\n";   // 3

    ms.erase(ms.find(1));                 // removes ONE copy of 1 -> 1 1 2 3 3
    print("erase ONE 1: ", ms);

    ms.erase(3);                          // erase(value) removes ALL copies of 3!
    print("erase ALL 3: ", ms);           // 1 1 2
}

void explainUnorderedSet()
{
    cout << "--- unordered_set ---\n";
    unordered_set<int> us = {4, 1, 9, 1, 7};
    cout << "size = " << us.size() << " (duplicate 1 ignored, order is NOT guaranteed)\n";
    cout << "contains 9? " << us.count(9) << "\n";
    // Same functions as set: insert, erase, find, count, size, empty.
    // NO lower_bound / upper_bound (there's no order).

    // Classic: does the array contain a duplicate?  O(n) average
    vector<int> a = {3, 8, 2, 8, 5};
    unordered_set<int> seen;
    for (int x : a) {
        if (seen.count(x)) { cout << "first duplicate = " << x << "\n"; break; }
        seen.insert(x);
    }

    // Classic: unique elements in sorted order -> just put them in a set
    set<int> uniqueSorted(a.begin(), a.end());
    print("unique sorted: ", uniqueSorted);  // 2 3 5 8
}

int main()
{
    explainSet();
    explainMultiset();
    explainUnorderedSet();
    return 0;
}

/*
 EXPECTED OUTPUT:
 --- set ---
 set: 1 2 3 5
 size = 4
 3 found
 4 not found
 count(2) = 1, count(9) = 0
 after erases: 3 5
 smallest = 10, largest = 50
 lower_bound(25) = 30
 lower_bound(30) = 30
 upper_bound(30) = 40
 after range erase: 10 40 50
 descending set: 5 4 3 1
 --- multiset ---
 multiset: 1 1 1 2 3 3
 count(1) = 3
 erase ONE 1: 1 1 2 3 3
 erase ALL 3: 1 1 2
 --- unordered_set ---
 size = 4 (duplicate 1 ignored, order is NOT guaranteed)
 contains 9? 1
 first duplicate = 8
 unique sorted: 2 3 5 8
*/
