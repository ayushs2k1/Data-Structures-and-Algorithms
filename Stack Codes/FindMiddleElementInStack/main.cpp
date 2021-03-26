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

//A doubly linked list node
class DLLNode{
    public:
    int data;
    DLLNode* prev;
    DLLNode* next;
};

/*Representation of stack data structure that supports
findMiddle() in O(1) time. The stack is implemented using
DLL. It maintains pointer to head,pointer to the middle node
and count of nodes.*/
class MyStack{
    public:
    DLLNode* head;
    DLLNode* mid;
    int count;
};

//Function to create stack data structure.
MyStack *createMyStack(){
    MyStack *ms=new MyStack();
    ms->count=0;
    return ms;
};

//Function to push an element in the stack.
void push(MyStack *ms,int new_data){
    //allocate DLLNode and put in data.
    DLLNode *newnode= new DLLNode();
    newnode->data=new_data;
 
    //Since we are adding at the beginning, prev will always be NULL
    newnode->prev=NULL;
 
    //link the old list off the new DLLNode
    newnode->next=ms->head;
 
    //Increment count of items in the stack
    ms->count+=1;
    
    /*Change the mid pointer in two cases:
    1.) Linked list is empty
    2.) Number of nodes in the linked list is odd*/
    if(ms->count==1){
        ms->mid=newnode;
    }
    else{
        ms->head->prev=newnode;
        
        //Update mid if ms->count is odd
        if(!(ms->count & 1)){
            ms->mid=ms->mid->prev;
        }
    }
    //Move head to point to the new DLLNode
    ms->head=newnode;
}

//Funtion to pop an element from the stack
int pop(MyStack *ms){
 
    //Stack underflow
    if(ms->count==0){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    
    DLLNode *head=ms->head;
    int item=head->data;
    ms->head=head->next;

    /*If linked list doesn't become empty, update prev
    of new head as NULL*/
    if(ms->head!=NULL){
        ms->head->prev=NULL;
    }
    ms->count-=1;
    
    /*UPdate the mid pointer when we have odd number of 
    elements in the stack,i.e, move down the mid pointer*/
    if((ms->count) & 1){
        ms->mid=ms->mid->next;
    }
    free(head);

    return item;
}

//Function to find the middle element of the stack
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
