/*
Push the first element to stack.
Pick rest of the elements one by one and follow the 
following steps in loop. 

1.) Mark the current element as next.
2.) If stack is not empty, compare top element of stack
    with next.
3.) If next is greater than the top element,Pop element 
    from stack. next is the next greater element for the 
    popped element.
4.) Keep popping from the stack while the popped element 
    is smaller than next. next becomes the next greater 
    element for all such popped elements
5.) Finally, push the next in the stack.
6.) After the loop in step 2 is over, pop all the elements 
    from stack and print -1 as next element for them.
*/

#include<bits/stdc++.h>
using namespace std;

void printNGE(int arr[],int n){
    stack<int> s;
    unordered_map<int, int> mp;

    s.push(arr[0]);

    for(int i=1;i<n;i++){
        if(s.empty()){
            s.push(arr[i]);
            continue;
        }

        /*
           if stack is not empty, then
           pop an element from stack.
           If the popped element is smaller
           than next, then
           a) print the pair
           b) keep popping while elements are
           smaller and stack is not empty 
        */

    while(s.empty()==false && s.top()<arr[i]){
        mp[s.top()]=arr[i];
        s.pop();
    }

    s.push(arr[i]);
    }

    while(s.empty()==false){
        mp[s.top()]=-1;
        s.pop();
    }

    for(int i=0;i<n;i++){
        cout<< arr[i] << " ----> "<<mp[arr[i]]<<endl;
    }
}

int main(){
    int arr[]={11,13,21,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    printNGE(arr,n);
    return 0;
}