#include<bits/stdc++.h>
using namespace std;

//recursive function
// long long binPow(long long a, long long b){
//     long long result, temp;

//     if(b == 0) return 1;
//     if(b == 1) return a;

//     temp = binPow(a, b/2);
//     result = temp * temp;

//     if(b%2 == 1) result *=a;

//     return result;


// }

//Iterative Approch

long long binPow(long long a, long long b){
    long long result = 1;

    while (b > 0) {

        if (b % 2 == 1)
            result *= a;

        a = a * a;
        b = b / 2;
    }
    return result;

}

int main(){
    long long a, b, ans;

    cin >> a >> b;

    ans = binPow(a,b);
    cout << ans << " is the answer";
    return 0;
}