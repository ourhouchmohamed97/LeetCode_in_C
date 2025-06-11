// String to Integer (atoi)

#include <stdio.h>
#include <limits.h>

int myAtoi(char* s) {
    unsigned long long	res;
	int					i;
	int					sign;

	i = 0;
	sign = 1;
	res = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] && (s[i] >= 48 && s[i] <= 57))
	{
		res = res * 10 + s[i] - '0';
		i++;
		if (res > INT_MAX) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
	}
	return ((int)(res * sign));
}


int main() {
    char str1[] = "   -42";
    char str2[] = "419 with words";
    char str3[] = "words and 987";
    char str4[] = "2147483648"; // Overflow case

    printf("Result 1: %d\n", myAtoi(str1)); // Expected: -42
    printf("Result 2: %d\n", myAtoi(str2)); // Expected: 419
    printf("Result 3: %d\n", myAtoi(str3)); // Expected: 0
    printf("Result 4: %d\n", myAtoi(str4)); // Expected: 2147483647 (INT_MAX)

    return 0;
}