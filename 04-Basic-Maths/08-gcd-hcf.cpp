/*
===============================================================================
 08 - GCD / HCF  (Greatest Common Divisor / Highest Common Factor)
===============================================================================
 No input needed (works on fixed pairs, because input.txt holds single numbers).

 GCD(a, b) = the largest number that divides BOTH a and b.
     GCD(12, 18) = 6     (divisors of 12: 1 2 3 4 6 12, of 18: 1 2 3 6 9 18)

 Approach 1 - brute force: check every i from min(a, b) DOWN to 1;
              the first i that divides both is the GCD.     O(min(a, b))

 Approach 2 - EUCLIDEAN ALGORITHM:   gcd(a, b) = gcd(b, a % b),  gcd(a, 0) = a
   Why? Any number that divides a and b also divides a - b, a - 2b, ...,
   and so a % b. So the GCD doesn't change when we replace a with a % b.

     gcd(52, 20) -> gcd(20, 52 % 20 = 12)
                 -> gcd(12, 20 % 12 = 8)
                 -> gcd(8, 12 % 8 = 4)
                 -> gcd(4, 8 % 4 = 0)
                 -> 4

   Time O(log(min(a, b))) - the numbers shrink very fast.

 LCM (Least Common Multiple):  lcm(a, b) = a / gcd(a, b) * b
   (divide FIRST to avoid overflow of a * b)

 C++17 also has the built-ins  std::gcd(a, b)  and  std::lcm(a, b)  in <numeric>.
===============================================================================
*/

#include<bits/stdc++.h>
using namespace std;

// Approach 1 - O(min(a, b))
int gcdBrute(int a, int b){
    for(int i = min(a, b); i >= 1; i--){
        if(a % i == 0 && b % i == 0) return i;
    }
    return max(a, b);   // only reached when one of them is 0: gcd(a, 0) = a
}

// Approach 2 - Euclidean, loop version
int gcdEuclid(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Approach 2 - Euclidean, recursive version (same thing, one line)
int gcdRec(int a, int b){
    return b == 0 ? a : gcdRec(b, a % b);
}

long long lcmOf(int a, int b){
    return (long long)a / gcdEuclid(a, b) * b;
}

int main(){
    vector<pair<int, int>> tests = {{12, 18}, {52, 20}, {17, 5}, {100, 75}, {9, 0}};
    for(auto [a, b] : tests){
        cout << "gcd(" << a << ", " << b << ") = " << gcdEuclid(a, b)
             << "  [brute " << gcdBrute(a, b) << ", recursive " << gcdRec(a, b)
             << ", std::gcd " << gcd(a, b) << "]";
        if(b != 0) cout << "   lcm = " << lcmOf(a, b);
        cout << "\n";
    }
    return 0;
}

/*
 EXPECTED OUTPUT:
 gcd(12, 18) = 6  [brute 6, recursive 6, std::gcd 6]   lcm = 36
 gcd(52, 20) = 4  [brute 4, recursive 4, std::gcd 4]   lcm = 260
 gcd(17, 5) = 1  [brute 1, recursive 1, std::gcd 1]   lcm = 85
 gcd(100, 75) = 25  [brute 25, recursive 25, std::gcd 25]   lcm = 300
 gcd(9, 0) = 9  [brute 9, recursive 9, std::gcd 9]
*/
