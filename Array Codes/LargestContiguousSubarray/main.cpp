#include <bits/stdc++.h>

using namespace std;

void contiguoussum(int arr[], int n)
{
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    int s = 0;
    int start = 0;
    int end = 0;

    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + arr[i];
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << "The largest Contiguous Sum is: " << max_so_far << endl;
    cout << "The subarray is: ";
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    contiguoussum(arr, n);
    return 0;
}