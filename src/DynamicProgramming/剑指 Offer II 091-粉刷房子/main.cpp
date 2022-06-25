#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int minCost(vector<vector<int>> &costs)
  {
    int n = costs.size();
    // 初始化 dp
    vector<vector<int>> dp(n, vector<int>(3, 0));
    for (int i = 0; i < 3; i++)
      dp[0][i] = costs[0][i];

    // 开始状态转移方程
    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        // 需要和上一轮不一致
        dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + costs[i][j];
      }
    }

    // 返回预算最小值
    return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
  }
};

int main(void)
{

  return 0;
}
