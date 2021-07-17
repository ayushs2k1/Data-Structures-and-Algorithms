#include<bits/stdc++.h>
using namespace std;

//A LL Node to store a queue entry
struct QNode{
    int key;
    struct QNode* next;
};

//The queue, front stores the front node of LL and rear stores the last node of LL
struct Queue{
    struct QNode *front, *rear;
};

//To create a new linked list node
struct QNode* newNode(int k){
    struct QNode *temp=(struct QNode*)malloc(sizeof(struct QNode));
    temp->key=k;
    temp->next=NULL;
    return temp;
}

//To create an empty queue
struct Queue *createQueue(){
    struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue));
    q->front=q->rear=NULL;
    return q;
}

void enqueue(struct Queue *q, int k){
    //Create a new LL Node
    struct QNode *temp=newNode(k);

    //If queue is empty
    if(q->rear==NULL){
        q->front=q->rear=temp;
        return;
    }
    else{
        q->rear->next=temp;
        q->rear=temp;
    }
}

struct QNode *dequeue(struct Queue *q){
    //If queue is empty
    if(q->front==NULL){
        return NULL;
    }
    //Store previous front and move front one node ahead
    else{
        struct QNode *temp=q->front;
        q->front=q->front->next;
        //If front becomes NULL,then change the rear to NULL as well
        if(q->front==NULL){
            q->rear=NULL;
        }
        return temp;
    }
}

int main(){
    struct Queue *q=createQueue();
    enqueue(q,10);
    enqueue(q,20);
    dequeue(q);
    dequeue(q);
    enqueue(q,30);
    enqueue(q,40);
    enqueue(q,50);
    struct QNode *n=dequeue(q);
    if(n!=NULL){
        cout<<"Dequeued item is "<<n->key<<endl;
    }
    return 0;
}