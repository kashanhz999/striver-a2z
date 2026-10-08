/*
===============================================================================
 STL 04 - DEQUE (double-ended queue, pronounced "deck")
===============================================================================
 No input needed.

 deque<T> = vector that is ALSO fast at the front.

               push_front                 push_back
                   -->  [ 1 | 2 | 3 | 4 ]  <--
               pop_front                  pop_back

   - push/pop at BOTH ends: O(1)
   - d[i] random access:    O(1)   (list can't do this)
   - insert in the middle:  O(n)

 Used in DSA for: sliding window maximum (monotonic deque), 0-1 BFS,
 and as the container behind stack and queue.
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

void print(const deque<int> &d)
{
    for (int x : d) cout << x << " ";
    cout << "\n";
}

int main()
{
    deque<int> dq;

    dq.push_back(1);           // {1}
    dq.emplace_back(2);        // {1, 2}
    dq.push_front(4);          // {4, 1, 2}
    dq.emplace_front(3);       // {3, 4, 1, 2}
    print(dq);                 // 3 4 1 2

    cout << "dq[1] = " << dq[1] << ", front = " << dq.front() << ", back = " << dq.back() << "\n";

    dq.pop_back();             // {3, 4, 1}
    dq.pop_front();            // {4, 1}
    print(dq);                 // 4 1

    // Same as vector: insert, erase, size, empty, clear, begin/end, swap ...
    dq.insert(dq.begin() + 1, 99);   // {4, 99, 1}
    print(dq);

    // ---------------------------------------------------------------
    // Classic use: Sliding Window Maximum
    // For each window of size k, print the maximum.
    // Keep INDICES in the deque so that their values are DECREASING.
    // The front is always the max of the current window.
    // Each index is pushed and popped at most once -> O(n) total.
    // ---------------------------------------------------------------
    vector<int> a = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    deque<int> win;                          // stores indices
    cout << "window max (k=3): ";
    for (int i = 0; i < (int)a.size(); i++) {
        if (!win.empty() && win.front() <= i - k) win.pop_front();       // out of window
        while (!win.empty() && a[win.back()] <= a[i]) win.pop_back();    // smaller ones are useless
        win.push_back(i);
        if (i >= k - 1) cout << a[win.front()] << " ";
    }
    cout << "\n";

    return 0;
}

/*
 EXPECTED OUTPUT:
 3 4 1 2
 dq[1] = 4, front = 3, back = 2
 4 1
 4 99 1
 window max (k=3): 3 3 5 5 6 7
*/
