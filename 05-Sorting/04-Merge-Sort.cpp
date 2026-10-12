
#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[], int low, int mid, int high) {
    vector<int> temp;

    int left = low;
    int right = mid + 1;

    // Dono sorted halves ko merge karo
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Left half ke remaining elements
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Right half ke remaining elements
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Temporary array ko original array mein copy karo
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void Merge_Sort(int arr[], int low, int high) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;

    Merge_Sort(arr, low, mid);
    Merge_Sort(arr, mid + 1, high);

    Merge(arr, low, mid, high);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Merge_Sort(arr.data(), 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << '\n';

    return 0;
}
