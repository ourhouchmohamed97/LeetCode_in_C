// Delete the Middle Node of a Linked List

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteMiddle(struct ListNode* head){
    if (!head->next) return NULL;
    struct ListNode *slow=head, *fast=head->next;
    while(fast->next && fast->next->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return head; 

}