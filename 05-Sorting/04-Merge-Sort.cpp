#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>& arr, int low, int mid, int high){
    vector<int> temp;
    int right, left;
    right = mid+1;
    left = low;

    while(left <=mid && right <=high){
        if(arr[left] <= arr[right]){
            temp.emplace_back(arr[left]);
            left++;
        }
        else{
            temp.emplace_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.emplace_back(arr[left]);
        left++;
    }
    while(right <=high){
        temp.emplace_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}

void merge_sort(vector<int>& arr, int low, int high){
    int mid;

    if(low>=high) return;
    mid = (low+high)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int main(){
    vector<int> arr = {5,4,3,2,1};
    int n = arr.size();

    merge_sort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}