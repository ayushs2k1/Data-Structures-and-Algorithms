#include <iostream>

using namespace std;

struct Node{
   int data;
   struct Node* next;
};

void segregateEvenOdd(struct Node **head){
   Node *current=*head;

   //Starting Node of the Linked List having even values
   Node *evenStart=NULL;
   //Ending Node of the Linked List having even values
   Node *evenEnd=NULL;

   //Starting Node of the Linked List having odd values
   Node *oddStart=NULL;
   //Ending Node of the Linked List having odd values
   Node *oddEnd=NULL;

   while(current!=NULL){
      int val=current->data;

      if(val%2==0){
         if(evenStart==NULL){
            evenStart=current;
            evenEnd=evenStart;
         }
         else{
            evenEnd->next=current;
            evenEnd=evenEnd->next;
         }
      }
      else{
         if(oddStart==NULL){
            oddStart=current;
            oddEnd=oddStart;
         }
         else{
            oddEnd->next=current;
            oddEnd=oddEnd->next;
         }
      }
      current=current->next;
   }

   if(oddStart==NULL || evenStart==NULL){
      return;
   }

   evenEnd->next=oddStart;
   oddEnd->next=NULL;

   *head=evenStart;
}

void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

void printList(struct Node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;

    /* Let us create a sample linked list as following
    0->1->4->6->9->10->11 */

    push(&head, 11);
    push(&head, 10);
    push(&head, 9);
    push(&head, 6);
    push(&head, 4);
    push(&head, 1);
    push(&head, 0);

    printf("\nOriginal Linked list \n");
    printList(head);

    segregateEvenOdd(&head);

    printf("\nModified Linked list \n");
    printList(head);

    return 0;
}
