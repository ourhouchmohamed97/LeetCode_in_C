// Average Value of Even Numbers That Are Divisible by Three

#include <stdio.h>

int averageValue(int* nums, int numsSize) {
    int e = 0;
    int div = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] % 2 == 0 && nums[i] % 3 == 0) {
            e += nums[i];
            div++;
        }
    }
    if(div == 0)
        return 0;
    return e / div;
}

int main() {
    int nums[] = {1, 3, 6, 12, 18, 7};
    int size = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", averageValue(nums, size));
    return 0;
}