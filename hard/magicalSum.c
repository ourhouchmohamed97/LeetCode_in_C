// Find Sum of Array Product of Magical Sequences

#include <stdio.h>
#include <string.h>

#define MOD 1000000007L

// Dynamic upper bounds (safe for problem limits)
#define MAX_M 100
#define MAX_K 100
#define MAX_OVER 64

// Binomial coefficients
static long long choose[MAX_M + 1][MAX_M + 1];

// DP: dp[length][bits][carry]
static long long dp[MAX_M + 1][MAX_K + 1][MAX_OVER + 1];

static void precompute_choose(int M) {
    for (int n = 0; n <= M; n++) {
        choose[n][0] = choose[n][n] = 1;
        for (int k = 1; k < n; k++) {
            choose[n][k] = (choose[n - 1][k] + choose[n - 1][k - 1]) % MOD;
        }
    }
}

static inline int popcount(int x) {
    int c = 0;
    while (x) {
        x &= (x - 1);
        c++;
    }
    return c;
}

int magicalSum(int M, int K, int *nums, int numsSize) {
    memset(dp, 0, sizeof(dp));
    precompute_choose(M);
    dp[0][0][0] = 1;

    for (int i = 0; i < numsSize; i++) {
        // We process nums[i], updating dp
        for (int length = M; length >= 0; length--) {
            long long power = 1;

            for (int added = 1; added + length <= M; added++) {
                power = (power * nums[i]) % MOD;
                long long val = (power * choose[length + added][added]) % MOD;

                for (int bits = length; bits >= 0; bits--) {
                    for (int carry = 0; carry <= (length - bits) / 2; carry++) {
                        int tail_sum = added + carry;
                        int new_bits = bits + (tail_sum & 1);
                        int new_carry = tail_sum >> 1;

                        dp[length + added][new_bits][new_carry] =
                            (dp[length + added][new_bits][new_carry] +
                             dp[length][bits][carry] * val) % MOD;
                    }
                }
            }

            // Carry propagation cleanup
            for (int bits = length; bits >= 0; bits--) {
                for (int carry = 1; carry <= (length - bits) / 2; carry++) {
                    int new_bits = bits + (carry & 1);
                    int new_carry = carry >> 1;

                    dp[length][new_bits][new_carry] =
                        (dp[length][new_bits][new_carry] + dp[length][bits][carry]) % MOD;

                    dp[length][bits][carry] = 0;
                }
            }
        }
    }

    long long total = 0;
    for (int carry = 0; carry <= M / 2; carry++) {
        int extra_bits = popcount(carry);
        if (extra_bits <= K) {
            total = (total + dp[M][K - extra_bits][carry]) % MOD;
        }
    }

    return (int)total;
}

// --- Example Test ---
int main(void) {
    int nums[] = {4, 8, 56, 39, 50, 45, 18};
    printf("%d\n", magicalSum(10, 9, nums, 7));  // Should match expected output
    return 0;
}
