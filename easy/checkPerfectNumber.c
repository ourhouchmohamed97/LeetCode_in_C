// Perfect Number

#include <stdio.h>
#include <stdbool.h>

bool checkPerfectNumber(int num) {
    if (num <= 1)
        return false;
    int sum = 1;
    int i = 2;
    while(i*i <= num)
    {
        if(num % i == 0)
        {
            sum += i;
            if (i != num / i)
                sum += num / i;
        }
        i++;
    }
    return sum == num;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (checkPerfectNumber(num)) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }
    
    return 0;
}