#include <bits/stdc++.h>
using namespace std;

int MinLenSubarraySum(int arr[], int n, int x)
{
    int min_len = n + 1;
    int curr_sum = 0;
    int start = 0, end = 0;

    while (end < n)
    {
        while (curr_sum <= x && end < n)
        {
            curr_sum += arr[end];
            end++;
        }

        while (curr_sum > x && start < n)
        {
            if (end - start < min_len)
            {
                min_len = end - start;
            }
            else
            {
                curr_sum -= arr[start];
                start++;
            }
        }
    }
    return min_len;
}

int main()
{
    int arr[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = MinLenSubarraySum(arr, n, x);
    (res == n + 1) ? cout << "Not possible\n" : cout << res << endl;
    return 0;
}