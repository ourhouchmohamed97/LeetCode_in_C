// Minimum Distance Between Three Equal Elements I

int minimumDistance(int* nums, int numsSize) {
    int max_val = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max_val) 
            max_val = nums[i];
    }

    int (*pos)[2] = malloc((max_val + 1) * sizeof(int[2]));
    for (int i = 0; i <= max_val; i++) {
        pos[i][0] = -1;
        pos[i][1] = -1;
    }

    long long res = 1LL << 32;

    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        int last = pos[val][0];
        int second_last = pos[val][1];

        if (second_last != -1) {
            int distance = (i - second_last) * 2;
            if (distance < res) 
                res = distance;
        }

        pos[val][1] = last;
        pos[val][0] = i;
    }

    free(pos);
    return (res == (1LL << 32)) ? -1 : (int)res;
}