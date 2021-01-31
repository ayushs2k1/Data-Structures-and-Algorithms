#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *reverse(struct node *head,int k){
    struct node* prev=NULL;
    struct node* current=head;
    struct node* next=NULL;
    int count=0;
    //reverse first K nodes in the linked list
    while(current!=NULL && count<k){
         next=current->next;
         current->next=prev;
         prev=current;
         current=next;
         count++;
    }
    /*next is now a pointer to (k+1)th node.
      Recursively call for the list starting from current
      and make rest of the list as next of first node*/
    if(next!=NULL){
         head->next=reverse(next,k);
    }
    //prev is new head of the input list
    return prev;
}

void push(struct node** head,int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
}

void print(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
         printf("%d ",temp->data);
         temp=temp->next;
    }
}

int main(void){
    struct node* head=NULL;
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("\nGiven Linked List is: \n");
    print(head);
    head=reverse(head,3);
    printf("\nReversed Linked List is: \n");
    print(head);
    return 0;
}
