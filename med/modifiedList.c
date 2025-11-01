// Delete Nodes From Linked List Present in Array

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int cmp_ints(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    if (!head || numsSize == 0)
        return head;
    qsort(nums, numsSize, sizeof(int), cmp_ints);
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *prev = &dummy;
    struct ListNode *curr = head;
    while (curr) {
        if (bsearch(&curr->val, nums, numsSize, sizeof(int), cmp_ints)) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return dummy.next;
}

int main(void) {
    struct ListNode *head = malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;

    int nums[] = {1, 3, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    head = modifiedList(nums, numsSize, head);

    struct ListNode *curr = head;
    while (curr) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");

    while (head) {
        struct ListNode *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
