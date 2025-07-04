// Find the K-th Character in String Game II

#include <cmath>
#include <vector>
using namespace std;

class Solution {
 public:
  char kthCharacter(long long k, vector<int>& operations) {
    const int operationsCount = ceil(log2(k));
    int increases = 0;

    for (int i = operationsCount - 1; i >= 0; --i) {
      const long halfSize = 1L << i;
      if (k > halfSize) {
        k -= halfSize;  // Move k from the right half to the left half.
        increases += operations[i];
      }
    }

    return 'a' + increases % 26;
  }
};

int main() 
{
  Solution solution;
  vector<int> operations1 = {1, 2, 3};
  long long k1 = 5;
  char result1 = solution.kthCharacter(k1, operations1);
  // Expected output: 'd'

  vector<int> operations2 = {0, 1, 2, 3};
  long long k2 = 10;
  char result2 = solution.kthCharacter(k2, operations2);
  // Expected output: 'g'

  return 0;
}