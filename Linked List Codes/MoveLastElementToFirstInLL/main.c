#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node* next;
};

//We are using a double pointer head here because we changehead of the linked list inside this function
void movetofront(struct node** head){
    if(*head==NULL || (*head)->next==NULL){
        return;
    }
    struct node* secLast=NULL;
    struct node* last=*head;
    while(last->next!=NULL){
        secLast=last;
        last=last->next;
    }
    secLast->next=NULL;
    last->next=*head;
    *head=last;
}

void push(struct node** head, int data)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data  = data;
    newnode->next = *head;
    *head= newnode;
}

void print(struct node *temp)
{
    while(temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct node *head = NULL;

    /* The constructed linked list is:
     1->2->3->4->5 */
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("\n Linked list before moving last to front\n");
    print(head);

    movetofront(&head);

    printf("\n Linked list after removing last to front\n");
    print(head);
    return 0;
}
