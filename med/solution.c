// Linked List Random Node

#include <stdlib.h>
#include <time.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct {
    struct ListNode* head;
} Solution;

Solution* solutionCreate(struct ListNode* head) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->head = head;
    srand(time(NULL)); 
    return obj;
}

int solutionGetRandom(Solution* obj) {
    struct ListNode* curr = obj->head;
    int result = curr->val;
    int count = 1;

    while (curr) {
        if ((rand() % count) == 0) 
            result = curr->val;
        curr = curr->next;
        count++;
    }

    return result;
}

void solutionFree(Solution* obj) {
    free(obj);
}

int main() {
    struct ListNode n3 = {3, NULL};
    struct ListNode n2 = {2, &n3};
    struct ListNode n1 = {1, &n2};

    Solution* obj = solutionCreate(&n1);

    for (int i = 0; i < 10; i++)
        printf("%d ", solutionGetRandom(obj));

    printf("\n");
    solutionFree(obj);
    return 0;
}
