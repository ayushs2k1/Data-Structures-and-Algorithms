#include<stdio.h>
#include<stdlib.h>

struct Node{
   int data;
   struct Node* next;
};

void delnodes(struct Node* head){
   struct Node* current=head;
   struct Node* temp;

   while(current!=NULL && current->next!=NULL){
      if(current->data<current->next->data){
         current->data=current->next->data;
         current->next=current->next->next;
      }
      else{
         current=current->next;
      }
   }
}

void push(struct Node** head, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void printList(struct Node* head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct Node* head = NULL;

    /* Create following linked list
      12->15->10->11->5->6->2->3 */
    push(&head, 3);
    push(&head, 2);
    push(&head, 6);
    push(&head, 5);
    push(&head, 11);
    push(&head, 10);
    push(&head, 15);
    push(&head, 12);

    printf("Given Linked List \n");
    printList(head);

    delnodes(head);

    printf("Modified Linked List \n");
    printList(head);

    return 0;
}
