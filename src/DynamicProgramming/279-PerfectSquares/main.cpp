#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * dp解决
 * dp[i] 表示 i 这个数需要的最少完全平方数相加的个数
 * dp[i] = min(dp[i], dp[i-j*j] + 1)
 */
class Solution279
{
public:
  int numSquares(int n)
  {
    vector<int> dp(n + 1, n);
    dp[0] = 0, dp[1] = 1;
    int i, j;
    for (i = 2; i <= n; i++)
      for (j = (int)sqrt(i); j > 0; j--)
        dp[i] = min(dp[i], dp[i - j * j] + 1);

    return dp[n];
  }
};

int main(void)
{
  cout << Solution279().numSquares(12) << endl;
  cout << Solution279().numSquares(13) << endl;

  return 0;
}
