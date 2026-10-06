/*
===============================================================================
 STL 01 - PAIR
===============================================================================
 No input needed.

 pair<T1, T2> stores exactly TWO values (can be different types) together.
   p.first  -> first value
   p.second -> second value

 Where it's used in DSA:
   - (value, index) when you need to remember where an element came from
   - (x, y) coordinates, (start, end) intervals
   - Edges in graphs: (neighbour, weight)
   - map stores its elements as pair<key, value>
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ---------------------------------------------------------------
    // 1. Creating pairs
    // ---------------------------------------------------------------
    pair<int, int> p = {1, 2};
    cout << p.first << " " << p.second << "\n";              // 1 2

    pair<string, int> student = make_pair("Kashan", 95);    // make_pair also works
    cout << student.first << " scored " << student.second << "\n";

    auto q = make_pair('x', 3.5);                            // auto deduces pair<char, double>
    cout << q.first << " " << q.second << "\n";

    // ---------------------------------------------------------------
    // 2. Nested pair - for storing 3 (or more) values
    // ---------------------------------------------------------------
    pair<int, pair<int, int>> p1 = {1, {1, 2}};
    cout << p1.first << " " << p1.second.first << " " << p1.second.second << "\n"; // 1 1 2

    // ---------------------------------------------------------------
    // 3. Array of pairs
    // ---------------------------------------------------------------
    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 10}};
    cout << arr[2].second << "\n";                           // 10

    // ---------------------------------------------------------------
    // 4. Modifying
    // ---------------------------------------------------------------
    p.first = 100;
    p.second += 5;
    cout << p.first << " " << p.second << "\n";              // 100 7

    // ---------------------------------------------------------------
    // 5. Comparing pairs - compares .first, and only if equal compares .second
    //    (this is why sorting a vector of pairs sorts by first, then second)
    // ---------------------------------------------------------------
    pair<int, int> a = {1, 5}, b = {1, 9}, c = {2, 0};
    cout << (a < b) << " " << (b < c) << " " << (a == make_pair(1, 5)) << "\n"; // 1 1 1

    // ---------------------------------------------------------------
    // 6. Structured bindings (C++17) - unpack a pair into named variables
    // ---------------------------------------------------------------
    auto [name, marks] = student;
    cout << name << " -> " << marks << "\n";

    // ---------------------------------------------------------------
    // 7. Practical: find the max element AND its index using pair
    // ---------------------------------------------------------------
    int nums[] = {4, 9, 2, 9, 1};
    pair<int, int> best = {nums[0], 0};                       // (value, index)
    for (int i = 1; i < 5; i++) {
        if (nums[i] > best.first) best = {nums[i], i};
    }
    cout << "max = " << best.first << " at index " << best.second << "\n";

    // ---------------------------------------------------------------
    // 8. tuple - like pair but any number of values
    // ---------------------------------------------------------------
    tuple<int, string, double> t = {1, "abc", 2.5};
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "\n";

    return 0;
}

/*
 EXPECTED OUTPUT:
 1 2
 Kashan scored 95
 x 3.5
 1 1 2
 10
 100 7
 1 1 1
 Kashan -> 95
 max = 9 at index 1
 1 abc 2.5
*/
