// Rotate Function

int maxRotateFunction(int* nums, int n) {
    int sum = nums[0], f = 0;
    for (int i = 1; i < n; i++) {
        f += i * nums[i];
        sum += nums[i];
    }
    int ret = f;
    for (int i = 1; i < n; i++) {
        f += n * nums[i - 1] - sum;
        ret = f > ret ? f : ret;
    }
    return ret;
}