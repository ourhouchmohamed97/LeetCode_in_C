// Separate the Digits in an Array

int digit_number(int n) {
    int result = 0;
    while (n != 0) {
        result++;
        n /= 10;
    }
    return result;
}

int total_digit_number(int* nums, int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += digit_number(nums[i]);
    }
    return result;
}

int* separateDigits(int* nums, int nums_size, int* return_size) {
    *return_size = total_digit_number(nums, nums_size);
    int* ans = (int*) malloc(*return_size * sizeof(int));

    for (int i = *return_size - 1, j = nums_size - 1; i >= 0; i--) {
        ans[i] = nums[j] % 10;
        nums[j] /= 10;
        if (nums[j] == 0) {
            j--;
        }
    }

    return ans;
}