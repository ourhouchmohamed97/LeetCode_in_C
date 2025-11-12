// Minimum Number of Operations to Make All Array Elements Equal to 1

static int gcd(int a, int b){
	while (b != 0){
		const int c = a % b;

		a = b;
		b = c;
	}
	return a;
}

int minOperations(const int * const nums, const int numsLen){
	int oneCnt = 0;
	for (int i = 0; i < numsLen; i += 1){
		if (1 == nums[i]){
			oneCnt += 1;
		}
	}
	if (oneCnt >= 1){
		return numsLen - oneCnt;
	}

	int minSubArrLen = numsLen + 1;
	for (int i = 0; i < numsLen; i += 1){
		int curGcd = nums[i];
		for (int j = i + 1; j < numsLen; j += 1){
			curGcd = gcd(curGcd, nums[j]);

			if (1 == curGcd){
				const int curSubArrLen = (j + 1) - i;

				if (curSubArrLen < minSubArrLen){
					minSubArrLen = curSubArrLen;
				}

				break;
			}
		}
	}

	return (minSubArrLen <= numsLen)? ( (minSubArrLen - 1) + (numsLen - 1) ) : -1;
}