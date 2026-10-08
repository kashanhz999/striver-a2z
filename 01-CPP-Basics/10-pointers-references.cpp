/*
===============================================================================
 10 - POINTERS & REFERENCES
===============================================================================
 No input needed.

 Every variable lives at some ADDRESS in memory.

     int x = 10;

       address     value
      +---------+--------+
      | 0x61fe1c|   10   |   <- x
      +---------+--------+

 &x       -> "address of x"                         (0x61fe1c)
 int *p   -> p is a POINTER: a variable that stores an address
 *p       -> "value at the address stored in p"     (10)   (dereference)
 int &r=x -> r is a REFERENCE: just another name for x (an alias)

 Why care in DSA?
   - Linked lists, trees and graphs are built with pointers (Node* next).
   - STL iterators behave like pointers (*it gives the value).
   - Pass-by-reference avoids copying big data.
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

// A preview of how a linked list node uses a pointer
struct Node {
    int data;
    Node *next;                    // points to the next node (or nullptr at the end)
    Node(int val) : data(val), next(nullptr) {}
};

void addTenPtr(int *p) { *p += 10; }   // pass by POINTER
void addTenRef(int &r) { r += 10; }    // pass by REFERENCE (cleaner syntax, same effect)

int main()
{
    // ---------------------------------------------------------------
    // 1. Pointer basics
    // ---------------------------------------------------------------
    int x = 10;
    int *p = &x;                   // p stores the address of x

    cout << "x  = " << x << "\n";
    cout << "*p = " << *p << "   (value at address p)\n";
    cout << "p == &x ? " << (p == &x) << "\n";
    // cout << p;  would print an address like 0x61fe1c (changes each run)

    *p = 50;                       // change x THROUGH the pointer
    cout << "after *p = 50, x = " << x << "\n";

    // ---------------------------------------------------------------
    // 2. References
    // ---------------------------------------------------------------
    int y = 5;
    int &r = y;                    // r IS y (must be initialised, can't be re-pointed later)
    r = 99;
    cout << "after r = 99, y = " << y << "\n";

    // Pointer vs reference:
    //   pointer   - can be nullptr, can be changed to point elsewhere, needs * to use
    //   reference - always refers to the same variable, never null, used like a normal variable

    // ---------------------------------------------------------------
    // 3. Passing to functions
    // ---------------------------------------------------------------
    int a = 1;
    addTenPtr(&a);                 // pass the address
    addTenRef(a);                  // pass the variable itself
    cout << "a after addTenPtr + addTenRef = " << a << "\n";   // 21

    // ---------------------------------------------------------------
    // 4. Pointers and arrays
    //    The array name acts like a pointer to its first element.
    //    arr[i] is exactly the same as *(arr + i)
    // ---------------------------------------------------------------
    int arr[] = {10, 20, 30, 40};
    int *q = arr;                  // same as &arr[0]
    cout << "*q = " << *q << ", *(q + 2) = " << *(q + 2) << ", arr[2] = " << arr[2] << "\n";
    q++;                           // moves by sizeof(int) bytes -> next element
    cout << "after q++, *q = " << *q << "\n";

    // ---------------------------------------------------------------
    // 5. nullptr - a pointer that points to nothing
    // ---------------------------------------------------------------
    int *empty = nullptr;
    if (empty == nullptr) cout << "empty is null - never do *empty (crash!)\n";

    // ---------------------------------------------------------------
    // 6. Dynamic memory: new / delete (memory you manage yourself)
    // ---------------------------------------------------------------
    int *heapNum = new int(7);     // allocate one int on the heap
    cout << "*heapNum = " << *heapNum << "\n";
    delete heapNum;                // free it (otherwise: memory leak)

    int n = 5;
    int *dyn = new int[n];         // array whose size is decided at runtime
    for (int i = 0; i < n; i++) dyn[i] = i * i;
    cout << "dyn: ";
    for (int i = 0; i < n; i++) cout << dyn[i] << " ";
    cout << "\n";
    delete[] dyn;                  // arrays use delete[]
    // In practice, prefer vector<int> - it does new/delete for you.

    // ---------------------------------------------------------------
    // 7. Struct + pointer: a tiny linked list 1 -> 2 -> 3
    //    ptr->field is shorthand for (*ptr).field
    // ---------------------------------------------------------------
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "linked list: ";
    for (Node *cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->data << (cur->next ? " -> " : "\n");
    }

    // free the nodes
    while (head) {
        Node *nxt = head->next;
        delete head;
        head = nxt;
    }

    return 0;
}

/*
 EXPECTED OUTPUT:
 x  = 10
 *p = 10   (value at address p)
 p == &x ? 1
 after *p = 50, x = 50
 after r = 99, y = 99
 a after addTenPtr + addTenRef = 21
 *q = 10, *(q + 2) = 30, arr[2] = 30
 after q++, *q = 20
 empty is null - never do *empty (crash!)
 *heapNum = 7
 dyn: 0 1 4 9 16
 linked list: 1 -> 2 -> 3

 THE TWO MEANINGS OF * AND &  (this confuses everyone at first)
   In a DECLARATION:  int *p   -> p is a pointer
                      int &r   -> r is a reference
   In an EXPRESSION:  *p       -> value at p (dereference)
                      &x       -> address of x
*/
