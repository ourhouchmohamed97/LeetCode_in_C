// Fruit Into Baskets

#include <stdio.h>
#include <stdlib.h>

int totalFruit(int* fruits, int fruitsSize) {
    if (fruitsSize <= 2) {
        return fruitsSize;
    }
    
    int maxFruits = 0;
    int left = 0;
    int type1 = -1, type2 = -1;
    int count1 = 0, count2 = 0;
    
    for (int right = 0; right < fruitsSize; right++) {
        int current = fruits[right];
        
        if (current == type1 || type1 == -1) {
            type1 = current;
            count1++;
        } else if (current == type2 || type2 == -1) {
            type2 = current;
            count2++;
        } else {
            while (count1 > 0 && count2 > 0) {
                int leftFruit = fruits[left];
                if (leftFruit == type1) {
                    count1--;
                } else if (leftFruit == type2) {
                    count2--;
                }
                left++;
            }
            if (count1 == 0) {
                type1 = current;
                count1 = 1;
            } else {
                type2 = current;
                count2 = 1;
            }
        }
        
        int currentTotal = count1 + count2;
        if (currentTotal > maxFruits) {
            maxFruits = currentTotal;
        }
    }
    
    return maxFruits;
}

int main() {
    int fruits1[] = {1, 2, 1};
    int size1 = sizeof(fruits1) / sizeof(fruits1[0]);
    printf("%d\n", totalFruit(fruits1, size1));
    
    int fruits2[] = {0, 1, 2, 2};
    int size2 = sizeof(fruits2) / sizeof(fruits2[0]);
    printf("%d\n", totalFruit(fruits2, size2));
    
    int fruits3[] = {1, 2, 3, 2, 2};
    int size3 = sizeof(fruits3) / sizeof(fruits3[0]);
    printf("%d\n", totalFruit(fruits3, size3));
    
    return 0;
}