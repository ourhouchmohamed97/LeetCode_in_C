// Minimum Changes To Make Alternating Binary String

int minOperations(char* s) {
    int op = 0;
    int i;
    for (i = 0; s[i] != '\0'; i++)
        op += (s[i] - '0') == (i & 1);
    return fmin(op, i-op);
}