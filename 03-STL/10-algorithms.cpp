/*
===============================================================================
 STL 10 - ALGORITHMS  (#include <algorithm>, <numeric>)
===============================================================================
 No input needed.

 STL algorithms work on a RANGE given by two iterators [first, last):
     sort(v.begin(), v.end());      // whole vector
     sort(arr, arr + n);            // whole array (array name = pointer to first)
     sort(v.begin() + 2, v.begin() + 5);  // only indices 2, 3, 4

 "last" is NOT included - same rule as v.end() pointing past the last element.
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

void print(const string &label, const vector<int> &v)
{
    cout << label;
    for (int x : v) cout << x << " ";
    cout << "\n";
}

// Custom comparator for sort: return true if a should come BEFORE b.
// Here: sort pairs by second ASCENDING; if seconds are equal, by first DESCENDING.
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second != b.second) return a.second < b.second;
    return a.first > b.first;
}

int main()
{
    // ---------------------------------------------------------------
    // 1. sort - O(n log n)
    // ---------------------------------------------------------------
    vector<int> v = {5, 2, 9, 1, 5, 6};
    sort(v.begin(), v.end());
    print("sort asc:  ", v);                              // 1 2 5 5 6 9

    sort(v.begin(), v.end(), greater<int>());
    print("sort desc: ", v);                              // 9 6 5 5 2 1

    int arr[] = {4, 3, 2, 1};
    sort(arr, arr + 4);                                   // works on arrays too
    cout << "sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    // Custom comparator
    vector<pair<int, int>> pv = {{1, 2}, {2, 1}, {4, 1}};
    sort(pv.begin(), pv.end(), cmp);
    cout << "custom sort: ";
    for (auto &p : pv) cout << "{" << p.first << "," << p.second << "} ";
    cout << "\n";                                          // {4,1} {2,1} {1,2}

    // Lambda comparator (inline) - sort by absolute value
    vector<int> w = {-7, 3, -1, 5};
    sort(w.begin(), w.end(), [](int a, int b) { return abs(a) < abs(b); });
    print("by |x|:    ", w);                              // -1 3 5 -7

    // ---------------------------------------------------------------
    // 2. reverse, min/max, sum
    // ---------------------------------------------------------------
    vector<int> a = {3, 8, 1, 6};
    reverse(a.begin(), a.end());
    print("reversed:  ", a);                              // 6 1 8 3

    cout << "max_element = " << *max_element(a.begin(), a.end())
         << ", min_element = " << *min_element(a.begin(), a.end()) << "\n";
    // index of the max: subtract begin()
    cout << "index of max = " << max_element(a.begin(), a.end()) - a.begin() << "\n";

    cout << "accumulate (sum) = " << accumulate(a.begin(), a.end(), 0) << "\n";   // 18
    // for big sums use 0LL as the start value so the sum is a long long

    cout << "max(3, 7) = " << max(3, 7) << ", min({4, 2, 8}) = " << min({4, 2, 8}) << "\n";

    // ---------------------------------------------------------------
    // 3. count, find
    // ---------------------------------------------------------------
    vector<int> c = {1, 2, 2, 3, 2};
    cout << "count of 2 = " << count(c.begin(), c.end(), 2) << "\n";             // 3
    auto it = find(c.begin(), c.end(), 3);
    if (it != c.end()) cout << "3 found at index " << it - c.begin() << "\n";   // 3

    // ---------------------------------------------------------------
    // 4. Binary search family - ONLY on SORTED ranges, O(log n)
    //    binary_search -> true/false
    //    lower_bound   -> first element >= x
    //    upper_bound   -> first element >  x
    // ---------------------------------------------------------------
    vector<int> s = {1, 3, 3, 3, 5, 7};
    cout << "binary_search(5) = " << binary_search(s.begin(), s.end(), 5)
         << ", binary_search(4) = " << binary_search(s.begin(), s.end(), 4) << "\n";

    int lb = lower_bound(s.begin(), s.end(), 3) - s.begin();   // 1
    int ub = upper_bound(s.begin(), s.end(), 3) - s.begin();   // 4
    cout << "lower_bound(3) idx = " << lb << ", upper_bound(3) idx = " << ub
         << ", occurrences of 3 = " << ub - lb << "\n";

    int lb4 = lower_bound(s.begin(), s.end(), 4) - s.begin();  // 4 is missing -> where it WOULD go
    cout << "lower_bound(4) idx = " << lb4 << " (value there = " << s[lb4] << ")\n";

    // ---------------------------------------------------------------
    // 5. next_permutation - rearranges into the next bigger order
    //    Start from SORTED to get ALL permutations. Returns false at the end.
    // ---------------------------------------------------------------
    string str = "abc";
    cout << "permutations of abc: ";
    do {
        cout << str << " ";
    } while (next_permutation(str.begin(), str.end()));
    cout << "\n";

    // ---------------------------------------------------------------
    // 6. unique - removes CONSECUTIVE duplicates (sort first!)
    //    It moves unique elements to the front and returns the new end.
    // ---------------------------------------------------------------
    vector<int> d = {4, 1, 2, 1, 4, 4};
    sort(d.begin(), d.end());                             // 1 1 2 4 4 4
    d.erase(unique(d.begin(), d.end()), d.end());         // the "sort + unique + erase" idiom
    print("deduplicated: ", d);                           // 1 2 4

    // ---------------------------------------------------------------
    // 7. fill, iota, swap
    // ---------------------------------------------------------------
    vector<int> f(5);
    fill(f.begin(), f.end(), 7);
    print("fill 7:    ", f);
    iota(f.begin(), f.end(), 1);                          // 1, 2, 3, ...
    print("iota 1..:  ", f);

    int p = 1, q = 2;
    swap(p, q);
    cout << "after swap p = " << p << ", q = " << q << "\n";

    // ---------------------------------------------------------------
    // 8. Bit helpers (GCC built-ins)
    // ---------------------------------------------------------------
    int num = 13;                                         // binary 1101
    cout << "__builtin_popcount(13) = " << __builtin_popcount(num) << "\n";        // 3 set bits
    long long big = (1LL << 40) + 1;
    cout << "__builtin_popcountll(2^40 + 1) = " << __builtin_popcountll(big) << "\n"; // 2

    return 0;
}

/*
 EXPECTED OUTPUT:
 sort asc:  1 2 5 5 6 9
 sort desc: 9 6 5 5 2 1
 sorted array: 1 2 3 4
 custom sort: {4,1} {2,1} {1,2}
 by |x|:    -1 3 5 -7
 reversed:  6 1 8 3
 max_element = 8, min_element = 1
 index of max = 2
 accumulate (sum) = 18
 max(3, 7) = 7, min({4, 2, 8}) = 2
 count of 2 = 3
 3 found at index 3
 binary_search(5) = 1, binary_search(4) = 0
 lower_bound(3) idx = 1, upper_bound(3) idx = 4, occurrences of 3 = 3
 lower_bound(4) idx = 4 (value there = 5)
 permutations of abc: abc acb bac bca cab cba
 deduplicated: 1 2 4
 fill 7:    7 7 7 7 7
 iota 1..:  1 2 3 4 5
 after swap p = 2, q = 1
 __builtin_popcount(13) = 3
 __builtin_popcountll(2^40 + 1) = 2
*/
