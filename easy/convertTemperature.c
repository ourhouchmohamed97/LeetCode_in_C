// Convert the Temperature

#include <stdio.h>
#include <stdlib.h>

double* convertTemperature(double celsius, int* returnSize) {
    double* ans = (double*)malloc(2 * sizeof(double));
    if (!ans) return NULL;

    ans[0] = celsius + 273.15;
    ans[1] = celsius * 1.80 + 32.00;

    *returnSize = 2;

    return ans;
}

int main() {
    int returnSize;
    double* result;

    result = convertTemperature(36.50, &returnSize);
    printf("[%.5f, %.5f]\n", result[0], result[1]); // [309.65000, 97.70000]
    free(result);

    result = convertTemperature(122.11, &returnSize);
    printf("[%.5f, %.5f]\n", result[0], result[1]); // [395.26000, 251.79800]
    free(result);

    return 0;
}
