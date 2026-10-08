/*
===============================================================================
 02 - COUNT DIGITS
===============================================================================
 INPUT: numbers in 04-Basic-Maths/input.txt

 Problem: how many digits does n have?   7789 -> 4

 Approach 1 (loop): keep removing the last digit (n / 10) and count the steps.
     Time O(log10 n), Space O(1)

 Approach 2 (maths): digits = floor(log10(n)) + 1
     log10(7789) = 3.89  -> floor = 3 -> +1 = 4
     Time O(1)  (but needs n > 0, and floating point can be risky for huge n)

 EDGE CASE (was a bug in the old version): n = 0 has 1 digit, but the
 while loop never runs for 0, so it printed 0.
===============================================================================
*/

#include<bits/stdc++.h>
using namespace std;

int countDigits(int n){
    if(n == 0) return 1;        // special case
    int cnt = 0;
    while(n > 0){
        n = n / 10;             // remove last digit
        cnt++;                  // count it
    }
    return cnt;
}

int countDigitsLog(int n){
    if(n == 0) return 1;        // log10(0) is undefined
    return (int)log10(n) + 1;
}

int main(){
    int n;
    while(cin >> n){
        cout << n << " -> " << countDigits(n) << " digits (log10 way: " << countDigitsLog(n) << ")\n";
    }
    return 0;
}

/*
 EXPECTED OUTPUT (input: 0 7 12 121 153 1634 7789):
 0 -> 1 digits (log10 way: 1)
 7 -> 1 digits (log10 way: 1)
 12 -> 2 digits (log10 way: 2)
 121 -> 3 digits (log10 way: 3)
 153 -> 3 digits (log10 way: 3)
 1634 -> 4 digits (log10 way: 4)
 7789 -> 4 digits (log10 way: 4)
*/
