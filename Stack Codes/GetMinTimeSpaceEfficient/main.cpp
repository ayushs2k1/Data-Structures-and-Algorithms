/*
Consider the following SpecialStack
16  --> TOP
15
29
19
18

When getMin() is called it should return 15, 
which is the minimum element in the current stack. 

If we do pop two times on stack, the stack becomes
29  --> TOP
19
18

When getMin() is called, it should return 18 
which is the minimum in the current stack.
*/


/*
Push(x) : Inserts x at the top of stack.

If stack is empty, insert x into the stack and make 
minEle equal to x. If stack is not empty, compare x 
with minEle. Two cases arise:

-> If x is greater than or equal to minEle, simply insert x.

-> If x is less than minEle, insert (2*x – minEle) into 
the stack and make minEle equal to x. For example, let 
previous minEle was 3. Now we want to insert 2.We update
 minEle as 2 and insert 2*2 – 3 = 1 into the stack.
*/



/*
Pop() : Removes an element from top of stack.

Remove element from top. Let the removed element be y.
Two cases arise:

-> If y is greater than or equal to minEle, the minimum 
   element in the stack is still minEle.

-> If y is less than minEle, the minimum element now becomes
   (2*minEle – y), so update (minEle = 2*minEle – y). This is
   where we retrieve previous minimum from current minimum
   and its value in stack. For example, let the element to 
   be removed be 1 and minEle be 2. We remove 1 and update
   minEle as 2*2 – 1 = 3.
*/

#include<bits/stdc++.h>
using namespace std;

struct MyStack{
    stack<int> s;
    int minEle;

    void getMin(){
        if(s.empty()){
            cout<<"The stack is empty"<<endl;
        }
        else{
            cout<<"Minimum element of the stack is: "<<minEle<<endl;
        }
    }

    void peek(){
        if(s.empty()){
            cout<<"The stack is empty"<<endl;
            return;
        }
        else{
            int t=s.top();
            cout<<"Top most element is: ";

            (t<minEle)? cout<<minEle: cout<<t;
        }
    }

    void pop(){
        if(s.empty()){
            cout<<"The stack is empty"<<endl;
            return;
        }
        else{
            cout<<"The topmost element is removed: ";
            int t=s.top();
            s.pop();

            if(t<minEle){
                cout<<minEle<<endl;
                minEle=2*minEle-t;
            }
            else{
                cout<<t<<endl;
            }
        }
    }

    void push(int x){
        if(s.empty()){
            minEle=x;
            s.push(x);
            cout<<"The number inserted: "<<x<<endl;
            return;
        }
        else{
            if(x<minEle){
                s.push(2*x-minEle);
                minEle=x;
            }
            else{
                s.push(x);
            }
            cout<<"The number inserted: "<<x<<endl;
        }
    }
};

int main(){
    MyStack s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.peek();

    return 0;
}