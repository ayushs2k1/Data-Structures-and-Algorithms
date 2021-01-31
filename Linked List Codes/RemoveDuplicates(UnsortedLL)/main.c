#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void removeduplicates(struct node* head){
    struct node *ptr1,*ptr2,*dup;
    ptr1=head;
    //Pick elements one by one
    while(ptr1!=NULL && ptr1->next!=NULL){
        ptr2=ptr1;
        //Compare the picked elements with rest of the elements
        while(ptr2->next!=NULL){
            //if duplicate exists then delete it
            if(ptr1->data==ptr2->next->data){
                 dup=ptr2->next;
                 ptr2->next=ptr2->next->next;
                 free(dup);
            }
            else{
                 ptr2=ptr2->next;
            }
        }
        ptr1=ptr1->next;
    }
}

void print(struct node *temp)
{
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void push(struct node** head,int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
}

int main()
{
    //The constructed linked list is:10->12->11->11->12->11->10
    struct node *head = NULL;
    push(&head,10);
    push(&head,12);
    push(&head,11);
    push(&head,11);
    push(&head,12);
    push(&head,11);
    push(&head,10);

    printf("Linked list before removing duplicates ");
    print(head);

    removeduplicates(head);

    printf("\nLinked list after removing duplicates ");
    print(head);

    return 0;
}
