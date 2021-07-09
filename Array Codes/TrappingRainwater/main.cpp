#include <bits/stdc++.h>
using namespace std;

void RainwaterTrap(int arr[], int n)
{
    int left = 0;
    int right = n - 1;
    int left_max = 0;
    int right_max = 0;
    int result = 0;

    while (left <= right)
    {
        if (right_max <= left_max)
        {
            result += max(0, right_max - arr[right]);
            right_max = max(right_max, arr[right]);
            right -= 1;
        }
        else
        {
            result += max(0, left_max - arr[left]);
            left_max = max(left_max, arr[left]);
            left += 1;
        }
    }
    cout << "The Amount(Units) of Rainwater trapped is: " << result;
}

int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    RainwaterTrap(arr, n);
    return 0;
}