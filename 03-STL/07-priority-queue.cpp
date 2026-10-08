/*
===============================================================================
 STL 07 - PRIORITY QUEUE (HEAP)
===============================================================================
 No input needed.

 A queue where the element that comes out is always the "BEST" one,
 not the oldest one. Internally it's a binary HEAP (a tree stored in an array).

   priority_queue<int>                               -> MAX-heap: top() = LARGEST
   priority_queue<int, vector<int>, greater<int>>    -> MIN-heap: top() = SMALLEST

 Operations:
   push(x) / emplace(x)   O(log n)
   top()                  O(1)     look at the best element
   pop()                  O(log n) remove the best element
   size(), empty()        O(1)

 Used in DSA for: K largest / smallest, Dijkstra's shortest path,
 merging k sorted lists, median of a stream, scheduling, greedy problems.
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ---------------------------------------------------------------
    // 1. Max-heap (default)
    // ---------------------------------------------------------------
    priority_queue<int> maxH;
    maxH.push(5);
    maxH.push(2);
    maxH.push(8);
    maxH.emplace(10);
    cout << "max-heap top = " << maxH.top() << "\n";   // 10

    cout << "max-heap pop order: ";
    while (!maxH.empty()) {
        cout << maxH.top() << " ";
        maxH.pop();
    }
    cout << "\n";                                       // 10 8 5 2  (sorted descending)

    // ---------------------------------------------------------------
    // 2. Min-heap
    //    template args: <type, underlying container, comparator>
    // ---------------------------------------------------------------
    priority_queue<int, vector<int>, greater<int>> minH;
    for (int x : {5, 2, 8, 10}) minH.push(x);
    cout << "min-heap pop order: ";
    while (!minH.empty()) {
        cout << minH.top() << " ";
        minH.pop();
    }
    cout << "\n";                                       // 2 5 8 10

    // Trick: a min-heap from a max-heap -> push -x, and negate again when reading.

    // ---------------------------------------------------------------
    // 3. Heap of pairs - compares .first, then .second
    //    Common for Dijkstra: (distance, node) in a MIN-heap
    // ---------------------------------------------------------------
    priority_queue<pair<int, string>> tasks;           // max by priority
    tasks.push({2, "write notes"});
    tasks.push({5, "fix bug"});
    tasks.push({1, "lunch"});
    cout << "highest priority task: " << tasks.top().second << "\n";   // fix bug

    // ---------------------------------------------------------------
    // 4. Custom comparator - e.g. sort strings by LENGTH, shortest on top
    //    The comparator returns true if a should come BELOW b
    //    (it's "reversed" compared to sort - a common confusion).
    // ---------------------------------------------------------------
    auto cmp = [](const string &a, const string &b) { return a.size() > b.size(); };
    priority_queue<string, vector<string>, decltype(cmp)> byLen(cmp);
    for (string s : {"banana", "fig", "apple", "kiwi"}) byLen.push(s);
    cout << "shortest word first: ";
    while (!byLen.empty()) {
        cout << byLen.top() << " ";
        byLen.pop();
    }
    cout << "\n";

    // ---------------------------------------------------------------
    // 5. Classic: K-th largest element
    //    Keep a MIN-heap of size k. The smallest of the k largest is on top.
    //    O(n log k) - better than sorting O(n log n) when k is small.
    // ---------------------------------------------------------------
    vector<int> a = {7, 10, 4, 3, 20, 15};
    int k = 3;
    priority_queue<int, vector<int>, greater<int>> kHeap;
    for (int x : a) {
        kHeap.push(x);
        if ((int)kHeap.size() > k) kHeap.pop();         // throw away the smallest
    }
    cout << k << "rd largest in {7,10,4,3,20,15} = " << kHeap.top() << "\n";   // 10

    return 0;
}

/*
 EXPECTED OUTPUT:
 max-heap top = 10
 max-heap pop order: 10 8 5 2
 min-heap pop order: 2 5 8 10
 highest priority task: fix bug
 shortest word first: fig kiwi apple banana
 3rd largest in {7,10,4,3,20,15} = 10
*/
