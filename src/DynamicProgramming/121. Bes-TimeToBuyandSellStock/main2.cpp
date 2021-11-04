#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * 状态定义：dp[i] 表示当天能获得的最高利润
 * 状态转移方程：i=0 时，dp[i] = 0
 * i > 0, j < i 时，dp[i] = max(dp[i], prices[i] - prices[j])
 */
class Solution121
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    int i, j;
    int maxPrice;
    int ret = 0;
    vector<int> dp(n, 0); // 初始化全为 0 就不用手动置初值了

    for (i = 0; i < n; i++)
    {
      for (j = 0; j < i; j++)
        dp[i] = max(dp[i], prices[i] - prices[j]);

      ret = max(ret, dp[i]);
    }

    return ret;
  }
};

int main(void)
{
  vector<int> arr1 = {7, 1, 5, 3, 6, 4};
  vector<int> arr2 = {7, 6, 5, 4, 3, 2, 1};
  vector<int> arr3 = {2, 4, 1};

  cout << Solution121().maxProfit(arr1) << endl;
  cout << Solution121().maxProfit(arr2) << endl;
  cout << Solution121().maxProfit(arr3) << endl;

  return 0;
}
