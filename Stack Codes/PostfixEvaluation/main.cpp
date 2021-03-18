#include<iostream>
#include<stack>

using namespace std;

bool isNumericDigit(char C){
    if(C>='0' && C<='9'){
        return true;
    }
    else{
        return false;
    }
}

bool isOperator(char C){
    if(C=='+' || C=='-' || C=='*' || C=='/'){
        return true;
    }
    else{
        return false;
    }
}

int PerformOperation(char operation,int operand1,int operand2){
    if(operation=='+'){
        return operand2+operand1;
    }
    else if(operation=='-'){
        return operand2-operand1;
    }
    else if(operation=='*'){
        return operand2*operand1;
    }
    else if(operation=='/'){
        return operand2/operand1;
    }
    else{
        cout<<"Unexpected error"<<endl;
        return -1;
    }
}

int EvaluatePostfix(string expression){
    stack<int> st;
    
    for(int i=0;i<expression.length();i++){
        if(expression[i]==' ' || expression[i]==','){
            continue;
        }
        else if(isOperator(expression[i])){
            int operand1=st.top();
            st.pop();
            int operand2=st.top();
            st.pop();
            int result=PerformOperation(expression[i],operand1,operand2);
            st.push(result);
        }
        else if(isNumericDigit(expression[i])){
            int operand=0;
            while(i<expression.length() && isNumericDigit(expression[i])){
                operand=(operand*10)+(expression[i]-'0');
                i++;
            }
            i--;
            st.push(operand);
        }
    }
    return st.top();
}

int main(){
    string expression;
    cout<<"Enter Postfix Expression: "<<endl;
    cin>>expression;
    int result=EvaluatePostfix(expression);
    cout<<"The evaluated postfix expression is: "<<result<<endl;
}