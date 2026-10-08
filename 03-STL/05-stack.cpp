/*
===============================================================================
 STL 05 - STACK  (LIFO: Last In, First Out)
===============================================================================
 No input needed.

 Think of a stack of plates: you add on top and remove from the top.

        push(3) ->  | 3 |  <- top()   pop() removes this
                    | 2 |
                    | 1 |
                    +---+

 Operations (all O(1)):
   push(x) / emplace(x)  add on top
   top()                 look at the top element (don't remove)
   pop()                 remove the top (returns NOTHING - call top() first)
   size(), empty()

 NO indexing, NO iteration - you can only touch the top.

 Used in DSA for: balanced parentheses, next greater element, undo,
 expression evaluation, DFS (iterative), function call stack in recursion.
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Classic problem 1: are the brackets balanced?
// Push opening brackets; on a closing bracket the top must be its matching opener.
bool isBalanced(const string &s)
{
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else {
            if (st.empty()) return false;                // closing with nothing open
            char open = st.top();
            st.pop();
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) return false;
        }
    }
    return st.empty();                                    // nothing left unclosed
}

// Classic problem 2: Next Greater Element (monotonic stack)
// For each element, the first element to its RIGHT that is bigger, else -1.
// Go from right to left; keep the stack decreasing.  O(n) total.
vector<int> nextGreater(const vector<int> &a)
{
    int n = a.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= a[i]) st.pop(); // smaller ones can never be an answer
        res[i] = st.empty() ? -1 : st.top();
        st.push(a[i]);
    }
    return res;
}

int main()
{
    stack<int> st;
    st.push(1);                 // {1}
    st.push(2);                 // {1, 2}
    st.push(3);                 // {1, 2, 3}
    st.emplace(5);              // {1, 2, 3, 5}   top = 5

    cout << "top = " << st.top() << ", size = " << st.size() << "\n";   // 5, 4

    st.pop();                   // removes 5
    cout << "after pop, top = " << st.top() << "\n";                   // 3

    // To print everything you must pop (this empties the stack).
    // Notice the REVERSE order of insertion.
    cout << "popping all: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";

    // Calling top() or pop() on an EMPTY stack = crash / undefined behaviour.
    // Always check !st.empty() first.

    cout << boolalpha;
    cout << "\"{[()]}\" balanced? " << isBalanced("{[()]}") << "\n";
    cout << "\"([)]\"   balanced? " << isBalanced("([)]") << "\n";
    cout << "\"((\"     balanced? " << isBalanced("((") << "\n";

    vector<int> a = {4, 5, 2, 25, 7};
    vector<int> ng = nextGreater(a);
    cout << "next greater of 4 5 2 25 7: ";
    for (int x : ng) cout << x << " ";
    cout << "\n";

    return 0;
}

/*
 EXPECTED OUTPUT:
 top = 5, size = 4
 after pop, top = 3
 popping all: 3 2 1
 "{[()]}" balanced? true
 "([)]"   balanced? false
 "(("     balanced? false
 next greater of 4 5 2 25 7: 5 25 25 -1 -1
*/
