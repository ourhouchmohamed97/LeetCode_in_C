// Minimum Number of People to Teach

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Hashset-like check using array
bool shareLanguage(int* langsU, int sizeU, int* langsV, int sizeV) {
    for (int i = 0; i < sizeU; i++) {
        for (int j = 0; j < sizeV; j++) {
            if (langsU[i] == langsV[j]) return true;
        }
    }
    return false;
}

int minimumTeachings(int n, int** languages, int languagesSize, int* languagesColSize,
                     int** friendships, int friendshipsSize, int* friendshipsColSize) {
    // Step 1: Find users involved in friendships that cannot communicate
    int* needFix = (int*)calloc(languagesSize + 1, sizeof(int)); // 1-indexed
    int needCount = 0;

    for (int i = 0; i < friendshipsSize; i++) {
        int u = friendships[i][0] - 1; // convert to 0-index
        int v = friendships[i][1] - 1;

        if (!shareLanguage(languages[u], languagesColSize[u],
                           languages[v], languagesColSize[v])) {
            if (!needFix[u + 1]) {
                needFix[u + 1] = 1;
                needCount++;
            }
            if (!needFix[v + 1]) {
                needFix[v + 1] = 1;
                needCount++;
            }
        }
    }

    if (needCount == 0) { // all friendships already good
        free(needFix);
        return 0;
    }

    // Step 2: For each language, count how many "needFix" users already know it
    int minTeach = languagesSize; // worst case
    for (int lang = 1; lang <= n; lang++) {
        int knowCount = 0;
        for (int u = 0; u < languagesSize; u++) {
            if (needFix[u + 1]) {
                for (int j = 0; j < languagesColSize[u]; j++) {
                    if (languages[u][j] == lang) {
                        knowCount++;
                        break;
                    }
                }
            }
        }
        int toTeach = needCount - knowCount;
        if (toTeach < minTeach) minTeach = toTeach;
    }

    free(needFix);
    return minTeach;
}


int main() {
    // Example 1
    int n1 = 2;
    int langsColSize1[] = {1,1,2};
    int l1a[] = {1};
    int l1b[] = {2};
    int l1c[] = {1,2};
    int* languages1[] = {l1a,l1b,l1c};
    int f1a[] = {1,2};
    int f1b[] = {1,3};
    int f1c[] = {2,3};
    int* friendships1[] = {f1a,f1b,f1c};
    int fColSize1[] = {2,2,2};

    printf("Example 1 Output: %d\n",
        minimumTeachings(n1, languages1, 3, langsColSize1,
                         friendships1, 3, fColSize1));

    // Example 2
    int n2 = 3;
    int langsColSize2[] = {1,2,2,1};
    int l2a[] = {2};
    int l2b[] = {1,3};
    int l2c[] = {1,2};
    int l2d[] = {3};
    int* languages2[] = {l2a,l2b,l2c,l2d};
    int f2a[] = {1,4};
    int f2b[] = {1,2};
    int f2c[] = {3,4};
    int f2d[] = {2,3};
    int* friendships2[] = {f2a,f2b,f2c,f2d};
    int fColSize2[] = {2,2,2,2};

    printf("Example 2 Output: %d\n",
        minimumTeachings(n2, languages2, 4, langsColSize2,
                         friendships2, 4, fColSize2));

    return 0;
}