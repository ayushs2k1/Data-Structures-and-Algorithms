#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void removeduplicates(struct node* head){
    //Pointer to traverse the Linked List
    struct node* current=head;
    //Pointer to store the next pointer of a node to be deleted
    struct node* next_next;
    //Do nothing if the list is empty
    if(current==NULL){
        return;
    }
    while(current->next!=NULL){
        if(current->data==current->next->data){
             next_next=current->next->next;
             free(current->next);
             current->next=next_next;
        }
        else{
             current=current->next;
        }
    }
}

void push(struct node** head, int data){
     struct node* newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=data;
     newnode->next=*head;
     *head=newnode;
}

void print(struct node* temp){
     while (temp!=NULL){
         printf("%d ",temp->data);
         temp=temp->next;
     }
}

int main(){
     struct node* head=NULL;
     push(&head, 20);
     push(&head, 13);
     push(&head, 13);
     push(&head, 11);
     push(&head, 11);
     push(&head, 11);
     printf("\n Linked List before duplicate removal: ");
     print(head);
     removeduplicates(head);
     printf("\n Linked List after duplicate removal: ");
     print(head);
     return 0;
}
