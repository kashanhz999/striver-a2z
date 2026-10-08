/*
===============================================================================
 03 - CONDITIONS: if / else if / else, logical operators, ternary
===============================================================================
 No input needed.

 Topics:
   1. Relational operators  ==  !=  <  >  <=  >=
   2. Logical operators     &&  ||  !
   3. if / else if / else
   4. Nested if
   5. Ternary operator  condition ? a : b
   6. Common mistakes
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

// Grade calculator - classic if / else-if ladder.
// Conditions are checked TOP to BOTTOM, and only the FIRST true block runs.
string getGrade(int marks)
{
    if (marks < 0 || marks > 100) {
        return "Invalid";
    }
    else if (marks >= 90) {
        return "A";
    }
    else if (marks >= 70) {      // we already know marks < 90 here
        return "B";
    }
    else if (marks >= 50) {
        return "C";
    }
    else {
        return "Fail";
    }
}

// Nested if - an if inside another if
// Problem: age < 18 -> "not eligible"
//          age >= 18 -> eligible, and if age >= 57 also "retirement soon"
void checkJob(int age)
{
    if (age >= 18) {
        cout << age << ": eligible for job";
        if (age >= 57) {
            cout << ", retirement soon";
        }
        cout << "\n";
    }
    else {
        cout << age << ": not eligible\n";
    }
}

int main()
{
    // ---------------------------------------------------------------
    // 1 & 2. Relational and logical operators produce bool (1 or 0)
    // ---------------------------------------------------------------
    int a = 5, b = 10;
    cout << (a == b) << " " << (a != b) << " " << (a < b) << "\n"; // 0 1 1
    cout << (a < b && b < 20) << "\n";  // AND: both must be true  -> 1
    cout << (a > b || b == 10) << "\n"; // OR : at least one true  -> 1
    cout << !(a < b) << "\n";           // NOT: flips              -> 0

    // Short-circuit: in A && B, if A is false, B is NOT evaluated.
    //                in A || B, if A is true,  B is NOT evaluated.
    // Useful to avoid errors:  if (i < n && arr[i] == x)  -> never reads arr[n]

    // ---------------------------------------------------------------
    // 3. if / else if / else
    // ---------------------------------------------------------------
    int tests[] = {95, 75, 55, 20, 120};
    for (int m : tests) {
        cout << m << " -> " << getGrade(m) << "\n";
    }

    // ---------------------------------------------------------------
    // 4. Nested if
    // ---------------------------------------------------------------
    checkJob(15);
    checkJob(30);
    checkJob(60);

    // ---------------------------------------------------------------
    // 5. Ternary operator - a one-line if/else that RETURNS a value
    //    result = (condition) ? valueIfTrue : valueIfFalse;
    // ---------------------------------------------------------------
    int n = 7;
    string parity = (n % 2 == 0) ? "even" : "odd";
    cout << n << " is " << parity << "\n";

    int mx = (a > b) ? a : b;   // max of two numbers
    cout << "max(" << a << ", " << b << ") = " << mx << "\n";

    // ---------------------------------------------------------------
    // 6. Common mistakes
    // ---------------------------------------------------------------
    // (a) = vs ==
    //     if (x = 5)  -> ASSIGNS 5 to x, and 5 is "true" -> always runs!
    //     if (x == 5) -> compares. Always use == for comparison.
    //
    // (b) Missing braces - only the FIRST statement belongs to the if:
    //     if (x > 0)
    //         cout << "positive";
    //         cout << "this ALWAYS prints";   // not part of the if!
    //     -> Always use { } to be safe.
    //
    // (c) Chained comparison doesn't work like maths:
    //     if (1 < x < 10)  is WRONG -> it becomes (1 < x) < 10 -> (0 or 1) < 10 -> always true
    //     if (1 < x && x < 10)  is correct.
    //
    // (d) Any non-zero number is "true", 0 is "false":
    //     if (5) -> runs,  if (0) -> doesn't run,  if (-1) -> runs.

    return 0;
}

/*
 EXPECTED OUTPUT:
 0 1 1
 1
 1
 0
 95 -> A
 75 -> B
 55 -> C
 20 -> Fail
 120 -> Invalid
 15: not eligible
 30: eligible for job
 60: eligible for job, retirement soon
 7 is odd
 max(5, 10) = 10
*/
