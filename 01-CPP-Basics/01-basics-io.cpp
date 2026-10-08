/*
===============================================================================
 01 - C++ SKELETON & INPUT / OUTPUT
===============================================================================
 INPUT (put this in 01-CPP-Basics/input.txt):
     10 20
     Hello World

 Topics:
   1. Structure of every C++ program
   2. cout  -> printing
   3. cin   -> reading (stops at whitespace)
   4. getline -> reading a full line (with spaces)
   5. endl vs "\n"
   6. Comments
===============================================================================
*/

#include <bits/stdc++.h> // includes every standard library header (GCC only)
using namespace std;     // so we can write cout instead of std::cout

// Program execution ALWAYS starts from main().
// "int" means main returns an integer to the operating system:
//   return 0  -> program finished successfully
//   non-zero  -> something went wrong
int main()
{
    // ---------------------------------------------------------------
    // 1. OUTPUT with cout  (c-out = console output)
    //    << is the "insertion operator" - it pushes data into cout
    // ---------------------------------------------------------------
    cout << "Hello DSA" << endl;          // endl = new line + flush
    cout << "Line 2" << "\n";             // "\n" = new line only (faster)
    cout << "A" << " " << "B" << "\n";    // you can chain many <<
    cout << 5 + 3 << "\n";                // expressions are evaluated: 8

    // endl vs "\n":
    //   endl  forces the output buffer to flush to the screen every time.
    //   "\n" just adds a newline character.
    //   When printing 10^5+ lines (common in DSA), endl can make your
    //   program noticeably slower -> prefer "\n".

    // ---------------------------------------------------------------
    // 2. INPUT with cin  (c-in = console input)
    //    >> is the "extraction operator" - it pulls data out of cin
    //    cin skips spaces/newlines and stops reading at the next space.
    // ---------------------------------------------------------------
    int a, b;
    cin >> a >> b;                        // reads 10 and 20
    cout << "a = " << a << ", b = " << b << "\n";
    cout << "a + b = " << a + b << "\n";

    // ---------------------------------------------------------------
    // 3. Reading a whole line (with spaces) -> getline
    // ---------------------------------------------------------------
    // PROBLEM: after `cin >> b`, the newline character '\n' that came
    // after "20" is still waiting in the input. If we call getline now,
    // it reads that empty remainder and returns "" immediately.
    // FIX: throw away that leftover newline first.
    cin.ignore();                         // skip the leftover '\n'

    string line;
    getline(cin, line);                   // reads "Hello World"
    cout << "Line read: " << line << "\n";

    // If we had used  cin >> line  instead, we would only get "Hello".

    // ---------------------------------------------------------------
    // 4. Comments
    // ---------------------------------------------------------------
    // This is a single-line comment.
    /* This is a
       multi-line comment. */

    return 0;
}

/*
 EXPECTED OUTPUT:
 Hello DSA
 Line 2
 A B
 8
 a = 10, b = 20
 a + b = 30
 Line read: Hello World

 FAST I/O TIP (for big inputs in contests), put at the start of main:
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
 (After this, don't mix cin/cout with scanf/printf.)
*/
