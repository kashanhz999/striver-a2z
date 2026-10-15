#include <bits/stdc++.h>
using namespace std;

int partision(vector<int> arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] >= pivot && j >= low)
        {
            j++;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(pivot, arr[j]);
    return j;
}

void quick_sort(vector<int> arr, int low, int high)
{
    if (low < high)
    {
        int pindex = partision(arr, low, high);

        quick_sort(arr, low, pindex);
        quick_sort(arr, pindex + 1, high);
    }
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    int n = arr.size();

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}