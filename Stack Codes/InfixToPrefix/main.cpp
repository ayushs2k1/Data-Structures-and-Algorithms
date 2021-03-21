/*
Step 1: Reverse the infix expression i.e A+B*C 
          will become C*B+A. Note while reversing 
          each ‘(‘ will become ‘)’ and each ‘)’ 
          becomes ‘(‘.
Step 2: Obtain the “nearly” postfix expression of
        the modified expression i.e CB*A+.
Step 3: Reverse the postfix expression. Hence in 
        our example prefix is +A*BC. 
*/

#include<bits/stdc++.h>
using namespace std;

bool isOperator(char ch){
    return (!isdigit(ch) && !(isalpha(ch)));
}

bool getPriority(char ch){
    if(ch=='+' || ch=='-'){
        return 1;
    }
    else if(ch=='*' || ch=='/'){
        return 2;
    }
    else if(ch=='^'){
        return 3;
    }
    else{
        return 0;
    }
}

string infixtopostfix(string infix){
    infix='('+infix+')';
    int l=infix.size();
    stack<char> st;
    string output;

    for(int i=0;i<l;i++){
        if(isalpha(infix[i]) || isdigit(infix[i])){
            output+=infix[i];
        }
        else if(infix[i]=='('){
            st.push('(');
        }
        else if(infix[i]==')'){
            while(st.top()!='('){
                output+=st.top();
                st.pop();
            }
            //Remove '(' from the stack
            st.pop();
        }
        else{
            if(isOperator(st.top())){
               while ((getPriority(infix[i])< getPriority(st.top())) || (getPriority(infix[i])<= getPriority(st.top()) && infix[i] == '^')){
                   output+=st.top();
                   st.pop();
               }
               st.push(infix[i]); 
            }
        }
    }
    return output;
}

string infixtoprefix(string infix){
    int l=infix.size();
    reverse(infix.begin(),infix.end());
    for(int i=0;i<l;i++){
        if(infix[i]=='('){
            infix[i]=')';
            i++;
        }
        else if(infix[i]==')'){
            infix[i]='(';
            i++;
        }
    }
    string prefix=infixtopostfix((infix));
    reverse(prefix.begin(),prefix.end());
    return prefix;
}

int main(){
    string s = ("(A-B/C)*(A/K-L)");
    cout<<infixtoprefix(s)<<endl;
    return 0;
}
