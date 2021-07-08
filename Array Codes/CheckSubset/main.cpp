#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    unordered_set<int> S;

    for (int i = 0; i < n; i++)
    {
        S.insert(arr1[i]);
    }
    int p = S.size();

    for (int i = 0; i < m; i++)
    {
        S.insert(arr2[i]);
    }

    if (S.size() == p)
    {
        cout << "arr2[] is a subset of arr1[]" << endl;
    }
    else
    {
        cout << "arr2[] is not a subset of arr1[]" << endl;
    }

    return 0;
}