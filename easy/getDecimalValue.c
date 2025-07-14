// Convert Binary Number in a Linked List to Integer

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


int getDecimalValue(struct ListNode* head) {
    int len = 0;
    struct ListNode* tmp = head;
    while(tmp != NULL)
    {
        len++;
        tmp = tmp->next;
    }
    int decimal = 0;
    int i = 0;
    while(i < len)
    {
        if(head->val == 1)
            decimal += pow(2, len - 1 - i);
        i++;
        head = head->next;
    }
    return decimal;
}

// Function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to free the linked list
void freeList(struct ListNode* head) {
    struct ListNode* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    // Example 1: 101 (binary) = 5 (decimal)
    struct ListNode* head1 = newNode(1);
    head1->next = newNode(0);
    head1->next->next = newNode(1);
    printf("Binary 101 -> Decimal: %d\n", getDecimalValue(head1));
    freeList(head1);

    // Example 2: 1101 (binary) = 13 (decimal)
    struct ListNode* head2 = newNode(1);
    head2->next = newNode(1);
    head2->next->next = newNode(0);
    head2->next->next->next = newNode(1);
    printf("Binary 1101 -> Decimal: %d\n", getDecimalValue(head2));
    freeList(head2);

    // Example 3: 0 (binary) = 0 (decimal)
    struct ListNode* head3 = newNode(0);
    printf("Binary 0 -> Decimal: %d\n", getDecimalValue(head3));
    freeList(head3);

    return 0;
}