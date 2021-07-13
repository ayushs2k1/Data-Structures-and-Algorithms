#include <bits/stdc++.h>
using namespace std;

stack<int> st;
int ns[5];

void sortInserted(int x)
{
    if (st.size() == 0 || x > st.top())
    {
        st.push(x);
    }
    else
    {
        int a = st.top();
        st.pop();
        sortInserted(x);
        st.push(a);
    }
}

void sortStack()
{
    if (st.size() > 0)
    {
        int x = st.top();
        st.pop();
        sortStack();

        sortInserted(x);
    }
}

int main()
{
    st.push(30);
    st.push(-5);
    st.push(18);
    st.push(14);
    st.push(-3);

    cout << "Original Stack" << endl;

    cout << "30"
         << " "
         << "-5"
         << " "
         << "18"
         << " "
         << "14"
         << " "
         << "-3"
         << endl;

    sortStack();
    cout << "Sorted Stack"
         << endl;

    int i = 0;
    while (!st.empty())
    {
        char p = st.top();
        st.pop();
        ns[i] = p;
        i++;
    }

    //display of reversed stack
    cout << ns[4] << " " << ns[3] << " " << ns[2] << " "
         << ns[1] << " " << ns[0] << endl;
    return 0;
}