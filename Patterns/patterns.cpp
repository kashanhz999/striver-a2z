/*
===============================================================================
 PATTERN PRINTING - 22 classic patterns
===============================================================================
 INPUT (Patterns/input.txt): any number of lines, each line is
         <patternNumber> <n>
       patternNumber = 1..22  -> prints that pattern
       patternNumber = 0      -> prints ALL 22 patterns for that n

   Example input.txt:
       0 5        <- show every pattern with n = 5
       9 3        <- then pattern 9 with n = 3

 THE 4-STEP METHOD (works for every pattern - read Patterns/README.md):
   1. Outer loop = number of ROWS.
   2. Inner loop(s) = what goes in each COLUMN of a row.
   3. Find the FORMULA connecting the row number i to what is printed
      (how many stars / spaces / which number).
   4. Print what's inside, then a newline after the inner loops.

 Convention in this file:
   - Rows are 0-indexed (i = 0 .. n-1) unless the comment says otherwise.
   - For every pattern there's a picture for n = 5 (or 3 if it's big).
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

// ============================================================================
//  PART A - Right-angled triangles (one inner loop)
// ============================================================================

// P1 - Square
// * * * * *
// * * * * *
// * * * * *
// * * * * *
// * * * * *
// rows = n, cols = n (every row is the same).
// (Old bug: the loops went to n-1, which printed a 4x4 square for n = 5.)
void p1(int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << "* ";
        cout << "\n";
    }
}

// P2 - Right triangle of stars
// *
// * *
// * * *
// * * * *
// * * * * *
// row i (0-indexed) has i+1 stars  ->  inner loop j = 0..i
void p2(int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) cout << "* ";
        cout << "\n";
    }
}

// P3 - Right triangle of numbers 1..i
// 1
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5
// 1-indexed rows: row i prints 1..i  -> print j (the column number)
void p3(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cout << j << " ";
        cout << "\n";
    }
}

// P4 - Row number repeated
// 1
// 2 2
// 3 3 3
// 4 4 4 4
// 5 5 5 5 5
// Same shape as P3, but print i (the ROW number) instead of j.
void p4(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cout << i << " ";
        cout << "\n";
    }
}

// P5 - Inverted right triangle of stars
// * * * * *
// * * * *
// * * *
// * *
// *
// Observation: stars = (total rows - current row) -> n - i  (0-indexed)
//   row 0 -> 5, row 1 -> 4 ... row 4 -> 1
// (1-indexed it's n - i + 1, which is what the old version of this file used.)
void p5(int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) cout << "* ";
        cout << "\n";
    }
}

// P6 - Inverted numbers
// 1 2 3 4 5
// 1 2 3 4
// 1 2 3
// 1 2
// 1
// 1-indexed: row i prints 1..(n - i + 1)
void p6(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) cout << j << " ";
        cout << "\n";
    }
}

// ============================================================================
//  PART B - Pyramids (space + star + space)
// ============================================================================

// P7 - Star pyramid
//     *          row 0: 4 spaces, 1 star
//    ***         row 1: 3 spaces, 3 stars
//   *****        row 2: 2 spaces, 5 stars
//  *******       row 3: 1 space , 7 stars
// *********      row 4: 0 spaces, 9 stars
//
// spaces = n - i - 1      stars = 2*i + 1
// (Trailing spaces are optional - they make the shape a perfect rectangle.)
void p7(int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) cout << " ";   // left spaces
        for (int j = 0; j < 2 * i + 1; j++) cout << "*";   // stars
        for (int j = 0; j < n - i - 1; j++) cout << " ";   // right spaces
        cout << "\n";
    }
}

// P8 - Inverted star pyramid
// *********      row 0: 0 spaces, 9 stars
//  *******       row 1: 1 space , 7 stars
//   *****        row 2: 2 spaces, 5 stars
//    ***
//     *
//
// spaces = i      stars = 2*n - (2*i + 1)   (start at 2n-1, lose 2 each row)
void p8(int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) cout << " ";
        for (int j = 0; j < 2 * n - (2 * i + 1); j++) cout << "*";
        for (int j = 0; j < i; j++) cout << " ";
        cout << "\n";
    }
}

// P9 - Diamond = P7 on top + P8 below  (reusing functions!)
//     *
//    ***
//   *****
//  *******
// *********
// *********
//  *******
//   *****
//    ***
//     *
void p9(int n)
{
    p7(n);
    p8(n);
}

// P10 - Half diamond (sideways triangle)
// *
// **
// ***
// ****
// *****
// ****
// ***
// **
// *
// Total rows = 2n - 1 (1-indexed i = 1..2n-1).
// stars = i          while i <= n  (growing)
// stars = 2n - i     after that    (shrinking)
void p10(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++) {
        int stars = (i <= n) ? i : 2 * n - i;
        for (int j = 0; j < stars; j++) cout << "*";
        cout << "\n";
    }
}

// ============================================================================
//  PART C - Number & alternating patterns
// ============================================================================

// P11 - Binary number triangle
// 1
// 0 1
// 1 0 1
// 0 1 0 1
// 1 0 1 0 1
// Each row STARTS with 1 if the row is even (0-indexed), else 0,
// then the value flips every step: start = 1 - start.
void p11(int n)
{
    for (int i = 0; i < n; i++) {
        int start = (i % 2 == 0) ? 1 : 0;
        for (int j = 0; j <= i; j++) {
            cout << start << " ";
            start = 1 - start;              // flip 1 <-> 0
        }
        cout << "\n";
    }
}

// P12 - Number crown
// 1        1      row 1: 1..1, 8 spaces, 1..1
// 12      21      row 2: 1..2, 6 spaces, 2..1
// 123    321
// 1234  4321
// 1234554321      row 5: 0 spaces
// 1-indexed: numbers 1..i, spaces = 2*(n - i), numbers i..1
void p12(int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cout << j;
        for (int j = 0; j < 2 * (n - i); j++) cout << " ";
        for (int j = i; j >= 1; j--) cout << j;
        cout << "\n";
    }
}

// P13 - Increasing number triangle (Floyd's triangle)
// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15
// Keep ONE counter outside both loops and keep increasing it.
void p13(int n)
{
    int num = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cout << num++ << " ";
        cout << "\n";
    }
}

// ============================================================================
//  PART D - Letter patterns  (char is a number: 'A' + 1 == 'B')
// ============================================================================

// P14 - Increasing letter triangle
// A
// A B
// A B C
// A B C D
// A B C D E
// row i (0-indexed): letters 'A' .. 'A' + i
void p14(int n)
{
    for (int i = 0; i < n; i++) {
        for (char ch = 'A'; ch <= 'A' + i; ch++) cout << ch << " ";
        cout << "\n";
    }
}

// P15 - Reverse letter triangle
// A B C D E
// A B C D
// A B C
// A B
// A
// row i: letters 'A' .. 'A' + (n - i - 1)
void p15(int n)
{
    for (int i = 0; i < n; i++) {
        for (char ch = 'A'; ch <= 'A' + (n - i - 1); ch++) cout << ch << " ";
        cout << "\n";
    }
}

// P16 - Alpha ramp
// A
// B B
// C C C
// D D D D
// E E E E E
// row i: letter 'A' + i, printed i+1 times (like P4 with letters)
void p16(int n)
{
    for (int i = 0; i < n; i++) {
        char ch = 'A' + i;
        for (int j = 0; j <= i; j++) cout << ch << " ";
        cout << "\n";
    }
}

// P17 - Alpha hill
//     A
//    ABA
//   ABCBA
//  ABCDCBA
// ABCDEDCBA
// Same skeleton as P7 (spaces = n-i-1, chars = 2i+1).
// Inside a row: increase the letter until the middle, then decrease.
// middle index = (2i+1)/2 = i
void p17(int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) cout << " ";
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << ch;
            if (j < breakpoint) ch++;
            else ch--;
        }
        for (int j = 0; j < n - i - 1; j++) cout << " ";
        cout << "\n";
    }
}

// P18 - Alpha triangle (from the end)
// E
// D E
// C D E
// B C D E
// A B C D E
// row i starts at letter 'A' + (n-1-i) and goes up to 'A' + (n-1)
void p18(int n)
{
    for (int i = 0; i < n; i++) {
        for (char ch = 'A' + n - 1 - i; ch <= 'A' + n - 1; ch++) cout << ch << " ";
        cout << "\n";
    }
}

// ============================================================================
//  PART E - Symmetric / hollow patterns
// ============================================================================

// P19 - Symmetric void
// **********     top half    (i = 0..n-1): stars = n-i, spaces = 2i, stars = n-i
// ****  ****
// ***    ***
// **      **
// *        *
// *        *     bottom half (i = 0..n-1): stars = i+1, spaces = 2(n-i-1), stars = i+1
// **      **
// ***    ***
// ****  ****
// **********
void p19(int n)
{
    // top half
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) cout << "*";
        for (int j = 0; j < 2 * i; j++) cout << " ";
        for (int j = 0; j < n - i; j++) cout << "*";
        cout << "\n";
    }
    // bottom half
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) cout << "*";
        for (int j = 0; j < 2 * (n - i - 1); j++) cout << " ";
        for (int j = 0; j < i + 1; j++) cout << "*";
        cout << "\n";
    }
}

// P20 - Symmetric butterfly
// *        *
// **      **
// ***    ***
// ****  ****
// **********
// ****  ****
// ***    ***
// **      **
// *        *
// Total rows 2n-1 (1-indexed). stars per side follows P10 (grow then shrink),
// spaces in the middle = 2 * (n - stars)
void p20(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++) {
        int stars = (i <= n) ? i : 2 * n - i;
        int spaces = 2 * (n - stars);
        for (int j = 0; j < stars; j++) cout << "*";
        for (int j = 0; j < spaces; j++) cout << " ";
        for (int j = 0; j < stars; j++) cout << "*";
        cout << "\n";
    }
}

// P21 - Hollow square
// *****
// *   *
// *   *
// *   *
// *****
// Loop over EVERY cell (i, j). Print * only on the border:
// first row, last row, first column, last column. Otherwise a space.
void p21(int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
}

// P22 - Concentric number square (n = 4)
// 4444444
// 4333334
// 4322234
// 4321234
// 4322234
// 4333334
// 4444444
// Grid size = (2n-1) x (2n-1).
// For each cell, find its distance to the NEAREST edge:
//     top = i, left = j, right = (2n-2) - j, bottom = (2n-2) - i
// value = n - min(top, bottom, left, right)
// (Border cells have distance 0 -> value n; the centre is farthest -> value 1.)
void p22(int n)
{
    int size = 2 * n - 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int top = i, left = j;
            int right = (size - 1) - j, bottom = (size - 1) - i;
            cout << n - min(min(top, bottom), min(left, right));
        }
        cout << "\n";
    }
}

// ============================================================================
//  main - reads "patternNumber n" pairs from input
// ============================================================================

int main()
{
    // An array of FUNCTION POINTERS: patterns[k] is the function pk.
    // patterns[0] is unused so that the index matches the pattern number.
    void (*patterns[])(int) = {
        nullptr, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11,
        p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22
    };
    const int TOTAL = 22;

    int p, n;
    while (cin >> p >> n) {                         // read until input ends
        if (p == 0) {
            for (int k = 1; k <= TOTAL; k++) {
                cout << "Pattern " << k << " (n = " << n << ")\n";
                patterns[k](n);
                cout << "\n";
            }
        }
        else if (p >= 1 && p <= TOTAL) {
            cout << "Pattern " << p << " (n = " << n << ")\n";
            patterns[p](n);
            cout << "\n";
        }
        else {
            cout << "No pattern " << p << " - choose 0..22\n";
        }
    }
    return 0;
}
