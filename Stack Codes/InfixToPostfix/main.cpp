#include<iostream>
#include<stack>
using namespace std;

int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

void InfixToPostfix(string s){
    stack<char> st;
    st.push('#');
    int l=s.length();
    string ns;
    for(int i=0;i<l;i++){
        // If the scanned character is an operand, add it to output string.
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            ns+=s[i];
        }
        // If the scanned character is an ‘(‘, push it to the stack.
        else if(s[i]=='('){
            st.push(s[i]);
        }
        // If the scanned character is an ‘)’,pop and to output string from the stack until an ‘(‘ is encountered. 
        else if(s[i]==')'){
            while(st.top()!='#' && st.top()!='('){
                char c=st.top();
                st.pop();
                ns+=c;
            }
            if(st.top()=='('){
                char c=st.top();
                st.pop();
            }
        }
        //If an operator is scanned 
        else{
            while(st.top()!='#' && prec(s[i])<=prec(st.top())){
                char c=st.top();
                st.pop();
                ns+=c;
            }
            st.push(s[i]);
        }
    }
    // Pop all the remaining elements from the stack
    while(st.top()!='#'){
        char c=st.top();
        st.pop();
        ns+=c;
    }
    cout<<ns<<endl;
}

int main(){
    string exp="a+b*(c^d-e)^(f+g*h)-i";
    InfixToPostfix(exp);
    return 0;
}