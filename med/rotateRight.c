// Rotate List

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Rotates the linked list to the right by k places.
 * 
 * @param head The head of the linked list.
 * @param k The number of places to rotate.
 * @return The new head of the rotated list.
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    int length = 1;
    struct ListNode* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }

    k %= length;
    
    if (k == 0) {
        return head;
    }

    tail->next = head;

    int steps_to_new_tail = length - k;
    while (steps_to_new_tail--) {
        tail = tail->next;
    }

    struct ListNode* new_head = tail->next;
    tail->next = NULL;

    return new_head;
}