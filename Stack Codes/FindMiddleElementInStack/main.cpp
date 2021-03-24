/*The important question is, whether to use a linked 
list or array for implementation of stack? 
Please note that, we need to find and delete middle 
element. Deleting an element from middle is not O(1)
for array. Also, we may need to move the middle pointer
up when we push an element and move down when we pop().
In singly linked list, moving middle pointer in both 
directions is not possible. The idea is to use Doubly 
Linked List (DLL). We can delete middle element in O(1)
 time by maintaining mid pointer. We can move mid pointer
  in both directions using previous and next pointers. */
#include<bits/stdc++.h>
using namespace std;

class DLLNode{
    public:
    int data;
    DLLNode* prev;
    DLLNode* next;
};

class MyStack{
    public:
    DLLNode* head;
    DLLNode* mid;
    int count;
};

MyStack *createMyStack(){
    MyStack *ms=new MyStack();
    ms->count=0;
    return ms;
};

void push(MyStack *ms,int new_data){
    DLLNode *newnode= new DLLNode();
    newnode->data=new_data;
    newnode->prev=NULL;
    newnode->next=ms->head;
    ms->count+=1;

    if(ms->count==1){
        ms->mid=newnode;
    }
    else{
        ms->head->prev=newnode;

        if(!(ms->count & 1)){
            ms->mid=ms->mid->prev;
        }
    }
    ms->head=newnode;
}

int pop(MyStack *ms){
    if(ms->count==0){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    
    DLLNode *head=ms->head;
    int item=head->data;
    ms->head=head->next;

    if(ms->head!=NULL){
        ms->head->prev=NULL;
    }
    ms->count-=1;

    if((ms->count) & 1){
        ms->mid=ms->mid->next;
    }
    free(head);

    return item;
}

int findMiddle(MyStack *ms){
    if(ms->count==0){
        cout<<"The Stack is empty"<<endl;
        return -1;
    }
    else{
        return ms->mid->data;
    }
}

int main(){
    MyStack *ms=createMyStack();
    push(ms,11);
    push(ms,22);
    push(ms,33);
    push(ms,44);
    push(ms,55);
    push(ms,66);
    push(ms,77);
    
    cout<<"Item popped is "<<pop(ms)<<endl;
    cout<< "Item popped is "<<pop(ms)<<endl;
    cout<< "Middle Element is "<<findMiddle(ms)<<endl;
    return 0;
}