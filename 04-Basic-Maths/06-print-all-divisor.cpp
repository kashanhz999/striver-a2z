/*
===============================================================================
 06 - PRINT ALL DIVISORS
===============================================================================
 INPUT: numbers in 04-Basic-Maths/input.txt

 Problem: print every i that divides n exactly (n % i == 0).   36 -> 1 2 3 4 6 9 12 18 36

 Approach 1 - brute force: try every i from 1 to n.   Time O(n)

 Approach 2 - only go up to sqrt(n).   Time O(sqrt(n))
   Divisors come in PAIRS: if i divides n, then n/i also divides n.

       36 = 1 x 36
          = 2 x 18
          = 3 x 12
          = 4 x 9
          = 6 x 6     <- i == n/i, the pair meets at sqrt(36) = 6
          = 9 x 4     <- same pairs again, reversed - no need to check

   So loop i from 1 while i*i <= n, and for every divisor i add BOTH
   i and n/i. When i == n/i (perfect square) add it only ONCE.
   Then sort, because the n/i values come out in decreasing order.

 BUG IN THE OLD VERSION: the `num/i != i` check was OUTSIDE the
 `num % i == 0` check, so n/i was added even when i was NOT a divisor.
 For n = 7: i = 2 is not a divisor, but 7/2 = 3 was added -> printed 1 3 7.
 The second if must be INSIDE the first one.

 Why i*i <= n instead of i <= sqrt(n)? sqrt() returns a double and is
 called every iteration; i*i is exact integer maths.
===============================================================================
*/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 - O(n)
void printDivisorBrute(int num){
    for(int i = 1; i <= num; i++){
        if(num % i == 0) cout << i << " ";
    }
}

// Approach 2 - O(sqrt(n)) + O(k log k) to sort k divisors
void printDivisor(int num){
    vector<int> vec;
    for(int i = 1; i * i <= num; i++){      // O(sqrt(n))
        if(num % i == 0){
            vec.emplace_back(i);            // the small divisor
            if(num / i != i){               // INSIDE: only for real divisors
                vec.emplace_back(num / i);  // its pair (skip if same, e.g. 6 for 36)
            }
        }
    }
    sort(vec.begin(), vec.end());           // O(k log k), k = number of divisors (small)
    for(auto i : vec){
        cout << i << " ";
    }
}

int main(){
    int num;
    while(cin >> num){
        if(num <= 0) { cout << num << " -> (skip, divisors are for n >= 1)\n"; continue; }
        cout << num << " -> ";
        printDivisor(num);
        cout << "  | brute: ";
        printDivisorBrute(num);
        cout << "\n";
    }
    return 0;
}

/*
 EXPECTED OUTPUT (input: 0 7 12 121 153 1634 7789):
 0 -> (skip, divisors are for n >= 1)
 7 -> 1 7   | brute: 1 7
 12 -> 1 2 3 4 6 12   | brute: 1 2 3 4 6 12
 121 -> 1 11 121   | brute: 1 11 121
 153 -> 1 3 9 17 51 153   | brute: 1 3 9 17 51 153
 1634 -> 1 2 19 38 43 86 817 1634   | brute: 1 2 19 38 43 86 817 1634
 7789 -> 1 7789   | brute: 1 7789
*/
