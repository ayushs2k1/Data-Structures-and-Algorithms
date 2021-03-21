#include<bits/stdc++.h>
using namespace std;

double EvaluatePrefix(string expression){
    stack<int> st;
    for(int j=expression.size()-1;j>=0;j--){
        if(expression[j]==' '){
            continue;
        }
        if(isdigit(expression[j])){
            double num=0,i=j;
            while(j<expression.size() && isdigit(expression[j])){
                j--;
            }
            j++;
            for(int k=j;k<=i;k++){
                num=(num*10)+double(expression[k]-'0');
            }
            st.push(num);
        }
        else{
            double op1=st.top();
            st.pop();
            double op2=st.top();
            st.pop();
            switch(expression[j]){
                case '+': {
                    st.push(op1+op2);
                    break;
                }
                case '-': {
                    st.push(op1-op2);
                    break;
                }
                case '*': {
                    st.push(op1*op2);
                    break;
                }
                case '/': {
                    st.push(op1/op2);
                    break;
                }
            }
        }
    }
    return st.top();
}

int main(){
    string expression="+ 9 * 12 6";
    cout<<EvaluatePrefix(expression)<<endl;
    return 0;
}