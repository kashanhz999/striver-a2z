#include<bits/stdc++.h>
using namespace std;

/*
Selection Sort mein hum array ki har position ke liye
baaki unsorted elements mein se sabse chhota element find karte hain.

Phir us minimum element ko current position wale element ke saath swap kar dete hain.

Ye process tab tak repeat hota hai jab tak poora array sorted nahi ho jata.

Time Complexity: O(n²) - best, average aur worst teeno mein (array sorted ho tab bhi poora scan karta hai)
Space Complexity: O(1)

INPUT (05-Sorting/input.txt):  n, phir n elements   e.g.  5 4 3 2 1 0
EXPECTED OUTPUT:               0 1 2 3 4
*/

int main(){

    // User se array ka size input le rahe hain
    int size_of_arr;
    cin >> size_of_arr;

    // Given size ka array declare kar rahe hain
    int arr[size_of_arr];

    // User se array ke saare elements input le rahe hain
    for(int i = 0; i < size_of_arr; i++){
        cin >> arr[i];
    }

    // Ab hum Selection Sort apply karenge
    // Is point par array unsorted hai

    for(int i = 0; i < size_of_arr - 1; i++){

        // Pehle assume kar rahe hain ki current index par minimum element hai
        int min_ele = i;

        // Current element ke next element se loop start karenge
        // Aur baaki unsorted elements mein minimum element find karenge

        for(int j = i + 1; j < size_of_arr; j++){

            // Agar current element, minimum element se chhota hai
            // To min_ele ko current element ke index par update kar denge

            if(arr[j] < arr[min_ele]){
                min_ele = j;
            }
        }

        // Ab minimum element ka index mil gaya hai
        // Isliye minimum element ko current position wale element se swap kar denge

        swap(arr[i], arr[min_ele]);
    }

    // Ab array completely sorted hai
    // Sorted array ko print kar rahe hain

    for(int i = 0; i < size_of_arr; i++){
        cout << arr[i] << " ";
    }

    return 0;
}