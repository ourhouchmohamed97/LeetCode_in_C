// Count the Number of Computer Unlocking Permutations

#define MOD 1000000007

int countPermutations(int* complexity, int complexitySize) {
    int first = complexity[0];

    for (int i = 1; i < complexitySize; i++) {
        if (complexity[i] <= first) return 0;
    }

    long long fact = 1;
    for (int i = 2; i < complexitySize; i++) {
        fact = (fact * i) % MOD;
    }

    return (int)fact;
}