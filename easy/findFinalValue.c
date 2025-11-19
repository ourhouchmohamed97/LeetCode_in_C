// Keep Multiplying Found Values by Two

int findFinalValue(int* nums, int numsSize, int original) {
    for(int i = 0;i < numsSize && original <= 1000;i++)
    {
        if(nums[i] ==  original)
        {
            original *= 2;
            i = -1;
        }
    }
    return original;
}