// Minimum One Bit Operations to Make Integers Zero

int minimumOneBitOperations(int n) {
    if(n == 0) return 0;
    return n ^ minimumOneBitOperations(n >> 1);
}
