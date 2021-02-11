#include <iostream>

using namespace std;

struct Node{
   int data;
   struct Node *next, *prev;
};

void rotateDLL(struct Node** head, int N){
   if(N==0){
      return;
   }

   struct Node* current=*head;

   int c=1;

   while(c<N && current->next!=NULL){
      current=current->next;
      c++;
   }

   if(current==NULL){
      return;
   }

   struct Node* NthNode=current;

   while(current->next!=NULL){
      current=current->next;
   }

   current->next=*head;

   (*head)->prev=current;

   *head=NthNode->next;

   (*head)->prev=NULL;

   NthNode->next=NULL;
}

 void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node =  new Node;
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
   *head_ref = new_node;
}

/* Function to print linked list */
void printList(struct Node* node)
{
    while (node->next != NULL) {
        cout << node->data << " "
             << "<=>"
             << " ";
        node = node->next;
    }
    cout << node->data;
}

// Driver's Code
int main(void)
{
    /* Start with the empty list */
    struct Node* head = NULL;

    /* Let us create the doubly
      linked list a<->b<->c<->d<->e */
    push(&head, 'e');
    push(&head, 'd');
    push(&head, 'c');
    push(&head, 'b');
    push(&head, 'a');

    int N = 2;

    cout << "Given linked list \n";
    printList(head);
    rotateDLL(&head, N);

    cout << "\nRotated Linked list \n";
    printList(head);

    return 0;
}
