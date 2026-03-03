// Find Kth Bit in Nth Binary String

char findKthBit(int n, int k) {
    if (n == 1) 
        return '0';

    int mid = 1 << (n - 1);
    if (mid == k) 
        return '1';
    if (mid > k) 
        return findKthBit(n - 1, k);

    int mirror = (1 << n) - k;
    char bit = findKthBit(n - 1, mirror);
    return (bit == '0') ? '1' : '0';
}