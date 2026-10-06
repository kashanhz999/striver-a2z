/*
===============================================================================
 STL 06 - QUEUE  (FIFO: First In, First Out)
===============================================================================
 No input needed.

 Like a line at a ticket counter: join at the BACK, leave from the FRONT.

     pop() <- front [ 1 | 2 | 3 | 4 ] back <- push(x)

 Operations (all O(1)):
   push(x) / emplace(x)  add at the back
   front()               first element (the next to leave)
   back()                last element added
   pop()                 remove the front (returns nothing)
   size(), empty()

 NO indexing, NO iteration.

 Used in DSA for: BFS (graphs, trees level-order), scheduling, sliding problems.
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(1);                  // {1}
    q.push(2);                  // {1, 2}
    q.emplace(4);               // {1, 2, 4}

    cout << "front = " << q.front() << ", back = " << q.back() << ", size = " << q.size() << "\n";

    q.back() += 5;              // front()/back() return references -> can modify: {1, 2, 9}
    cout << "back after += 5 = " << q.back() << "\n";

    q.pop();                    // removes 1 -> {2, 9}
    cout << "after pop, front = " << q.front() << "\n";

    // Printing empties it - notice the SAME order as insertion (unlike stack)
    cout << "popping all: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";

    // ---------------------------------------------------------------
    // Classic use: BFS on a small graph
    //      0 --- 1 --- 3
    //      |     |
    //      2 ----+     4 (connected to 3)
    // BFS visits nodes level by level (closest first).
    // ---------------------------------------------------------------
    vector<vector<int>> adj = {
        {1, 2},     // neighbours of 0
        {0, 2, 3},  // neighbours of 1
        {0, 1},     // neighbours of 2
        {1, 4},     // neighbours of 3
        {3}         // neighbours of 4
    };
    vector<int> dist(5, -1);    // -1 = not visited yet
    queue<int> bfs;
    bfs.push(0);
    dist[0] = 0;
    cout << "BFS order from 0: ";
    while (!bfs.empty()) {
        int node = bfs.front();
        bfs.pop();
        cout << node << " ";
        for (int nb : adj[node]) {
            if (dist[nb] == -1) {
                dist[nb] = dist[node] + 1;
                bfs.push(nb);
            }
        }
    }
    cout << "\ndistances from 0: ";
    for (int d : dist) cout << d << " ";
    cout << "\n";

    return 0;
}

/*
 EXPECTED OUTPUT:
 front = 1, back = 4, size = 3
 back after += 5 = 9
 after pop, front = 2
 popping all: 2 9
 BFS order from 0: 0 1 2 3 4
 distances from 0: 0 1 1 2 3
*/
