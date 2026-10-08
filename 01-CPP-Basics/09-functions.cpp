/*
===============================================================================
 09 - FUNCTIONS
===============================================================================
 No input needed.

 A function is a named, reusable block of code.
 Why use functions?
   - Write logic ONCE, use it many times (no repeated code)
   - Break a big problem into small pieces (modular code)
   - Easier to read, test and debug

 Anatomy:
     returnType  name ( parameters )
     {
         body
         return value;     // not needed if returnType is void
     }

 Types (by what they take / give back):
   1. void, no parameters        -> void greet()
   2. void, with parameters      -> void greetName(string name)
   3. returns value, no params   -> int getTen()
   4. returns value, with params -> int calSum(int a, int b)
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------------
// 1-4. The four basic types
// ---------------------------------------------------------------
void greet()                       // void + no parameters
{
    cout << "Hello!\n";
}

void greetName(string name)        // void + parameter
{
    cout << "Hello, " << name << "!\n";
}

int getTen()                       // return value + no parameters
{
    return 10;
}

int calSum(int num1, int num2)     // return value + parameters
{
    int sum = num1 + num2;
    return sum;                    // return sends the value back AND ends the function
}

// ---------------------------------------------------------------
// 5. PASS BY VALUE - a COPY of the variable goes to the function.
//    Changing it inside does NOT affect the original.
// ---------------------------------------------------------------
void doSomething(int num)
{
    cout << "  inside (by value): " << num;
    num += 5;
    cout << " -> " << num;
    num += 5;
    cout << " -> " << num << "\n";
}

// ---------------------------------------------------------------
// 6. PASS BY REFERENCE (&) - the function works on the ORIGINAL variable
//    (same memory address, just another name for it).
// ---------------------------------------------------------------
void doSomething1(int &num)
{
    cout << "  inside (by reference): " << num;
    num += 5;
    cout << " -> " << num;
    num += 5;
    cout << " -> " << num << "\n";
}

// Classic use of reference: swap two variables
void mySwap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Reference is also used to RETURN more than one value
void minMax(int arr[], int n, int &mn, int &mx)
{
    mn = mx = arr[0];
    for (int i = 1; i < n; i++) {
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
    }
}

// const reference: no copy (fast for big strings/vectors) AND can't be modified
int countVowels(const string &s)
{
    int cnt = 0;
    for (char c : s)
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++;
    return cnt;
}

// ---------------------------------------------------------------
// 7. Function OVERLOADING - same name, different parameter list
// ---------------------------------------------------------------
int area(int side) { return side * side; }               // square
int area(int l, int b) { return l * b; }                  // rectangle
double area(double r) { return 3.14159 * r * r; }         // circle

// ---------------------------------------------------------------
// 8. DEFAULT arguments - used when the caller doesn't pass that value
//    (default params must be at the END of the list)
// ---------------------------------------------------------------
int power(int base, int exp = 2)
{
    int result = 1;
    for (int i = 0; i < exp; i++) result *= base;
    return result;
}

// ---------------------------------------------------------------
// 9. Function declaration (prototype) - lets you use a function
//    before its full definition appears in the file.
// ---------------------------------------------------------------
bool isPrime(int n);               // declared here, defined below main

int main()
{
    greet();
    greetName("Kashan");
    cout << "getTen() = " << getTen() << "\n";
    cout << "calSum(3, 4) = " << calSum(3, 4) << "\n";

    // Pass by value vs reference
    int num = 10;
    cout << "By value:\n";
    doSomething(num);
    cout << "  outside after call: " << num << "   <- unchanged (a copy was modified)\n";

    cout << "By reference:\n";
    doSomething1(num);
    cout << "  outside after call: " << num << "   <- changed (the original was modified)\n";

    int x = 1, y = 2;
    mySwap(x, y);
    cout << "after mySwap: x = " << x << ", y = " << y << "\n";

    int arr[] = {5, 2, 9, 1, 7};
    int mn, mx;
    minMax(arr, 5, mn, mx);
    cout << "min = " << mn << ", max = " << mx << "\n";

    cout << "vowels in 'education' = " << countVowels("education") << "\n";

    cout << "area(4) = " << area(4) << ", area(3, 5) = " << area(3, 5)
         << ", area(1.0) = " << area(1.0) << "\n";

    cout << "power(5) = " << power(5) << ", power(2, 10) = " << power(2, 10) << "\n";

    cout << "primes up to 20: ";
    for (int i = 1; i <= 20; i++)
        if (isPrime(i)) cout << i << " ";
    cout << "\n";

    return 0;
}

// Definition of the function declared above main.
// Only need to check divisors up to sqrt(n): if n = a*b, one of a, b is <= sqrt(n).
bool isPrime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

/*
 EXPECTED OUTPUT:
 Hello!
 Hello, Kashan!
 getTen() = 10
 calSum(3, 4) = 7
 By value:
   inside (by value): 10 -> 15 -> 20
   outside after call: 10   <- unchanged (a copy was modified)
 By reference:
   inside (by reference): 10 -> 15 -> 20
   outside after call: 20   <- changed (the original was modified)
 after mySwap: x = 2, y = 1
 min = 1, max = 9
 vowels in 'education' = 5
 area(4) = 16, area(3, 5) = 15, area(1.0) = 3.14159
 power(5) = 25, power(2, 10) = 1024
 primes up to 20: 2 3 5 7 11 13 17 19

 SUMMARY - WHAT GETS PASSED HOW
   int, char, double, bool   -> by value (copy)   unless you write &
   string, vector, map ...   -> by value (FULL COPY - slow!) unless you write &
   arrays (int arr[])        -> always as pointer, so changes affect original
*/
