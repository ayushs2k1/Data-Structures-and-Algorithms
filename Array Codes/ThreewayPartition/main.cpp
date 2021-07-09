#include <bits/stdc++.h>
using namespace std;

void ThreewayPartition(int arr[], int n, int lowVal, int highVal)
{
    int start = 0, end = n - 1;

    for (int i = 0; i <= end;)
    {
        if (arr[i] < lowVal)
        {
            swap(arr[i], arr[start]);
            start++;
            i++;
        }
        else if (arr[i] > highVal)
        {
            swap(arr[i], arr[end]);
            end--;
            i++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    int n = sizeof(arr) / sizeof(arr[0]);
    ThreewayPartition(arr, n, 10, 20);
    cout << "Modified array is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}