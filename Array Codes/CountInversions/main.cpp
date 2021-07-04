#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i = left, j = mid, k = left;
    int invcount = 0;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            invcount += mid - i;
        }
    }
    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
    return invcount;
}

int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, invcount = 0;
    if (right > left)
    {
        mid = (right + left) / 2;
        invcount += _mergeSort(arr, temp, left, mid);
        invcount += _mergeSort(arr, temp, mid + 1, right);
        invcount += merge(arr, temp, left, mid + 1, right);
    }
    return invcount;
}

int mergeSort(int arr[], int n)
{
    int temp[n];
    return _mergeSort(arr, temp, 0, n - 1);
}

int main()
{
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = mergeSort(arr, n);
    cout << "The Number of Inversions are: " << ans << endl;
    return 0;
}