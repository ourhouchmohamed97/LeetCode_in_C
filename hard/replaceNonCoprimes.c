// Replace Non-Coprime Numbers in Array


#include <stdio.h>
#include <stdlib.h>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int* replaceNonCoprimes(int* nums, int numsSize, int* returnSize) {
    long long* stack = (long long*)malloc(numsSize * sizeof(long long));
    int top = -1;
    for (int i = 0; i < numsSize; i++) {
        long long curr = nums[i];
        while (top >= 0) {
            long long g = gcd(stack[top], curr);
            if (g == 1) break;
            curr = lcm(stack[top], curr);
            top--;
        }
        stack[++top] = curr;
    }
    int* res = (int*)malloc((top + 1) * sizeof(int));
    for (int i = 0; i <= top; i++) res[i] = (int)stack[i];
    *returnSize = top + 1;
    free(stack);
    return res;
}

int main() {
    int nums[] = {6,4,3,2,7,6,2};
    int n = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* result = replaceNonCoprimes(nums, n, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}
