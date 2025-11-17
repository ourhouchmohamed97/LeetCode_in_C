// Check If All 1's Are at Least Length K Places Away

#include <stdbool.h>

bool kLengthApart(int* nums, int numsSize, int k) {
    int index = 0, occur = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {

            if (occur > 0) {
                if (i - index - 1 >= k)
                    index = i;

                else
                    return false;
            }
            index = i;
            occur++;
        }
    }

    return true;
}