/*
===============================================================================
 05 - ARMSTRONG NUMBER
===============================================================================
 INPUT: numbers in 04-Basic-Maths/input.txt

 A number with k digits is an Armstrong number if the sum of each digit
 raised to the power k equals the number itself.

     153  (3 digits):  1^3 + 5^3 + 3^3       = 1 + 125 + 27        = 153  YES
     1634 (4 digits):  1^4 + 6^4 + 3^4 + 4^4 = 1 + 1296 + 81 + 256 = 1634 YES
     12   (2 digits):  1^2 + 2^2             = 5                         NO

 BUG IN THE OLD VERSION: it always CUBED the digits (power 3). That only
 works for 3-digit numbers - 1634 was wrongly reported as "Not Armstrong".
 Fix: first count the digits k (02-count-digits.cpp), then use power k.

 Steps:
   1. k = number of digits
   2. for every digit d: sum += d^k
   3. compare sum with the original number

 Time O(log10 n), Space O(1)
===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int countDigits(int n) {
    if (n == 0) return 1;
    int cnt = 0;
    while (n > 0) { n /= 10; cnt++; }
    return cnt;
}

// integer power - avoids pow() which returns a double (can give 124.999...)
long long power(int base, int exp) {
    long long result = 1;
    for (int i = 0; i < exp; i++) result *= base;
    return result;
}

bool isArmstrong(int n) {
    int k = countDigits(n);
    int cpy = n;
    long long sum = 0;
    while (n > 0) {
        int last_digit = n % 10;
        sum += power(last_digit, k);
        n = n / 10;
    }
    return sum == cpy;
}

int main() {
    int n;
    while (cin >> n) {
        cout << n << (isArmstrong(n) ? " Is Armstrong" : " Is Not Armstrong") << "\n";
    }

    // All Armstrong numbers up to 10000:
    cout << "Armstrong numbers up to 10000: ";
    for (int i = 0; i <= 10000; i++)
        if (isArmstrong(i)) cout << i << " ";
    cout << "\n";
    return 0;
}

/*
 EXPECTED OUTPUT (input: 0 7 12 121 153 1634 7789):
 0 Is Armstrong
 7 Is Armstrong
 12 Is Not Armstrong
 121 Is Not Armstrong
 153 Is Armstrong
 1634 Is Armstrong
 7789 Is Not Armstrong
 Armstrong numbers up to 10000: 0 1 2 3 4 5 6 7 8 9 153 370 371 407 1634 8208 9474
*/
