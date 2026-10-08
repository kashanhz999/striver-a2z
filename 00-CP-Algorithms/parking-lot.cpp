#include <bits/stdc++.h>
using namespace std;

long long binPow(long long a, long long b) {
    long long result = 1;

    while (b > 0) {
        if (b % 2 == 1)
            result *= a;

        a = a * a;
        b = b / 2;
    }

    return result;
}

int main() {
    long long n;
    cin >> n;

    long long ans = 8 * binPow(3, n - 2);

    cout << ans << endl;

    return 0;
}