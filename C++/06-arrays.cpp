/*
===============================================================================
 06 - ARRAYS (1D)
===============================================================================
 No input needed (the cin version is shown in comments).

 An array = a fixed-size collection of elements of the SAME type, stored
 next to each other in memory.

     int arr[5] = {10, 20, 30, 40, 50};

     index:   0    1    2    3    4
            +----+----+----+----+----+
     arr:   | 10 | 20 | 30 | 40 | 50 |
            +----+----+----+----+----+

 - Indexing starts at 0, so the last index is size - 1.
 - Access by index is O(1) (instant), because the address is computed:
       address(arr[i]) = address(arr[0]) + i * sizeof(int)
 - Size is FIXED at compile time. Need a growing array? -> use vector (STL).
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Arrays are passed to functions as a POINTER to the first element.
// So: (1) the function does NOT know the size -> pass it separately
//     (2) changes inside the function affect the ORIGINAL array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

void doubleAll(int arr[], int n)
{
    for (int i = 0; i < n; i++) arr[i] *= 2;   // modifies the caller's array
}

int main()
{
    // ---------------------------------------------------------------
    // 1. Ways to declare / initialise
    // ---------------------------------------------------------------
    int a[5];                         // 5 ints, values are GARBAGE (uninitialised) if local
    int b[5] = {1, 2, 3};             // {1, 2, 3, 0, 0} - remaining become 0
    int c[5] = {0};                   // all zeros
    int d[] = {7, 8, 9};              // size deduced = 3
    (void)a;                          // (just to silence the "unused variable" warning)

    printArray(b, 5);
    printArray(c, 5);
    printArray(d, 3);

    // ---------------------------------------------------------------
    // 2. Size of an array
    // ---------------------------------------------------------------
    int n = sizeof(d) / sizeof(d[0]);  // total bytes / bytes per element = 3
    cout << "size of d = " << n << " (also size(d) = " << size(d) << ")\n";
    // NOTE: this only works where the array is DECLARED, not inside a
    // function that received it as a parameter (there it's just a pointer).

    // ---------------------------------------------------------------
    // 3. Reading input into an array (the correct loop)
    // ---------------------------------------------------------------
    //   int arr[5];
    //   for (int i = 0; i < 5; i++) cin >> arr[i];
    //
    // BUG THAT WAS IN THE OLD VERSION OF THIS FILE:
    //   for (int i = 0; i <= size(arr); i++)   <-- runs for i = 0..5 (SIX times)
    //   arr[5] does not exist! Reading/writing past the end is
    //   "undefined behaviour" - it may crash, or silently corrupt other variables.
    //   Rule: valid indices are 0 .. n-1  ->  use  i < n

    // ---------------------------------------------------------------
    // 4. Common operations - sum, max, min, search, reverse
    // ---------------------------------------------------------------
    int arr[] = {4, 9, 1, 7, 3, 8};
    int len = 6;

    int sum = 0, mx = INT_MIN, mn = INT_MAX;   // start max at smallest, min at largest
    for (int i = 0; i < len; i++) {
        sum += arr[i];
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }
    cout << "sum = " << sum << ", max = " << mx << ", min = " << mn << "\n";

    // Linear search - O(n)
    int target = 7, foundAt = -1;
    for (int i = 0; i < len; i++) {
        if (arr[i] == target) { foundAt = i; break; }
    }
    cout << "7 found at index " << foundAt << "\n";

    // Reverse in place using two pointers: swap first & last, move inwards
    int left = 0, right = len - 1;
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    cout << "reversed: ";
    printArray(arr, len);

    // ---------------------------------------------------------------
    // 5. Arrays are passed "by reference" (as pointer) to functions
    // ---------------------------------------------------------------
    doubleAll(arr, len);
    cout << "doubled:  ";
    printArray(arr, len);

    // ---------------------------------------------------------------
    // 6. Range-based for loop (for-each)
    // ---------------------------------------------------------------
    cout << "for-each: ";
    for (int x : arr) cout << x << " ";   // x is a COPY - changing x won't change arr
    cout << "\n";
    for (int &x : arr) x = 0;             // &x is a REFERENCE - this DOES change arr
    cout << "after zeroing: ";
    printArray(arr, len);

    // ---------------------------------------------------------------
    // 7. Global vs local arrays
    // ---------------------------------------------------------------
    // - Local arrays (inside main) live on the STACK (small, ~1-8 MB).
    //   int big[10000000]; inside main -> likely crashes (stack overflow).
    // - Declare huge arrays GLOBALLY (outside main): they live in static
    //   memory, can be much bigger, and are automatically set to 0.

    return 0;
}

/*
 EXPECTED OUTPUT:
 1 2 3 0 0
 0 0 0 0 0
 7 8 9
 size of d = 3 (also size(d) = 3)
 sum = 32, max = 9, min = 1
 7 found at index 3
 reversed: 8 3 7 1 9 4
 doubled:  16 6 14 2 18 8
 for-each: 16 6 14 2 18 8
 after zeroing: 0 0 0 0 0 0
*/
