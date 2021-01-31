#include<stdio.h>
#include<stdlib.h>

struct node{
     int data;
     struct node* next;
}node;

void push(struct node** head,int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
}

int detectloop(struct node* head){
    struct node* slowptr=head;
    struct node* fastptr=head;
    while(slowptr && fastptr && fastptr->next){
         slowptr=slowptr->next;
         fastptr=fastptr->next->next;
         if(slowptr==fastptr){
             return 1;
         }
    }
    return 0;
}

int main(){
    struct node* head=NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
    //create a loop for testing
    head->next->next->next->next=head;
    if(detectloop(head)){
         printf("Loop found");
    }
    else{
         printf("No Loop found");
    }
    return 0;
}
