#include<bits/stdc++.h>
using namespace std;

/*
Insertion Sort mein hum array ke left part ko sorted maante hain.

Har iteration mein ek current element lete hain aur usko
left side ke sorted elements ke beech uski correct position par insert karte hain.

Agar left wala element current element se bada hai,
to dono ko swap karte hain aur current element ko left move karte hain.

Ye process tab tak repeat hota hai jab tak poora array sorted nahi ho jata.

Time Complexity: O(n²) worst / average (reverse sorted array)
                 O(n)  best (already sorted - while loop ek baar bhi nahi chalta)
Space Complexity: O(1)

INPUT (05-Sorting/input.txt):  n, phir n elements   e.g.  5 4 3 2 1 0
EXPECTED OUTPUT:               0 1 2 3 4
*/

int main(){

    // User se array ka size input le rahe hain
    int n;
    cin >> n;

    // Given size ka array declare kar rahe hain
    int arr[n];

    // User se array ke saare elements input le rahe hain
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    /*
    Index 0 ko already sorted maan sakte hain,
    isliye Insertion Sort index 1 se start karte hain.

    Har iteration mein current element ko
    left side ke sorted part mein insert karenge.
    */

    for(int i = 1; i < n; i++){

        // Current element ka index store kar rahe hain
        int j = i;

        /*
        Jab tak:

        1. j 0 se bada hai
        2. Left wala element current element se bada hai

        tab tak dono elements ko swap karenge.

        Isse current element left side mein
        apni correct position par move karega.
        */

        while(j > 0 && arr[j - 1] > arr[j]){

            // Current element ko left wale element ke saath swap kar rahe hain
            swap(arr[j], arr[j - 1]);

            // Current element ko ek position left move kar rahe hain
            j--;
        }
    }

    // Ab array completely sorted hai
    // Sorted array ko print kar rahe hain

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}