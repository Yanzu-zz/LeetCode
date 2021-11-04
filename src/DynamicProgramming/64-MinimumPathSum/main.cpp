#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution64
{
public:
  int minPathSum(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();

    if (m == 1 && n == 1)
      return grid[0][0];

    // 状态定义：dp[i][j]表示从左上角触发到（i, j） 位置的最短路径和
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    dp[0][0] = grid[0][0]; // 初始化状态，题目确定是从左上角出发

    int i, j;
    // 当 i=0 时（即第一行，不算第一个），dp[i][j] = dp[i][j-1] + grid[i][j]
    for (j = 1; j < n; j++)
      dp[0][j] = dp[0][j - 1] + grid[0][j];

    // 当 i>0 且 j=0 时（即第二行开始的第一列）,dp[i][j] = dp[i-1][j] + grid[i][j]
    for (i = 1; i < m; i++)
      dp[i][0] = dp[i - 1][0] + grid[i][0];

    // 当 i>0 且 j>0 时，dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
    for (i = 1; i < m; i++)
      for (j = 1; j < n; j++)
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];

    return dp[m - 1][n - 1];
  }
};

int main(void)
{
  vector<vector<int>> arr1 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

  cout << Solution64().minPathSum(arr1) << endl;

  return 0;
}
