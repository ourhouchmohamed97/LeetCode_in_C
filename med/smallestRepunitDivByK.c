// Smallest Integer Divisible by K

int smallestRepunitDivByK(int k) {
    int rem = 0;
    for (int length = 1; length <= k; ++length) {
        rem = (rem * 10 + 1) % k;
        if (rem == 0)
            return length;
    }
    return -1;
}
