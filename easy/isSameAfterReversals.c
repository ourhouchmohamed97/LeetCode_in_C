// A Number After a Double Reversal

#include <stdio.h>
#include <stdbool.h>

bool isSameAfterReversals(int num) {
    if (num == 0) return true;
    return num % 10 != 0;
}

int main() {
    int nums[] = {526, 1800, 0};
    int size = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < size; i++) {
        int num = nums[i];
        bool result = isSameAfterReversals(num);
        printf("num = %d -> %s\n", num, result ? "true" : "false");
    }

    return 0;
}
