//https://www.studytonight.com/post/program-to-reverse-a-linked-list-in-cpp#    for explanation
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

static void reverse(node** head){
    node* prev=NULL;
    node* current=*head;
    node* next=NULL;
    while(current!=NULL){
         next=current->next;   //store next
         current->next=prev;   //Reverse current node's pointer
         //move pointers one position ahead
         prev=current;
         current=next;
    }
    *head=prev;
}

void push(node** head,int data){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
}

void print(node* head){
    node* temp=head;
    while(temp!=NULL){
         printf("%d ",temp->data);
         temp=temp->next;
    }
}

int main(){
    node* head=NULL;
    push(&head,20);
    push(&head,4);
    push(&head,15);
    push(&head,85);
    printf("Given Linked List\n");
    print(head);
    reverse(&head);
    printf("\nReversed Linked List\n");
    print(head);
}
