/*
This method makes sure that newly entered element is 
always at the front of 'q1', so that pop operation just 
dequeues from 'q1'. 'q2' is used to put every new element 
at front of 'q1'.

1.) push(s, x) operation's step are described below:
        Enqueue x to q2

        One by one dequeue everything from q1 and enqueue to q2.

        Swap the names of q1 and q2


2.) pop(s) operation's function are described below:
        Dequeue an item from q1 and return it.
*/

#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q1,q2;
    int curr_size;

public:
    Stack(){
        curr_size=0;
    }

    void push(int x){
        curr_size++;
        q2.push(x);

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> q=q1;
        q1=q2;
        q2=q;
    }

    void pop(){
        if(q1.empty()){
            return;
        }
        else{
            q1.pop();
            curr_size--;
        }
    }

    int top(){
        if(q1.empty()){
            return -1;
        }
        else{
            return q1.front();
        }
    }

    int size(){
        return curr_size;
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "current size: " << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << "current size: " << s.size() << endl;
    return 0;
}