#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        sort(arr, arr + n);
        int result = arr[n - 1] - arr[0];
        int min_ele, max_ele;
        for (int i = 1; i <= n - 1; i++)
        {
            max_ele = max(arr[i - 1] + k, arr[n - 1] - k);
            min_ele = min(arr[0] + k, arr[i] - k);
            result = min(result, max_ele - min_ele);
        }
        return result;
    }
};

int main()
{
    int k = 6;
    int arr[] = {1, 10, 14, 14, 14, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution ob;
    auto ans = ob.getMinDiff(arr, n, k);
    cout << "The maximum difference after minimizing is: " << ans << endl;
    return 0;
}