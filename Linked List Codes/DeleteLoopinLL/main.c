#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

int removeloop(struct node* loop_node,struct node* head){
    //Loop node is pointer to one of the loop nodes
    struct node* ptr1=loop_node;
    struct node* ptr2=loop_node;
    //Count the number of nodes in the loop
    unsigned int k=1,i;
    while(ptr1->next!=ptr2){
        ptr1=ptr1->next;
        k++;
    }
    //Fix one pointer to head
    ptr1=head;
    //And the other pointer to k nodes after the head node
    ptr2=head;
    for(i=0;i<k;i++){
        ptr2=ptr2->next;
    }
    //Move both pointers at the same pace, they'll meet at the loop starting node
    while(ptr2!=ptr1){
       ptr1=ptr1->next;
       ptr2=ptr2->next;
    }
    printf("\nStarting Node of the Loop is: %d",ptr1->data);
    //Get pointer to last node
    while(ptr2->next!=ptr1){
       ptr2=ptr2->next;
    }
    // Setting the last node pointer to NULL to break the loop
    ptr2->next=NULL;
}

int detectandremoveloop(struct node* head){
    struct node* slowptr=head;
    struct node* fastptr=head;
    while(slowptr && fastptr && fastptr->next){
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
        // If slow_p and fast_p meet at some point then there is a loop
        if(slowptr==fastptr){
            removeloop(slowptr,head);
            //Return 1 to indicate that loop is found
            return 1;
        }
    }
    //Return 0 to indicate that there is no loop
    return 0;
}

void print(struct node* temp){
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

struct node* push(int data)
{
    struct node* newnode
        = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

int main(){
    struct node* head=push(50);
    head->next=push(20);
    head->next->next=push(15);
    head->next->next->next=push(4);
    head->next->next->next->next=push(10);
    //Create a loop for testing
    head->next->next->next->next->next=head->next->next;
    detectandremoveloop(head);
    printf("\nLinked List after removing the loop: \n");
    print(head);
    return 0;
}
