#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void reverse(int arr[], int start, int n)
{
    int i = start, j = n - 1;
    while (i < j)
    {
        swap(arr, i, j);
        i++;
        j--;
    }
}

void nextPermutation(int arr[], int n)
{
    int i = n - 2;
    while (i >= 0 && arr[i + 1] <= arr[i])
    {
        i--;
    }

    if (i >= 0)
    {
        int j = n - 1;
        while (arr[j] <= arr[i])
        {
            j--;
        }
        swap(arr, i, j);
    }
    reverse(arr, i + 1, n);
    cout << "The Next Permutation of the given array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 2, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    nextPermutation(arr, n);
    return 0;
}