// Max Difference You Can Get From Changing an Integer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxDiff(int num) {
    char str[12];
    sprintf(str, "%d", num);

    char max_str[12];
    strcpy(max_str, str);
    char x_for_max = '\0';
    for (int i = 0; max_str[i] != '\0'; i++) {
        if (max_str[i] != '9') {
            x_for_max = max_str[i];
            break;
        }
    }
    if (x_for_max != '\0') {
        for (int i = 0; max_str[i] != '\0'; i++) {
            if (max_str[i] == x_for_max) {
                max_str[i] = '9';
            }
        }
    }
    int max_num = atoi(max_str);

    char min_str[12];
    strcpy(min_str, str);
    char x_for_min = '\0';
    if (min_str[0] != '1') {
        x_for_min = min_str[0];
        for (int i = 0; min_str[i] != '\0'; i++) {
            if (min_str[i] == x_for_min) {
                min_str[i] = '1';
            }
        }
    } else {
        for (int i = 1; min_str[i] != '\0'; i++) {
            if (min_str[i] != '0' && min_str[i] != '1') {
                x_for_min = min_str[i];
                break;
            }
        }
        if (x_for_min != '\0') {
            for (int i = 0; min_str[i] != '\0'; i++) {
                if (min_str[i] == x_for_min) {
                    min_str[i] = '0';
                }
            }
        }
    }
    int min_num = atoi(min_str);

    return max_num - min_num;
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    int result = maxDiff(num);
    printf("Max difference: %d\n", result);
    return 0;
}