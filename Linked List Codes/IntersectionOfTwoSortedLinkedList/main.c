#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node* next;
};

void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

struct node* sortedintersect(struct node* a,struct node* b){
   /*The idea is to use a temporary dummy node at the start of the result list.
   The pointer always points to the last node in the result list,so new nodes
   can be added easily. The dummy node gives tail a memory space to point to.
   This dummy node is efficient since it is only temporary,and it is allocated in the stack.
   The loop proceeds removing one node either from 'a' or 'b' and adding it to tail.
   When the given lists are traversed,the result is in dummy.next as the values are
   allocated from next node of the dummy. If both the elements are equal then remove both
   and insert the element to the tail. Else remove the smaller element among both the lists.  */
   struct node dummy;
   struct node* tail=&dummy;
   dummy.next=NULL;
   while(a!=NULL && b!=NULL){
       if(a->data==b->data){
          push((&tail->next),a->data);
          tail=tail->next;
          a=a->next;
          b=b->next;
       }
       else if(a->data < b->data){
          a=a->next;
       }
       else{
          b=b->next;
       }
   }
   return dummy.next;
}

void printList(struct node* temp)
{
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    /* Start with the empty lists */
    struct node* a = NULL;
    struct node* b = NULL;
    struct node* intersect = NULL;

    /* Let us create the first sorted
     linked list to test the functions
     Created linked list will be
     1->2->3->4->5->6 */
    push(&a, 6);
    push(&a, 5);
    push(&a, 4);
    push(&a, 3);
    push(&a, 2);
    push(&a, 1);

    /* Let us create the second sorted linked list
   Created linked list will be 2->4->6->8 */
    push(&b, 8);
    push(&b, 6);
    push(&b, 4);
    push(&b, 2);

    /* Find the intersection two linked lists */
    intersect = sortedintersect(a, b);

    printf("\n Linked list containing common items of a & b \n ");
    printList(intersect);

    getchar();
}
