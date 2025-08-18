// 24 Game

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

bool solve(double* nums, int n) {
    if (n == 1) {
        return fabs(nums[0] - 24) < 1e-6;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            
            double newNums[4];
            int m = 0;
            for (int k = 0; k < n; k++) {
                if (k != i && k != j) {
                    newNums[m++] = nums[k];
                }
            }
            
            for (int op = 0; op < 4; op++) {
                if (op == 0) {
                    newNums[m] = nums[i] + nums[j];
                } else if (op == 1) {
                    newNums[m] = nums[i] - nums[j];
                } else if (op == 2) {
                    newNums[m] = nums[i] * nums[j];
                } else if (op == 3) {
                    if (nums[j] != 0) {
                        newNums[m] = nums[i] / nums[j];
                    } else {
                        continue;
                    }
                }
                
                if (solve(newNums, m + 1)) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

bool judgePoint24(int* cards, int cardsSize) {
    double nums[4];
    for (int i = 0; i < 4; i++) {
        nums[i] = (double)cards[i];
    }
    return solve(nums, 4);
}

int main() {
    int cards1[] = {4, 1, 8, 7};
    printf("%s\n", judgePoint24(cards1, 4) ? "true" : "false");
    
    int cards2[] = {1, 2, 1, 2};
    printf("%s\n", judgePoint24(cards2, 4) ? "true" : "false");
    
    return 0;
}