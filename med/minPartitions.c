// Partitioning Into Minimum Number Of Deci-Binary Numbers

int minPartitions(char * n) {
    int max = 0;
    for (int i = 0; n[i] != '\0'; i++) {
        int digit = n[i] - '0';
        if (digit > max) max = digit;
    }
    return max;
}