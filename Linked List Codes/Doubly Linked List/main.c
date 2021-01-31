// A complete working C program to demonstrate all insertion methods
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct dllNode {
	int data;
	struct dllNode* next;
	struct dllNode* prev;
};

/* Given a reference (pointer to pointer) to the head
of a DLL and an int, appends a new node at the end */
void append(struct dllNode** head, int data)
{
	/* 1. allocate node */
	struct  dllNode* newnode = (struct dllNode*)malloc(sizeof(struct dllNode));

	struct dllNode* last = *head; /* used in step 5*/

	/* 2. put in the data */
	newnode->data = data;

	/* 3. This new node is going to be the last node, so
		make next of it as NULL*/
	newnode->next = NULL;

	/* 4. If the Linked List is empty, then make the new
		node as head */
	if (*head == NULL) {
		newnode->prev = NULL;
		*head = newnode;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = newnode;

	/* 7. Make last node as previous of new node */
	newnode->prev = last;

	return;
}

void dllinsert(struct dllNode** head,int data,int position){
    int k=1;
    struct dllNode *temp,*newnode;
    newnode=(struct dllNode*)malloc(sizeof(struct dllNode));
        if(!newnode){
            printf("Memory error");
            return;
        }
        newnode->data=data;
        if(position==1){
            newnode->next=*head;
            newnode->prev=NULL;
            if(*head){
                (*head)->prev=newnode;
            }
        (*head)=newnode;
        return;
    }
    temp=*head;
    while((temp->next!=NULL)&&(k<position-1)){
        temp=temp->next;
        k++;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    if(temp->next){
        temp->next->prev=newnode;
    }
    temp->next=newnode;
    return;
}

void dlldelete(struct dllNode** head, int n)
{
    /* if list in NULL or invalid position is given */
    if (*head == NULL || n <= 0)
        return;

    struct dllNode* current = *head;

    /* traverse up to the node at position 'n' from
       the beginning */
    for (int i = 1; current != NULL && i < n; i++)
        current = current->next;

    /* if 'n' is greater than the number of nodes
       in the doubly linked list */
    if (current == NULL)
        return;

    /* delete the node pointed to by 'current' */
    dlldelete(head,current);
}


void printList(struct dllNode* newnode)
{
	struct dllNode* last;
	printf("\nTraversal in forward direction \n");
	while (newnode != NULL) {
		printf(" %d ", newnode->data);
		last = newnode;
		newnode = newnode->next;
	}

	printf("\nTraversal in reverse direction \n");
	while (last != NULL) {
		printf(" %d ", last->data);
		last = last->prev;
	}
}

void dlllength(struct dllNode* head) {
   int count = 0;
   struct dllNode *current;

   if(head==NULL) {
      printf("\n Size of list is %d\n", count);
      return;
   }

   current = head;
   while(current != NULL) {
      current = current->next;
      count++;
   }

   printf("\n Size of list is %d\n", count);
}

int main()
{
	struct dllNode* head = NULL;
	append(&head, 6);
	append(&head, 4);
	printf("\nCreated DLL is: ");
	printList(head);
	printf("\nSize: ");
	dlllength(head);
    dllinsert(&head,100,3);
    dllinsert(&head,70,6);
    printf("\nNew List created after insertion is: ");
    printList(head);
    printf("\nSize: ");
	dlllength(head);
    dlldelete(&head,4);
    printf("\nNew List created after deletion is: ");
    printList(head);
    printf("\nSize: ");
	dlllength(head);
	return 0;
}
