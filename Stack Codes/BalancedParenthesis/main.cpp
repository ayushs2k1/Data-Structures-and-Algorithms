#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string exp){
    stack<char> s;
    char ch;
    for(int i=0;i<exp.length();i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            s.push(exp[i]);
            continue;
        }
        if(s.empty()){
            return false;
        }
        else{
            switch(exp[i]){
                case ')': {
                    ch=s.top();
                    s.pop();
                    if(ch=='{' || ch=='['){
                        return false;
                    }
                    break;
                }
                case '}': {
                    ch=s.top();
                    s.pop();
                    if(ch=='(' || ch=='['){
                        return false;
                    }
                    break;
                }
                case ']': {
                    ch=s.top();
                    s.pop();
                    if(ch=='(' || ch=='{'){
                        return false;
                    }
                    break;
                }
            }
        }
    }
    return (s.empty());
}

int main(){
    string exp="[{A+B}(C+D){E(F+G)}]";
    if(isBalanced(exp)){
        cout<<"The String is balanced"<<endl;
    }
    else{
        cout<<"The String is not balanced"<<endl;
    }
    return 0;
}