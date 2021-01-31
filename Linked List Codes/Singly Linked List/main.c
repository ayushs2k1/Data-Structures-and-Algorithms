#include <stdio.h>
#include <stdlib.h>

struct ListNode{
      int data;
      struct ListNode *next;
};

void append(struct ListNode** head, int data)
{
    /* 1. allocate node */
    struct ListNode *newNode;
    newNode=(struct ListNode*)malloc(sizeof(struct ListNode));

    struct ListNode *last = *head; /* used in step 5*/

    /* 2. put in the data */
    newNode->data = data;

    /* 3. This new node is going to be the last node, so make next of it as NULL*/
    newNode->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL){
        last = last->next;
    }

    /* 6. Change the next of last node */
    last->next = newNode;
    return;
}



/*Inserting elements in the linked list.*/

void InsertInLinkedList(struct ListNode **head,int data,int position){
      int k=1;

      /* 1. Allocate node*/
      struct ListNode *p,*q,*newNode;
      newNode=(struct ListNode*)malloc(sizeof(struct ListNode));
      if(!newNode){
          printf("Memory Error");
          return;
      }

      /* 2.Put in the data */
      newNode->data=data;
      p=*head;

      /* 3. Case when the data is inserted in the first place. */
      if(position==1){
          newNode->next=p;
          *head=newNode;
      }

      /* 4. Case when the data is inserted in the middle or in the last */
      else{
          while((p!=NULL)&&(k<position)){
                k++;
                q=p;
                p=p->next;
          }
          q->next=newNode;
          newNode->next=p;
      }
}



/* Deleting elements in a list. */

void DeleteNodeFromLinkedList(struct ListNode **head,int position){
     int k=1;

     /* 1. Allocate node*/
     struct ListNode *p,*q;
     if(*head==NULL){
          printf("\nList Empty");
          return;
     }
     p=*head;

     /* 2. If the first element is to be deleted */
     if(position==1){
          (*head)=(*head)->next;
          free(p);
          return;
     }

     /* 3. If the middle or the last element is to be deleted */
     else{
          while((p!=NULL)&&(k<position)){
               k++;
               q=p;
               p=p->next;
          }
          if(p==NULL){
               printf("\nPosition does not exist");
          }
          else{
               q->next=p->next;
               free(p);
          }
     }
}



/*Finding the length of the linked list*/

int ListLength(struct ListNode *head){
     struct ListNode *current=head;
     int count=0;
     while(current!=NULL){
           count++;
           current=current->next;
     }
     printf(" %d ",count);
}



/*To print the linked list.*/

void printList(struct ListNode *newNode)
{
    while (newNode!= NULL)
    {
        printf(" %d ", newNode->data);
        newNode = newNode->next;
    }
}

/*Main Function*/

int main(){
      struct ListNode *head=NULL;
      append(&head,4);
      append(&head,15);
      append(&head,7);
      append(&head,40);
      printf("List Created is: ");
      printList(head);
      printf("\nLength of the list created is: ");
      ListLength(head);
      InsertInLinkedList(&head,100,2);
      printf("\nThe new list after insertion: ");
      printList(head);
      printf("\nLength of the new list after insertion: ");
      ListLength(head);
      DeleteNodeFromLinkedList(&head,4);
      printf("\nNew list after deletion: ");
      printList(head);
      printf("\nLength of list after deletion: ");
      ListLength(head);
      return 0;
}
