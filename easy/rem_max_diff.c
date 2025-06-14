// Maximum Difference by Remapping a Digit

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int remap(char* numStr, char from, char to) {
    char newNumStr[20];
    strcpy(newNumStr, numStr);
    for (int i = 0; newNumStr[i]; i++) {
        if (newNumStr[i] == from)
            newNumStr[i] = to;
    }
    return (atoi(newNumStr));
}

int minMaxDifference(int num) {
    char numStr[20];
    sprintf(numStr, "%d", num);

    int maxVal = num, minVal = num;

    for (char from = '0'; from <= '9'; from++) {
        for (char to = '0'; to <= '9'; to++) {
            int remapped = remap(numStr, from, to);
            if (remapped > maxVal) maxVal = remapped;
            if (remapped < minVal) minVal = remapped;
        }
    }

    return maxVal - minVal;
}


int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    int result = minMaxDifference(num);
    printf("The maximum difference after remapping digits is: %d\n", result);
    
    return 0;
}
