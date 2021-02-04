/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    if(head==NULL){
        return true;
    }

    struct ListNode* current=head;
    int n=0;
    while(current!=NULL){
        n++;
        current=current->next;
    }
    current=head;
    int arr1[n];
    int i=0;
    while(current!=NULL){
        arr1[i]=current->val;
        current=current->next;
        i++;
    }
    i=0;
    int j=n-1;
    int arr2[n];
    while(i<n){
        arr2[i]=arr1[j];
        i++;
        j--;
    }
    i=0;
    while(i<n){
        if(arr1[i]!=arr2[i]){
            return false;
        }
        i++;
    }
    return true;
}
