// Maximum Difference Between Even and Odd Frequency I

#include <stdio.h>
#include <limits.h> // For INT_MIN and INT_MAX

int maxDifference(char* s)
{
	int i = 0;
	int freq[26] = {0};
	while(s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z') 
		{
            int index = s[i] - 'a';
            freq[index]++;
		}
		i++;
	}
	int maxOdd = INT_MIN;
    int maxEven = INT_MAX;
	for(int i = 0; i < 26; i++)
	{
		if(freq[i] > 0)
		{
			if (freq[i] % 2 == 0 && freq[i] < maxEven)
				maxEven = freq[i];
			else if (freq[i] % 2 != 0 && freq[i] > maxOdd)
				maxOdd = freq[i];
		}
	}
	int difference = maxOdd - maxEven;
	return (difference);
}

int main ()
{
	char s[] = "mmsmsym";
	printf("The maximum difference is: %d", maxDifference(s));
	return 0;
}