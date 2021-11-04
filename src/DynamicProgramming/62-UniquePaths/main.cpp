#include <iostream>
#include <vector>

using namespace std;

/**
 * dp状态定义：dp[i][j] 表示当前点有多少不同的路径能够到达
 * 状态转移方程：dp第一行和第一列值都为 1，因为这些地方只能一个方向到达
 * 其余地方为：dp[i][j] = dp[i-1][j] + dp[i][j-1]
 */
class Solution62
{
public:
  int uniquePaths(int m, int n)
  {
    if (m == 1 && n == 1)
      return 1;

    // 初始化全为 1 就不用再手动初始第一行和第一列了
    vector<vector<int>> dp(m, vector<int>(n, 1));

    // 开始 dp
    int i, j;
    for (i = 1; i < m; i++)
      for (j = 1; j < n; j++)
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    return dp[m - 1][n - 1];
  }
};

int main(void)
{
  int m1 = 3, n1 = 7;
  int m2 = 3, n2 = 3;

  cout << Solution62().uniquePaths(m1, n1) << endl;
  cout << Solution62().uniquePaths(m2, n2) << endl;

  return 0;
}
