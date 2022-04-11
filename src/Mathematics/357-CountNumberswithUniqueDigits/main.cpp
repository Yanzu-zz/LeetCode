#include <iostream>
#include <vector>

using namespace std;

class Solution357
{
public:
  int countNumbersWithUniqueDigits(int n)
  {
    if (n == 0)
      return 1;

    vector<int> dp(n + 1, 1);
    dp[1] = 10;

    /**
     * 动态转移方程为：
        dp[i] = dp[i-1] + (dp[i-1] - dp[i-2]) * (10 - (i-1))

      转移的初始条件为：
        dp[0] = 1
        dp[1] = 10
     */
    for (int i = 2; i <= n; i++)
      dp[i] = dp[i - 1] + (dp[i - 1] - dp[i - 2]) * (10 - (i - 1));

    return dp[n];
  }
};

int main(void)
{

  return 0;
}
