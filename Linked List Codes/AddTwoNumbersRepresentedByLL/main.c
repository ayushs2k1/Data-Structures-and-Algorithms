#include<stdio.h>
#include<stdlib.h>

struct node{
   int data;
   struct node* next;
};

struct node* newnode(int data){
   struct node* new_node=(struct node*)malloc(sizeof(struct node));
   new_node->data=data;
   new_node->next=NULL;
   return new_node;
}

void push(struct node** head,int data){
   struct node* new_node=newnode(data);
   new_node->next=*head;
   *head=new_node;
}

struct node* addtwolist(struct node* first,struct node* second){
   //res is head node of the resultant list
   struct node* res=NULL;
   struct node *temp,*prev=NULL;
   int carry=0,sum;
   //while both list exists
   while(first!=NULL || second!=NULL){
        /*Calculate the value of next digit in resultant list.
        The next digit is sum of carry,next digit of first and next digit of second linked list*/
        sum=carry+(first ? first->data:0)+(second ? second->data:0);
        //Update carry for next calculation
        carry=(sum>=10)? 1:0;
        //update sum if it is greater than 10
        sum=sum%10;
        //Create a new node with sum as data
        temp=newnode(sum);
        //If this is the first node then set it as head of the resultant list
        if(res==NULL){
            res=temp;
        }
        //If this is not the first node then connect it to the rest.
        else{
            prev->next=temp;
        }
        //set prev for next insertion
        prev=temp;
        //move first and second pointers to next nodes
        if(first){
            first=first->next;
        }
        if(second){
            second=second->next;
        }
   }
   if(carry>0){
       temp->next=newnode(carry);
   }
   //return head of the resultant list
   return res;
}

void print(struct node* temp)
{
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(void)
{
    struct node* res = NULL;
    struct node* first = NULL;
    struct node* second = NULL;

    // create first list 7->5->9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    printf("First List is ");
    print(first);

    // create second list 8->4
    push(&second, 4);
    push(&second, 8);
    printf("Second List is ");
    print(second);

    // Add the two lists and see result
    res = addtwolist(first, second);
    printf("Resultant list is ");
    print(res);

    return 0;
}
