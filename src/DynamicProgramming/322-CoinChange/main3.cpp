#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * 这是一道完全背包问题
 * dp 解法，定义：dp[i]：凑足总额为j所需钱币的最少个数为dp[i]
 * 递推公式：dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
 */
class Solution322
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    // 0元 是我们能确定的最小兑换个数，为 0，故要初始 amount + 1 个位置
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    // 开始 dp
    int i, j;
    for (i = 1; i <= amount; i++)
    {
      for (j = 0; j < coins.size(); j++)
        // 查看是不把当前硬币放入背包中的个数小还是将当前硬币放入背包中个数小
        if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
          dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};

int main(void)
{
  vector<int> coins1 = {1, 2, 5};
  int amount1 = 11;

  cout << Solution322().coinChange(coins1, amount1) << endl;

  return 0;
}
