/*
for redundancy two condition will arise while popping- 
 

If immediate pop hits an open parenthesis ‘(‘, then we have
 found a duplicate parenthesis. For example, (((a+b))+c) has
 duplicate brackets around a+b. When we reach second “)” 
 after a+b, we have “((” in the stack. Since the top of 
 stack is an opening bracket, we conclude that there are 
 duplicate brackets. 
 
If immediate pop doesn’t hit any operand(‘*’, ‘+’, ‘/’, ‘-‘)
 then it indicates the presence of unwanted brackets surrounded
 by expression. For instance, (a)+b contain unwanted () around
 a thus it is redundant.
*/

#include<bits/stdc++.h>
using namespace std;

bool checkRedundancy(string& str){
    stack<char> st;
    for(auto& ch:str){
        if(ch==')'){
            char top=st.top();
            st.pop();

            bool flag=true;

            while(!st.empty() && top!='('){
                if(top=='+' || top=='-' || top=='*' || top=='/'){
                    flag=false;
                }

                top=st.top();
                st.pop();
            }
            if(flag==true){
                return true;
            }
        }
        else{
            st.push(ch);
        }
    }
    return false;
}

void findRedundant(string& str)
{
    bool ans = checkRedundancy(str);
    if (ans == true)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    string str = "((a+b))";
    findRedundant(str);
 
    str = "(a+(b)/c)";
    findRedundant(str);
 
    str = "(a+b*(c-d))";
    findRedundant(str);
 
    return 0;
}