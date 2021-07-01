#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int minJump(int arr[], int n)
{
    if (n <= 1)
    {
        return 0;
    }

    if (arr[0] == 0)
    {
        return -1;
    }

    int maxreach = arr[0];
    int steps = arr[0];
    int jump = 1;

    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
        {
            return jump;
        }

        maxreach = max(maxreach, i + arr[i]);
        steps--;

        if (steps == 0)
        {
            jump++;

            if (i >= maxreach)
            {
                return -1;
            }

            steps = maxreach - i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of jumps to reach end is: " << minJump(arr, n) << endl;
    return 0;
}