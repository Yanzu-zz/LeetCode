#include <iostream>
#include <vector>

using namespace std;

class Solution122
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2));

    // boundary condition
    // 有第一天 不持有股票和买入股票 两种状态
    dp[0][0] = 0;
    dp[0][1] = -prices[0]; // 买入即扣了这么多现金

    // 开始 dp，因为第一天初始情况以及考虑了，故我们从第二天开始
    for (int i = 1; i < n; i++)
    {
      // 即 昨天不持有股票延续到今天以及昨天持有股票但是今天卖了 这两种状态，选择收益大的那个
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
      // 昨天持有股票今天也没卖掉以及昨天没持有股票但是今天买入了 两种状态
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }

    // 最终结果一定是最后一天没有买入股票的情况（不存在负值）
    return dp[n - 1][0];
  }
};

int main(void)
{

  return 0;
}
