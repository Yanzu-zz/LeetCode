#include <iostream>
#include <vector>

using namespace std;

class Solution375
{
public:
  int getMoneyAmount(int n)
  {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    // 逆向遍历的原因： 举个例子： 如果要计算dp[1][n] 那么需要dp[1][k - 1], dp[k + 1][n]已经计算 在正向的遍历中，dp[k + 1][n]此时还没有得到计算（因为k + 1 > 1） 而在逆向的遍历中，因为k + 1 < n，1 < k - 1，二者都已经被计算
    for (int i = n - 1; i >= 1; i--)
    {
      for (int j = i + 1; j <= n; j++)
      {
        int minCost = INT_MAX;
        // i 和 j 只是控制范围，真正计算 dp 值的是 在下面的 k循环中
        for (int k = i; k < j; k++)
          minCost = min(minCost, k + max(dp[i][k - 1], dp[k + 1][j]));

        dp[i][j] = minCost;
      }
    }

    return dp[1][n];
  }
};

int main()
{

  return 0;
}