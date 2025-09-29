// Minimum Score Triangulation of Polygon

#include <stdio.h>
#include <limits.h>

int minScoreTriangulation(int* values, int valuesSize) {
    int m = valuesSize;
    int dp[50][50]={0};

    for (int len=2;len<m;len++){
        for(int i=0;i+len<m;i++){
            int j=i+len;
            dp[i][j]=INT_MAX;
            for(int k=i+1;k<j;k++){
                int sco = dp[i][k] + dp[k][j] + values[i] * values[j] * values[k];

                if(sco<dp[i][j]) dp[i][j]=sco;
            }

        }
    }
    return dp[0][m-1];
}

int main() {
    int values[] = {1, 2, 3};
    int size = sizeof(values) / sizeof(values[0]);

    int result = minScoreTriangulation(values, size);
    printf("Minimum triangulation score: %d\n", result);

    return 0;
}