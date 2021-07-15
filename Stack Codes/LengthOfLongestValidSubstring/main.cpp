/*

The idea to solve this problem is to traverse the string on
and keep track of the count of open parentheses and close 
parentheses with the help of two counters left and right 
respectively.

First, the string is traversed from the left towards the right
and for every “(” encountered, the left counter is incremented
by 1 and for every “)” the right counter is incremented by 1.

Whenever the left becomes equal to right, the length of the 
current valid string is calculated and if it greater than the 
current longest substring, then value of required longest 
substring is updated with current string length.

If the right counter becomes greater than the left counter, 
then the set of parentheses has become invalid and hence the 
left and right counters are set to 0.

After the above process, the string is similarly traversed 
from right to left and similar procedure is applied */

#include <bits/stdc++.h>
using namespace std;
 
int solve(string s, int n)
{
    int left = 0, right = 0, maxlength = 0;
 
    // Iterating the string from left to right
    for (int i = 0; i < n; i++)
    {
        // If "(" is encountered,
        // then left counter is incremented
        // else right counter is incremented
        if (s[i] == '(')
            left++;
        else
            right++;
 
        // Whenever left is equal to right, it signifies
        // that the subsequence is valid and
        if (left == right)
            maxlength = max(maxlength, 2 * right);
 
        // Reseting the counters when the subsequence
        // becomes invalid
        else if (right > left)
            left = right = 0;
    }
 
    left = right = 0;
 
    // Iterating the string from right to left
    for (int i = n - 1; i >= 0; i--) {
 
        // If "(" is encountered,
        // then left counter is incremented
        // else right counter is incremented
        if (s[i] == '(')
            left++;
        else
            right++;
 
        // Whenever left is equal to right, it signifies
        // that the subsequence is valid and
        if (left == right)
            maxlength = max(maxlength, 2 * left);
 
        // Reseting the counters when the subsequence
        // becomes invalid
        else if (left > right)
            left = right = 0;
    }
    return maxlength;
}
 
int main()
{
    cout << solve("((()()()()(((())", 16);
    return 0;
}