/*
===============================================================================
 02 - DATA TYPES, OPERATORS & TYPE CASTING
===============================================================================
 No input needed.

 Topics:
   1. Primitive data types and their sizes / ranges
   2. Overflow (VERY common bug in DSA)
   3. Integer division and modulo
   4. Type casting
   5. Increment / decrement, compound assignment
   6. char <-> int (ASCII)
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ---------------------------------------------------------------
    // 1. Data types
    // ---------------------------------------------------------------
    int i = 42;                  // whole numbers, ~ -2.1e9 to 2.1e9 (4 bytes)
    long long ll = 1e18;         // big whole numbers, ~ -9.2e18 to 9.2e18 (8 bytes)
    float f = 3.14f;             // decimal, ~7 digits precision (4 bytes)
    double d = 3.14159265358979; // decimal, ~15 digits precision (8 bytes) -> prefer double
    char c = 'A';                // single character, single quotes (1 byte)
    bool flag = true;            // true(1) / false(0) (1 byte)
    string s = "Kashan";         // text, double quotes (not primitive - it's a class)

    cout << i << " " << ll << " " << f << " " << d << " " << c << " " << flag << " " << s << "\n";

    // sizeof gives the size in BYTES
    cout << "int: " << sizeof(int) << ", long long: " << sizeof(long long)
         << ", double: " << sizeof(double) << ", char: " << sizeof(char) << "\n";

    // Exact limits
    cout << "INT_MAX = " << INT_MAX << ", INT_MIN = " << INT_MIN << "\n";
    cout << "LLONG_MAX = " << LLONG_MAX << "\n";

    // ---------------------------------------------------------------
    // 2. OVERFLOW - when a value goes beyond the type's range
    // ---------------------------------------------------------------
    int big = 100000;
    // int wrong = big * big;           // 10^10 doesn't fit in int -> garbage (undefined behaviour)
    long long right = 1LL * big * big;  // multiply by 1LL FIRST so the math happens in long long
    cout << "100000 * 100000 = " << right << "\n";

    // Rule of thumb: if a value can exceed ~2 * 10^9, use long long.

    // ---------------------------------------------------------------
    // 3. Integer division and modulo
    // ---------------------------------------------------------------
    cout << "7 / 2   = " << 7 / 2 << "\n";     // 3   (int / int -> decimal part is CUT, not rounded)
    cout << "7.0 / 2 = " << 7.0 / 2 << "\n";   // 3.5 (if either side is double -> double division)
    cout << "7 % 2   = " << 7 % 2 << "\n";     // 1   (remainder)
    cout << "-7 % 3  = " << -7 % 3 << "\n";    // -1  (sign follows the left number in C++)

    // % is used everywhere in DSA:
    //   n % 2 == 0      -> n is even
    //   n % 10          -> last digit of n
    //   n / 10          -> removes the last digit
    int n = 1234;
    cout << "last digit of 1234 = " << n % 10 << ", after removing = " << n / 10 << "\n";

    // ---------------------------------------------------------------
    // 4. Type casting
    // ---------------------------------------------------------------
    int x = 7, y = 2;
    double avg = (double)x / y;           // C-style cast
    double avg2 = static_cast<double>(x) / y; // C++ style cast (preferred)
    cout << "avg = " << avg << ", avg2 = " << avg2 << "\n"; // 3.5

    int truncated = (int)9.99;            // double -> int CUTS the decimal part
    cout << "(int)9.99 = " << truncated << "\n"; // 9

    // ---------------------------------------------------------------
    // 5. Increment / decrement and compound assignment
    // ---------------------------------------------------------------
    int k = 5;
    int used = k++;   // post-increment: use the OLD value, THEN increase -> used = 5, k = 6
    cout << "k++ gave " << used << ", now k = " << k << "\n";
    used = ++k;       // pre-increment: increase FIRST, then use -> k = 7, used = 7
    cout << "++k gave " << used << ", now k = " << k << "\n";
    // Don't read and modify the same variable in one expression
    // (like  cout << k++ << k;) - easy to get confusing / wrong results.
    k += 3;  // k = k + 3 -> 10
    k *= 2;  // k = k * 2 -> 20
    k -= 5;  // 15
    k /= 4;  // 3 (integer division)
    k %= 2;  // 1
    cout << "k after compound ops = " << k << "\n";

    // ---------------------------------------------------------------
    // 6. char <-> int (ASCII values)
    //    Every char is stored as a number: 'A'=65, 'a'=97, '0'=48
    // ---------------------------------------------------------------
    char ch = 'a';
    cout << "ASCII of 'a' = " << (int)ch << "\n";        // 97
    cout << "'a' + 1 as char = " << char(ch + 1) << "\n"; // b
    char digit = '7';
    cout << "'7' - '0' = " << digit - '0' << "\n";       // 7 -> char digit to int
    cout << "'c' - 'a' = " << 'c' - 'a' << "\n";         // 2 -> index of letter in alphabet

    return 0;
}

/*
 EXPECTED OUTPUT:
 42 1000000000000000000 3.14 3.14159 A 1 Kashan
 int: 4, long long: 8, double: 8, char: 1
 INT_MAX = 2147483647, INT_MIN = -2147483648
 LLONG_MAX = 9223372036854775807
 100000 * 100000 = 10000000000
 7 / 2   = 3
 7.0 / 2 = 3.5
 7 % 2   = 1
 -7 % 3  = -1
 last digit of 1234 = 4, after removing = 123
 avg = 3.5, avg2 = 3.5
 (int)9.99 = 9
 k++ gave 5, now k = 6
 ++k gave 7, now k = 7
 k after compound ops = 1
 ASCII of 'a' = 97
 'a' + 1 as char = b
 '7' - '0' = 7
 'c' - 'a' = 2

 NOTE: cout shows only 6 significant digits of a double by default
 (3.14159). To print more:  cout << fixed << setprecision(10) << d;
*/
