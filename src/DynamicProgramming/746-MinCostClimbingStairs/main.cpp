#include <iostream>
#include <vector>

using namespace std;

/**
 * dp解决
 * 状态定义：dp[i]表示到该级阶梯所花费的最小体力
 * 状态转移方程：dp[i] = min(dp[i-1], dp[i-2]) + cost[i]
 * 
 * 注意，到达阶梯顶部是要到 cost[n] 处，此时会越界，我们手动添加一个 0 到末尾即可解决问题
 */
class Solution746
{
public:
  int minCostClimbingStairs(vector<int> &cost)
  {
    int n = cost.size();
    cost.emplace_back(0);

    vector<int> dp(n + 1, -1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i <= n; i++)
      dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];

    return dp[n];
  }
};

int main(void)
{
  vector<int> arr1 = {10, 15, 20};
  vector<int> arr2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

  cout << Solution746().minCostClimbingStairs(arr1) << endl;
  cout << Solution746().minCostClimbingStairs(arr2) << endl;

  return 0;
}
