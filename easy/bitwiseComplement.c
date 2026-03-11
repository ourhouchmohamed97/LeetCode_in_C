// Complement of Base 10 Integer

int bitwiseComplement(int n) {
    if (n == 0)
        return 1;

    int mask = 0;
    int x = n;
    while(x) {
        mask = (mask << 1) | 1;
        x >>= 1;
    }
    return mask ^ n;
}