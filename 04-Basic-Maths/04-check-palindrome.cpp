/*
===============================================================================
 04 - PALINDROME NUMBER
===============================================================================
 INPUT: numbers in 04-Basic-Maths/input.txt

 A palindrome reads the same forwards and backwards: 121, 7, 1221.

 Idea: reverse the number (03-reverse-number.cpp) and compare with the
       ORIGINAL. The loop destroys n (it becomes 0), so save a copy first.

 Time O(log10 n), Space O(1)

 Edge cases:
   - Negative numbers are NOT palindromes (-121 backwards is "121-").
   - Single digit numbers (and 0) ARE palindromes.
===============================================================================
*/

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int n){
    if(n < 0) return false;
    int cpy = n;                        // keep the original - n will become 0
    long long rev_num = 0;
    while(n > 0){
        int last_dig = n % 10;
        rev_num = (rev_num * 10) + last_dig;
        n = n / 10;
    }
    return rev_num == cpy;
}

int main(){
    int n;
    while(cin >> n){
        cout << n << (isPalindrome(n) ? " Is Palindrome" : " Is not Palindrome") << "\n";
    }
    return 0;
}

/*
 EXPECTED OUTPUT (input: 0 7 12 121 153 1634 7789):
 0 Is Palindrome
 7 Is Palindrome
 12 Is not Palindrome
 121 Is Palindrome
 153 Is not Palindrome
 1634 Is not Palindrome
 7789 Is not Palindrome
*/
