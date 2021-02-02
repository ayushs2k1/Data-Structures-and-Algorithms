/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* current=head;

    int n=0;

    while(current!=NULL){
        n++;
        current=current->next;
    }

    current=head;
    for(int i=0;i<n/2;i++){
        current=current->next;
    }
    return current;
}
