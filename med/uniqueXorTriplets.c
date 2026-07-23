// Number of Unique XOR Triplets I

int uniqueXorTriplets(int* nums, int numsSize) {
    int n = numsSize;

    if (n < 3) {
        return n;
    }

    int bits = 0;
    int x = n;

    while (x > 0) {
        bits++;
        x >>= 1;
    }

    return 1 << bits;
}