// Categorize Box According to Criteria

#include <stdio.h>
#include <stdbool.h>

const char* categorizeBox(int length, int width, int height, int mass) {
    long long volume = 1LL * length * width * height;

    bool bulky = (length >= 10000 || width >= 10000 || height >= 10000 || volume >= 1000000000LL);
    bool heavy = (mass >= 100);

    if (bulky && heavy) return "Both";
    if (bulky) return "Bulky";
    if (heavy) return "Heavy";
    return "Neither";
}

int main() {
    printf("%s\n", categorizeBox(1000, 35, 700, 300));  // Expected "Heavy"
    printf("%s\n", categorizeBox(200, 50, 800, 50));    // Expected "Neither"
    printf("%s\n", categorizeBox(10000, 1, 1, 1));      // Expected "Bulky"
    printf("%s\n", categorizeBox(10000, 1, 1, 200));    // Expected "Both"
    return 0;
}
