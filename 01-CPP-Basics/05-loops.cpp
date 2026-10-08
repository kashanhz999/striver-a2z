/*
===============================================================================
 05 - LOOPS: for, while, do-while, break, continue, nested loops
===============================================================================
 No input needed.

 A loop repeats a block of code. Every loop has 3 parts:
   1. initialization -> where to start         (int i = 1)
   2. condition      -> keep going while true  (i <= 5)
   3. update         -> move towards the end   (i++)
 Forget the update and you get an INFINITE loop.
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ---------------------------------------------------------------
    // 1. for loop - use when you KNOW how many times to repeat
    //    for (init; condition; update) { body }
    //    order: init -> check -> body -> update -> check -> body -> ...
    // ---------------------------------------------------------------
    cout << "for 1..5: ";
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << "\n";

    cout << "for reverse 5..1: ";
    for (int i = 5; i >= 1; i--) cout << i << " ";
    cout << "\n";

    cout << "for step 2 (0..10): ";
    for (int i = 0; i <= 10; i += 2) cout << i << " ";
    cout << "\n";

    // Sum of 1..n
    int n = 10, sum = 0;
    for (int i = 1; i <= n; i++) sum += i;
    cout << "sum 1..10 = " << sum << "\n";   // 55  (formula: n*(n+1)/2)

    // ---------------------------------------------------------------
    // 2. while loop - use when you DON'T know how many times,
    //    only the condition to stop.
    //    Classic example: process digits of a number.
    // ---------------------------------------------------------------
    int num = 98765;
    int digits = 0, digitSum = 0, reversed = 0;
    while (num > 0) {
        int last = num % 10;          // take last digit
        digitSum += last;
        reversed = reversed * 10 + last;
        digits++;
        num /= 10;                    // remove last digit
    }
    cout << "98765 -> digits = " << digits << ", digit sum = " << digitSum
         << ", reversed = " << reversed << "\n";

    // ---------------------------------------------------------------
    // 3. do-while - body runs AT LEAST ONCE, condition is checked after.
    // ---------------------------------------------------------------
    int k = 100;
    do {
        cout << "do-while ran once even though k = " << k << "\n";
    } while (k < 5);                  // false, but the body already ran once

    // ---------------------------------------------------------------
    // 4. break  -> exits the loop immediately
    //    continue -> skips the REST of this iteration, goes to the next one
    // ---------------------------------------------------------------
    cout << "break at 5: ";
    for (int i = 1; i <= 10; i++) {
        if (i == 5) break;
        cout << i << " ";             // 1 2 3 4
    }
    cout << "\n";

    cout << "skip evens with continue: ";
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) continue;
        cout << i << " ";             // 1 3 5 7 9
    }
    cout << "\n";

    // ---------------------------------------------------------------
    // 5. Nested loops - a loop inside a loop.
    //    Outer loop = rows, inner loop = columns.
    //    Inner loop runs COMPLETELY for each single step of the outer loop.
    //    This is the base of ALL pattern problems (see Patterns folder).
    // ---------------------------------------------------------------
    cout << "Multiplication table 1..3:\n";
    for (int i = 1; i <= 3; i++) {            // rows
        for (int j = 1; j <= 5; j++) {        // columns
            cout << i * j << "\t";
        }
        cout << "\n";
    }
    // Total iterations = 3 * 5 = 15 -> nested loops multiply: O(rows * cols)

    // ---------------------------------------------------------------
    // 6. Common mistakes
    // ---------------------------------------------------------------
    // - Off-by-one: for (i = 0; i <= n; i++) runs n+1 times. For an array
    //   of size n use i < n.
    // - Infinite loop: while (i < 10) { ... }  but forgot i++.
    // - Semicolon after for:  for (int i = 0; i < 5; i++);  <- empty body!
    // - Using the loop variable outside: `int i` declared in the for
    //   header doesn't exist after the loop.

    return 0;
}

/*
 EXPECTED OUTPUT:
 for 1..5: 1 2 3 4 5
 for reverse 5..1: 5 4 3 2 1
 for step 2 (0..10): 0 2 4 6 8 10
 sum 1..10 = 55
 98765 -> digits = 5, digit sum = 35, reversed = 56789
 do-while ran once even though k = 100
 break at 5: 1 2 3 4
 skip evens with continue: 1 3 5 7 9
 Multiplication table 1..3:
 1  2  3  4  5
 2  4  6  8  10
 3  6  9  12 15
*/
