// Remove Sub-Folders from the Filesystem

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

char** removeSubfolders(char** folder, int folderSize, int* returnSize) {
    qsort(folder, folderSize, sizeof(char*), compareStrings);
    
    char** result = (char**)malloc(folderSize * sizeof(char*));
    *returnSize = 0;
    
    if (folderSize == 0) {
        return result;
    }
    
    result[(*returnSize)++] = folder[0];
    
    for (int i = 1; i < folderSize; i++) {
        char* lastFolder = result[*returnSize - 1];
        char* currentFolder = folder[i];
        
        int lastLen = strlen(lastFolder);
        int currentLen = strlen(currentFolder);
        
        if (currentLen > lastLen && 
            strncmp(currentFolder, lastFolder, lastLen) == 0 && 
            currentFolder[lastLen] == '/') {
            continue;
        } else {
            result[(*returnSize)++] = currentFolder;
        }
    }
    
    return result;
}

int main() {
    char* folder1[] = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
    int folderSize1 = 5;
    int returnSize1;
    char** result1 = removeSubfolders(folder1, folderSize1, &returnSize1);
    
    printf("Example 1 Output:\n");
    for (int i = 0; i < returnSize1; i++) {
        printf("%s\n", result1[i]);
    }
    free(result1);
    
    char* folder2[] = {"/a", "/a/b/c", "/a/b/d"};
    int folderSize2 = 3;
    int returnSize2;
    char** result2 = removeSubfolders(folder2, folderSize2, &returnSize2);
    
    printf("\nExample 2 Output:\n");
    for (int i = 0; i < returnSize2; i++) {
        printf("%s\n", result2[i]);
    }
    free(result2);

    char* folder3[] = {"/a/b/c", "/a/b/ca", "/a/b/d"};
    int folderSize3 = 3;
    int returnSize3;
    char** result3 = removeSubfolders(folder3, folderSize3, &returnSize3);
    
    printf("\nExample 3 Output:\n");
    for (int i = 0; i < returnSize3; i++) {
        printf("%s\n", result3[i]);
    }
    free(result3);
    
    return 0;
}