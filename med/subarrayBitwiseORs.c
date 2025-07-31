// Bitwise ORs of Subarrays

#include <stdlib.h>
#include <stdio.h>
#include <uthash.h>

typedef struct {
    int key;
    UT_hash_handle hh;
} HashItem;

void freeHash(HashItem** set) {
    HashItem *curr, *tmp;
    HASH_ITER(hh, *set, curr, tmp) {
        HASH_DEL(*set, curr);
        free(curr);
    }
}

int subarrayBitwiseORs(int* arr, int arrSize) {
    HashItem *res = NULL, *prev = NULL;
    
    for (int i = 0; i < arrSize; ++i) {
        HashItem *curr = NULL;
        int val = arr[i];
        
        // Create a new entry for the current element itself
        HashItem *entry = (HashItem*)malloc(sizeof(HashItem));
        entry->key = val;
        HASH_ADD_INT(curr, key, entry);
        
        // Iterate through all entries in the previous set and OR with current value
        HashItem *item;
        if (prev != NULL) {
            for (item = prev; item != NULL; item = (HashItem*)(item->hh.next)) {
                int new_val = item->key | val;
                HashItem *found = NULL;
                HASH_FIND_INT(curr, &new_val, found);
                if (!found) {
                    entry = (HashItem*)malloc(sizeof(HashItem));
                    entry->key = new_val;
                    HASH_ADD_INT(curr, key, entry);
                }
            }
        }
        
        // Add all current values to the result set
        for (item = curr; item != NULL; item = (HashItem*)(item->hh.next)) {
            int key = item->key;
            HashItem *found = NULL;
            HASH_FIND_INT(res, &key, found);
            if (!found) {
                entry = (HashItem*)malloc(sizeof(HashItem));
                entry->key = key;
                HASH_ADD_INT(res, key, entry);
            }
        }
        
        // Update prev to curr for the next iteration
        freeHash(&prev);
        prev = curr;
    }
    
    int count = HASH_COUNT(res);
    freeHash(&res);
    freeHash(&prev);
    return count;
}

void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]");
}

void testCase(int* arr, int size, int expected) {
    printf("Input: ");
    printArray(arr, size);
    printf("\n");
    
    int result = subarrayBitwiseORs(arr, size);
    printf("Output: %d\n", result);
    printf("Expected: %d\n", expected);
    printf(result == expected ? "PASS\n" : "FAIL\n");
    printf("\n");
}

int main() {
    // Test Case 1: Single element
    int arr1[] = {0};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    testCase(arr1, size1, 1);
    
    // Test Case 2: Repeated elements and a different element
    int arr2[] = {1, 1, 2};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    testCase(arr2, size2, 3);
    
    // Test Case 3: Distinct elements
    int arr3[] = {1, 2, 4};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    testCase(arr3, size3, 6);
    
    // Test Case 4: All elements are the same
    int arr4[] = {2, 2, 2};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    testCase(arr4, size4, 2);
    
    // Test Case 5: Larger array with varied elements
    int arr5[] = {1, 3, 5, 7};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    testCase(arr5, size5, 8);
    
    // Test Case 6: Edge case with maximum values
    int arr6[] = {2147483647, 2147483647, 2147483647};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    testCase(arr6, size6, 1);
    
    return 0;
}