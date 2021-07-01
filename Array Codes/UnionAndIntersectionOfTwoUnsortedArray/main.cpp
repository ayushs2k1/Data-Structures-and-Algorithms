#include <bits/stdc++.h>
using namespace std;

void getUnionandIntersection(int a[], int na, int b[], int nb)
{
    set<int> s;
    set<int> s1;
    set<int> s2;
    for (int i = 0; i < na; i++)
    {
        s.insert(a[i]);
        s1.insert(a[i]);
    }
    for (int i = 0; i < nb; i++)
    {
        s.insert(b[i]);
        s2.insert(b[i]);
    }

    cout << "The number of elements in the Union array: " << s.size() << endl;
    cout << "The elements of the Union Array is: ";
    for (auto itr = s.begin(); itr != s.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
    int count = 0;
    if (na > nb)
    {
        cout << "The elements of the Intersection Array is: ";
        for (auto itr2 = s2.begin(); itr2 != s2.end(); itr2++)
        {
            for (auto itr1 = s1.begin(); itr1 != s1.end(); itr1++)
            {
                if (*itr2 == *itr1)
                {
                    cout << *itr2 << " ";
                    count++;
                }
            }
        }
        cout << endl;
        cout << "The number of elements in the Intersection Array: " << count << endl;
    }
    else
    {
        cout << "The elements of the Intersection Array is: ";
        for (auto itr1 = s1.begin(); itr1 != s1.end(); itr1++)
        {
            for (auto itr2 = s2.begin(); itr2 != s1.end(); itr2++)
            {
                if (*itr2 == *itr1)
                {
                    cout << *itr1 << " ";
                    count++;
                }
            }
        }
        cout << endl;
        cout << "The number of elements in the Intersection Array: " << count << endl;
    }
}

int main()
{
    int a[] = {7, 1, 5, 2, 3, 6};
    int na = sizeof(a) / sizeof(a[0]);
    int b[] = {3, 8, 6, 20, 7};
    int nb = sizeof(b) / sizeof(b[0]);
    getUnionandIntersection(a, na, b, nb);
    return 0;
}