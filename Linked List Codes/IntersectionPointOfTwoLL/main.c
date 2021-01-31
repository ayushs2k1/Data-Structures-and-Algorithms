/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* ptr1=headA;
    struct ListNode* ptr2=headB;
    
    int n1=0,n2=0,diff=0,i;
    while(ptr1!=NULL){
        n1++;
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        n2++;
        ptr2=ptr2->next;
    }
    
    ptr1=headA;
    ptr2=headB;
    
    if(n1>n2){
        diff=n1-n2;
        for(i=0;i<diff;i++){
            ptr1=ptr1->next;
        }
    }
    else if(n1<n2){
        diff=n2-n1;
        for(i=0;i<diff;i++){
            ptr2=ptr2->next;
        }
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1 == ptr2){
            return ptr1;
        }
        else{
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }
    return NULL;
}
