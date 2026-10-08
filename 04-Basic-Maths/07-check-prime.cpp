/*
===============================================================================
 07 - CHECK PRIME
===============================================================================
 INPUT: numbers in 04-Basic-Maths/input.txt

 A prime number has EXACTLY 2 divisors: 1 and itself.   2, 3, 5, 7, 11, 13 ...
 0 and 1 are NOT prime. 2 is the only even prime.

 Approach 1 - count all divisors from 1 to n; prime if count == 2.   O(n)

 Approach 2 - O(sqrt(n)):
   If n has a divisor other than 1 and n, one of the pair (i, n/i) must be
   <= sqrt(n) (see 06-print-all-divisor.cpp). So only check i = 2 .. sqrt(n).
   Found a divisor -> NOT prime. None found -> prime.

 BUG IN THE OLD VERSION: the loop started at i = 1. EVERY number is
 divisible by 1, so num % 1 == 0 was true on the first step and the
 function returned false for ALL numbers (even 7). Start from i = 2.
 (Approach 1 starts at 1 on purpose - it counts 1 as one of the 2 divisors.)
===============================================================================
*/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 - O(n)
bool isPrimeBrute(int num){
    int cnt = 0;
    for(int i = 1; i <= num; i++){
        if(num % i == 0) cnt++;
    }
    return cnt == 2;
}

// Approach 2 - O(sqrt(n))
bool isPrime(int num){
    if(num < 2){                    // 0, 1 and negatives are not prime
        return false;
    }
    for(int i = 2; i * i <= num; i++){   // start at 2, NOT 1
        if(num % i == 0){
            return false;           // found a divisor -> not prime
        }
    }
    return true;
}

int main(){
    int num;
    while(cin >> num){
        cout << num << (isPrime(num) ? " Is Prime" : " Is Not Prime")
             << "  (brute agrees: " << (isPrime(num) == isPrimeBrute(num) ? "yes" : "NO") << ")\n";
    }

    cout << "Primes up to 50: ";
    for(int i = 1; i <= 50; i++)
        if(isPrime(i)) cout << i << " ";
    cout << "\n";
    return 0;
}

/*
 EXPECTED OUTPUT (input: 0 7 12 121 153 1634 7789):
 0 Is Not Prime  (brute agrees: yes)
 7 Is Prime  (brute agrees: yes)
 12 Is Not Prime  (brute agrees: yes)
 121 Is Not Prime  (brute agrees: yes)
 153 Is Not Prime  (brute agrees: yes)
 1634 Is Not Prime  (brute agrees: yes)
 7789 Is Prime  (brute agrees: yes)
 Primes up to 50: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47

 NEXT LEVEL: to find ALL primes up to n quickly, learn the
 Sieve of Eratosthenes - O(n log log n).
*/
