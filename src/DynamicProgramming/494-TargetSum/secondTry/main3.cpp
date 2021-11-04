#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution494
{
public:
  int findTargetSumWays(vector<int> &nums, int target)
  {
    int n = nums.size(), sum = 0;
    for (const auto &num : nums)
      sum += abs(num);
    if (sum < abs(target))
      return 0;

    // 初始化 dp
    vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));
    dp[0][0 + sum] = 1;
    for (int i = 1; i <= n; i++)
    {
      int x = nums[i - 1];
      for (int j = -sum; j <= sum; j++)
      {
        if ((j - x) + sum >= 0)
          dp[i][j + sum] += dp[i - 1][(j - x) + sum];

        if ((j + x) + sum <= 2 * sum)
          dp[i][j + sum] += dp[i - 1][(j + x) + sum];
      }
    }

    return dp[n][target + sum];
  }
};

int main()
{

  return 0;
}