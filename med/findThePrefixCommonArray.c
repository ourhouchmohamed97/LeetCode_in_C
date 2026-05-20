// Find the Prefix Common Array of Two Arrays

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int *result = malloc((ASize) * sizeof(int));
    int *freq = calloc((ASize + 1), sizeof(int));
    *returnSize = ASize;
    int prefix = 0;
    for(int i = 0 ; i < ASize ; i++){
        freq[A[i]]++;
        if(freq[A[i]] == 2)
            prefix++;
        freq[B[i]]++;
        if(freq[B[i]] == 2)
            prefix++;
        result[i] = prefix;
    }
    free(freq);
    return result;
}