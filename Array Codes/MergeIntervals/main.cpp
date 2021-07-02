#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int start, end;
};

bool mycomp(Interval a, Interval b)
{
    return a.start < b.start;
}

void mergeIntervals(Interval arr[], int n)
{
    sort(arr, arr + n, mycomp);

    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[index].end > arr[i].start)
        {
            arr[index].end = max(arr[i].end, arr[index].end);
            arr[index].start = min(arr[i].start, arr[index].start);
        }
        else
        {
            index++;
            arr[index] = arr[i];
        }
    }
    cout << "The merged Interval is: ";
    for (int i = 0; i <= index; i++)
    {
        cout << "[" << arr[i].start << "," << arr[i].end << "]";
    }
}

int main()
{
    Interval arr[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}