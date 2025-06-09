#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode head;
    struct ListNode* tail = &head;
    head.next = NULL;
    int carry = 0;

    while (l1 || l2 || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        tail->next = createNode(sum % 10);
        tail = tail->next;
    }

    return head.next;
}

void printList(struct ListNode* head) {
    while (head) {
        printf("%d", head->val);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct ListNode* l1 = createNode(3);
    l1->next = createNode(5);
    l1->next->next = createNode(4);

    struct ListNode* l2 = createNode(3);
    l2->next = createNode(2);
    l2->next->next = createNode(1);

    struct ListNode* sum = addTwoNumbers(l1, l2);
    printList(sum);

    return 0;
}
