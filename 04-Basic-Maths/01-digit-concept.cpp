/*
===============================================================================
 01 - DIGIT EXTRACTION (the base of every problem in this folder)
===============================================================================
 INPUT: numbers in 04-Basic-Maths/input.txt (separated by spaces / new lines)

 n = 7789   ->   we want its digits 7, 7, 8, 9

 Two operations do all the work:
     n % 10  -> gives the LAST digit       7789 % 10 = 9
     n / 10  -> REMOVES the last digit     7789 / 10 = 778

 Repeat until n becomes 0:

     n      n % 10   n / 10
     7789     9       778
     778      8       77
     77       7       7
     7        7       0     <- stop

 NOTE: digits come out in REVERSE order (9, 8, 7, 7). That's why this same
 loop can also REVERSE a number (see 03-reverse-number.cpp).

 Time: O(number of digits) = O(log10 n)
 (n is divided by 10 every step, so the loop runs log10(n) + 1 times)
===============================================================================
*/

#include<bits/stdc++.h>
using namespace std;

void printDigits(int n){
    if(n == 0){                 // the while loop below would print nothing for 0
        cout << 0;
        return;
    }
    while(n > 0){
        cout << n % 10 << " ";  // last digit
        n = n / 10;             // remove last digit
    }
}

int main(){
    int n;
    while(cin >> n){            // read every number in input.txt
        cout << n << " -> digits (last to first): ";
        printDigits(n);
        cout << "\n";
    }
    return 0;
}

/*
 EXPECTED OUTPUT (input: 0 7 12 121 153 1634 7789):
 0 -> digits (last to first): 0
 7 -> digits (last to first): 7
 12 -> digits (last to first): 2 1
 121 -> digits (last to first): 1 2 1
 153 -> digits (last to first): 3 5 1
 1634 -> digits (last to first): 4 3 6 1
 7789 -> digits (last to first): 9 8 7 7
*/
