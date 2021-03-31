/*
Given a set of time intervals in any order, merge all 
overlapping intervals into one and output the result which 
should have only mutually exclusive intervals. Let the 
intervals be represented as pairs of integers for simplicity.
For example, let the given set of intervals be {{1,3}, {2,4}, 
{5,7}, {6,8}}. The intervals {1,3} and {2,4} overlap with 
each other, so they should be merged and become {1, 4}. 
Similarly, {5, 7} and {6, 8} should be merged and become 
{5, 8}
*/

/*
Approach:

1. Sort the intervals based on increasing order of 
   starting time.
2. Push the first interval on to a stack.
3. For each interval do the following
   a. If the current interval does not overlap with the 
      stack top, push it.
   b. If the current interval overlaps with stack top and 
      ending time of current interval is more than that of 
      stack top,update stack top with the ending time of 
      current interval.
4. At the end stack contains the merged intervals. 
*/

#include<bits/stdc++.h>
using namespace std;
 
// An interval has start time and end time
struct Interval
{
    int start, end;
};
 
bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}
 
// The main function that takes a set of intervals, merges
// overlapping intervals and prints the result
void mergeIntervals(Interval arr[], int n)
{
    // Test if the given set has at least one interval
    if (n <= 0)
        return;
 
    // Create an empty stack of intervals
    stack<Interval> s;
 
    // sort the intervals in increasing order of start time
    sort(arr, arr+n, compareInterval);
 
    // push the first interval to stack
    s.push(arr[0]);
 
    // Start from the next interval and merge if necessary
    for (int i = 1 ; i < n; i++)
    {
        // get interval from stack top
        Interval top = s.top();
 
        // if current interval is not overlapping with 
        // stack top,push it to the stack
        if (top.end < arr[i].start)
            s.push(arr[i]);
 
        // Otherwise update the ending time of top if 
        // ending of current interval is more
        else if (top.end < arr[i].end)
        {
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }
 
    // Print contents of stack
    cout << "\n The Merged Intervals are: ";
    while (!s.empty())
    {
        Interval t = s.top();
        cout << "[" << t.start << "," << t.end << "] ";
        s.pop();
    }
    return;
}
 
int main()
{
    Interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}