// Compare Version Numbers

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compareVersion(char *version1, char *version2) {
    int i = 0, j = 0;
    int n1 = strlen(version1), n2 = strlen(version2);

    while (i < n1 || j < n2) {
        int num1 = 0;
        while (i < n1 && version1[i] != '.') {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }

        int num2 = 0;
        while (j < n2 && version2[j] != '.') {
            num2 = num2 * 10 + (version2[j] - '0');
            j++;
        }

        if (num1 < num2) return -1;
        if (num1 > num2) return 1;

        i++;
        j++;
    }

    return 0;
}

int main() {
    printf("%d\n", compareVersion("1.2", "1.10"));     // -1
    printf("%d\n", compareVersion("1.01", "1.001"));   // 0
    printf("%d\n", compareVersion("1.0", "1.0.0.0"));  // 0
    return 0;
}
