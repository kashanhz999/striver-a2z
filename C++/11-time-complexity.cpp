/*
===============================================================================
 11 - TIME & SPACE COMPLEXITY (Big-O)
===============================================================================
 No input needed. Full theory is in C++/README.md (section 11).

 Time complexity = how the NUMBER OF OPERATIONS grows as input size n grows.
 It is NOT the time in seconds (that depends on the machine).

 This program COUNTS operations for different loop shapes, so you can SEE
 how each complexity grows when n doubles.
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

// O(1) - constant: same work no matter how big n is
long long constant(int /* n */) { return 1; }

// O(log n) - n is cut in half each step
long long logarithmic(int n)
{
    long long ops = 0;
    for (int i = n; i > 1; i /= 2) ops++;
    return ops;
}

// O(n) - single loop over n
long long linear(int n)
{
    long long ops = 0;
    for (int i = 0; i < n; i++) ops++;
    return ops;
}

// O(n log n) - loop of n, and inside it a halving loop
long long nLogN(int n)
{
    long long ops = 0;
    for (int i = 0; i < n; i++)
        for (int j = n; j > 1; j /= 2) ops++;
    return ops;
}

// O(n^2) - two nested loops over n
long long quadratic(int n)
{
    long long ops = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) ops++;
    return ops;
}

// Still O(n^2): inner loop runs 0+1+2+...+(n-1) = n(n-1)/2 times.
// Big-O drops constants (1/2) and smaller terms (-n/2).
long long triangle(int n)
{
    long long ops = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++) ops++;
    return ops;
}

// O(2^n) - each call makes 2 more calls (naive recursion)
long long exponentialCalls = 0;
int fib(int n)
{
    exponentialCalls++;
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    cout << left << setw(8) << "n"
         << setw(8) << "O(1)"
         << setw(10) << "O(logn)"
         << setw(10) << "O(n)"
         << setw(12) << "O(nlogn)"
         << setw(14) << "O(n^2)"
         << setw(14) << "n(n-1)/2" << "\n";

    for (int n = 8; n <= 128; n *= 2) {
        cout << left << setw(8) << n
             << setw(8) << constant(n)
             << setw(10) << logarithmic(n)
             << setw(10) << linear(n)
             << setw(12) << nLogN(n)
             << setw(14) << quadratic(n)
             << setw(14) << triangle(n) << "\n";
    }
    cout << "\nWhen n doubles: O(log n) adds 1, O(n) doubles, O(n^2) becomes 4x.\n\n";

    for (int n = 10; n <= 25; n += 5) {
        exponentialCalls = 0;
        fib(n);
        cout << "fib(" << n << ") made " << exponentialCalls << " calls  <- O(2^n) explodes\n";
    }

    return 0;
}

/*
 EXPECTED OUTPUT:
 n       O(1)    O(logn)   O(n)      O(nlogn)    O(n^2)        n(n-1)/2
 8       1       3         8         24          64            28
 16      1       4         16        64          256           120
 32      1       5         32        160         1024          496
 64      1       6         64        384         4096          2016
 128     1       7         128       896         16384         8128

 When n doubles: O(log n) adds 1, O(n) doubles, O(n^2) becomes 4x.

 fib(10) made 177 calls  <- O(2^n) explodes
 fib(15) made 1973 calls  <- O(2^n) explodes
 fib(20) made 21891 calls  <- O(2^n) explodes
 fib(25) made 242785 calls  <- O(2^n) explodes

 RULE OF THUMB: a computer does roughly 10^8 simple operations per second.
 So for a 1-second limit:
   n <= 10^8   -> O(n) or O(log n)
   n <= 10^6   -> O(n log n)
   n <= 10^4   -> O(n^2)
   n <= 500    -> O(n^3)
   n <= 20     -> O(2^n)
   n <= 10     -> O(n!)
*/
