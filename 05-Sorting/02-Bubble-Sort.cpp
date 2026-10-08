/*
Bubble Sort mein hum adjacent elements ko compare karte hain.

Agar left wala element right wale se bada hai,
to dono ko swap kar dete hain.

Is process ko baar-baar repeat karte hain.

Har complete round ke baad sabse bada element
array ke end mein pahunch jata hai,
bilkul bubble ki tarah upar aata hai.

Phir next round mein last sorted element ko ignore karke
baaki elements par same process repeat hota hai,
jab tak array completely sorted na ho jaye.

Time Complexity: O(n²) worst / average
                 O(n)  best (already sorted, didSwap optimization ki wajah se)
Space Complexity: O(1)

INPUT (05-Sorting/input.txt):  n, phir n elements   e.g.  5 4 3 2 1 0
EXPECTED OUTPUT:               0 1 2 3 4
*/

#include<bits/stdc++.h>
using namespace std;

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
    Outer loop last index se start ho raha hai.

    Har round ke baad ek largest element
    apni correct position par end mein aa jata hai.

    Isliye next round mein us element ko
    dobara compare karne ki zarurat nahi hai.
    */

    for(int i = n - 1; i >= 1; i--){

        // OPTIMIZATION: is round mein koi swap hua ya nahi, ye track karenge
        bool didSwap = false;

        // Adjacent elements ko compare kar rahe hain
        // j+1 safe rahe isliye j <= i-1 tak jayega

        for(int j = 0; j <= i - 1; j++){

            // Agar left element right element se bada hai
            // to dono adjacent elements ko swap kar denge

            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                didSwap = true;
            }
        }

        // Agar poore round mein ek bhi swap nahi hua,
        // matlab array already sorted hai -> aage ke rounds bekaar hain, ruk jao.
        // Isi wajah se already-sorted array par Best Case O(n) ho jata hai.
        if(!didSwap){
            break;
        }
    }

    // Ab array completely sorted hai
    // Sorted array ko print kar rahe hain

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}