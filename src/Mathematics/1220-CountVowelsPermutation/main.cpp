#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution1220
{
public:
  int countVowelPermutation(int n)
  {
    long long MOD = 1e9 + 7;
    vector<long long> dp(5, 1);
    vector<long long> ndp(5);

    for (int i = 2; i <= n; i++)
    {
      // a 前面可以为 e,u,i
      ndp[0] = (dp[1] + dp[2] + dp[4]) % MOD;
      // e 前面可以为 a,i
      ndp[1] = (dp[0] + dp[2]) % MOD;
      // i 前面可以为 e,o
      ndp[2] = (dp[1] + dp[3]) % MOD;
      // o 前面可以为 i
      ndp[3] = dp[2];
      // u 前面可以为 i,o
      ndp[4] = (dp[2] + dp[3]) % MOD;
      dp = ndp;
    }

    return accumulate(dp.begin(), dp.end(), 0LL) % MOD;
  }
};

int main(void)
{

  return 0;
}
