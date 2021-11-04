#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution279
{
public:
  // 动态规划解决问题
  int numSquares(int n)
  {
    vector<int> dp(n + 1, n);
    dp[0] = 0;

    // 状态转移方程为 dp[i] = min(dp[i], dp[i - j*j] + 1)
    // 其中 dp[i] 最坏情况就是 i 个1加起来，即等于 i
    // dp[i - j*j]还要加一的原因是，既然比它小，那么到达这一步肯定要加一
    for (int i = 1; i <= n; i++)
      for (int j = (int)sqrt(i); j > 0; j--)
        dp[i] = min(dp[i], dp[i - j * j] + 1);

    return dp[n];
  }
};

int main()
{
  cout << Solution279().numSquares(12) << endl;
  cout << Solution279().numSquares(13) << endl;

  return 0;
}