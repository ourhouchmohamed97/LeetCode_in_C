// Soup Servings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 200

double memo[MAX_SIZE][MAX_SIZE];

double dfs(int a, int b) {
    if (a <= 0 && b <= 0) return 0.5;
    if (a <= 0) return 1.0;
    if (b <= 0) return 0.0;
    if (memo[a][b] > 0) return memo[a][b];
    double prob = 0.0;
    prob += 0.25 * dfs(a - 4, b);
    prob += 0.25 * dfs(a - 3, b - 1);
    prob += 0.25 * dfs(a - 2, b - 2);
    prob += 0.25 * dfs(a - 1, b - 3);
    memo[a][b] = prob;
    return prob;
}

double soupServings(int n) {
    if (n >= 4800) return 1.0;
    int m = (n + 24) / 25;
    memset(memo, 0, sizeof(memo));
    return dfs(m, m);
}

int main() {
    int n;
    printf("Enter the amount of soup in mL (n): ");
    scanf("%d", &n);
    double result = soupServings(n);
    printf("The probability is: %.5f\n", result);
    return 0;
}