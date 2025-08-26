// Different Ways to Add Parentheses

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char* key;
    int* values;
    int size;
    int capacity;
} MemoEntry;

typedef struct {
    MemoEntry* entries;
    int size;
    int capacity;
} Memo;

Memo* createMemo() {
    Memo* memo = (Memo*)malloc(sizeof(Memo));
    memo->entries = NULL;
    memo->size = 0;
    memo->capacity = 0;
    return memo;
}

void freeMemo(Memo* memo) {
    for (int i = 0; i < memo->size; i++) {
        free(memo->entries[i].key);
        free(memo->entries[i].values);
    }
    free(memo->entries);
    free(memo);
}

int* findInMemo(Memo* memo, char* key) {
    for (int i = 0; i < memo->size; i++) {
        if (strcmp(memo->entries[i].key, key) == 0) {
            return memo->entries[i].values;
        }
    }
    return NULL;
}

void addToMemo(Memo* memo, char* key, int* values, int size) {
    if (memo->size >= memo->capacity) {
        memo->capacity = memo->capacity == 0 ? 1 : memo->capacity * 2;
        memo->entries = (MemoEntry*)realloc(memo->entries, memo->capacity * sizeof(MemoEntry));
    }
    MemoEntry* entry = &memo->entries[memo->size];
    entry->key = strdup(key);
    entry->values = (int*)malloc(size * sizeof(int));
    memcpy(entry->values, values, size * sizeof(int));
    entry->size = size;
    memo->size++;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*';
}

int* compute(char* expression, int start, int end, int* returnSize, Memo* memo) {
    char* subExpr = (char*)malloc((end - start + 2) * sizeof(char));
    strncpy(subExpr, expression + start, end - start + 1);
    subExpr[end - start + 1] = '\0';
    
    int* memoized = findInMemo(memo, subExpr);
    if (memoized != NULL) {
        *returnSize = memo->entries[0].size; // Actually, we need to get the size for this key
        // But we need to know the size for the specific key. So we need to store the size in the memo entry.
        // Alternatively, we can return the array and set returnSize.
        // Since we are storing the size in the MemoEntry, we can return it.
        // However, we need to find the correct entry.
        for (int i = 0; i < memo->size; i++) {
            if (strcmp(memo->entries[i].key, subExpr) == 0) {
                *returnSize = memo->entries[i].size;
                int* result = (int*)malloc(memo->entries[i].size * sizeof(int));
                memcpy(result, memo->entries[i].values, memo->entries[i].size * sizeof(int));
                free(subExpr);
                return result;
            }
        }
    }
    
    int* results = NULL;
    int count = 0;
    int isNumber = 1;
    for (int i = start; i <= end; i++) {
        if (isOperator(expression[i])) {
            isNumber = 0;
            break;
        }
    }
    if (isNumber) {
        int num = atoi(subExpr);
        results = (int*)malloc(sizeof(int));
        results[0] = num;
        count = 1;
    } else {
        for (int i = start; i <= end; i++) {
            if (isOperator(expression[i])) {
                int leftSize, rightSize;
                int* leftResults = compute(expression, start, i-1, &leftSize, memo);
                int* rightResults = compute(expression, i+1, end, &rightSize, memo);
                for (int j = 0; j < leftSize; j++) {
                    for (int k = 0; k < rightSize; k++) {
                        int val;
                        switch (expression[i]) {
                            case '+': val = leftResults[j] + rightResults[k]; break;
                            case '-': val = leftResults[j] - rightResults[k]; break;
                            case '*': val = leftResults[j] * rightResults[k]; break;
                        }
                        count++;
                        results = (int*)realloc(results, count * sizeof(int));
                        results[count-1] = val;
                    }
                }
                free(leftResults);
                free(rightResults);
            }
        }
    }
    addToMemo(memo, subExpr, results, count);
    *returnSize = count;
    free(subExpr);
    return results;
}

int* diffWaysToCompute(char* expression, int* returnSize) {
    Memo* memo = createMemo();
    int* result = compute(expression, 0, strlen(expression)-1, returnSize, memo);
    freeMemo(memo);
    return result;
}

int main() {
    char expr1[] = "2-1-1";
    int size1;
    int* res1 = diffWaysToCompute(expr1, &size1);
    printf("Example 1 Output: [");
    for (int i = 0; i < size1; i++) {
        printf("%d", res1[i]);
        if (i < size1-1) printf(",");
    }
    printf("]\n");
    free(res1);
    
    char expr2[] = "2*3-4*5";
    int size2;
    int* res2 = diffWaysToCompute(expr2, &size2);
    printf("Example 2 Output: [");
    for (int i = 0; i < size2; i++) {
        printf("%d", res2[i]);
        if (i < size2-1) printf(",");
    }
    printf("]\n");
    free(res2);
    
    return 0;
}