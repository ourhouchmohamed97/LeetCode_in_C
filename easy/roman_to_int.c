// Roman to Integer

#include <stdio.h>

int romancharToInt(char c)
{
    switch (c)
    {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
    }
}

int romanToInt(char *s)
{
    int total = 0;
    int i = 0;
    while(s[i])
    {
        if(s[i + 1] && romancharToInt(s[i]) < romancharToInt(s[i + 1]))
        {
            total += romancharToInt(s[i + 1]) - romancharToInt(s[i]);
                i += 2;
        }
        else
        {
            total += romancharToInt(s[i]);
            i++;
        }
    }
    return (total);
}

int main()
{
    char *s1 = "III";
    char *s2 = "LVIII";
    char *s3 = "MCMXCIV";

    printf("Input: s = \"%s\"\nOutput: %d\n", s1, romanToInt(s1)); // Output: 3
    printf("Input: s = \"%s\"\nOutput: %d\n", s2, romanToInt(s2)); // Output: 58
    printf("Input: s = \"%s\"\nOutput: %d\n", s3, romanToInt(s3)); // Output: 1994

    return 0;
}