/*
===============================================================================
 03 - REVERSE A NUMBER
===============================================================================
 INPUT: numbers in 04-Basic-Maths/input.txt

 Problem: 7789 -> 9877

 Idea: take digits from the END of n (n % 10) and attach them to the END
       of rev. "Attach at the end" = shift rev left one place (rev * 10)
       and add the digit.

     n      last_dig   rev = rev*10 + last_dig
     7789      9        0*10 + 9   = 9
     778       8        9*10 + 8   = 98
     77        7        98*10 + 7  = 987
     7         7        987*10 + 7 = 9877

 Time O(log10 n), Space O(1)

 Edge cases:
   - Trailing zeros disappear: 1200 -> 21 (0021 is just 21)
   - OVERFLOW: reversing a big int can exceed INT_MAX (2147483647).
     e.g. 1999999999 -> 9999999991 doesn't fit in int. That's why rev is
     long long here. (LeetCode 7 asks you to return 0 in that case.)
===============================================================================
*/

#include<bits/stdc++.h>
using namespace std;

long long reverseNum(int n){
    long long rev_num = 0;
    while(n > 0){
        int last_dig = n % 10;              // take last digit
        rev_num = (rev_num * 10) + last_dig; // attach it to rev
        n = n / 10;                         // remove last digit
    }
    return rev_num;
}

int main(){
    int n;
    while(cin >> n){
        cout << n << " reversed = " << reverseNum(n) << "\n";
    }
    return 0;
}

/*
 EXPECTED OUTPUT (input: 0 7 12 121 153 1634 7789):
 0 reversed = 0
 7 reversed = 7
 12 reversed = 21
 121 reversed = 121
 153 reversed = 351
 1634 reversed = 4361
 7789 reversed = 9877
*/
