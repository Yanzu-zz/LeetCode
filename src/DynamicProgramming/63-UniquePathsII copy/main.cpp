#include <iostream>
#include <vector>

using namespace std;

/**
 * dp状态定义：dp[i][j] 表示当前点有多少不同的路径能够到达
 * 状态转移方程：dp第一行和第一列值都为 1，因为这些地方只能一个方向到达
 * 其余地方为：dp[i][j] = dp[i-1][j] + dp[i][j-1]
 * 如上或左边遇到障碍物，则延续另一个没有障碍物的方向的数字
 * 如两边都有障碍物，则 dp[i][j] = 0（即不可到达）
 */
class Solution63
{
private:
  const int ROAD = 0;
  const int WALL = 1;

public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    if (obstacleGrid[0][0] == WALL)
      return 0;

    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (m == 1 && n == 1)
      return 1;

    // 这里不能简单初始化全为 1，
    vector<vector<int>> dp(m, vector<int>(n, 0));

    int i, j;
    // 初始化第一行
    // 第一行只要遇到了一个 障碍物，后面的格子就是无法抵达状态
    for (j = 1; j < n && obstacleGrid[0][j] == ROAD; j++)
      dp[0][j] = 1;

    // 初始化第一列
    // 同理向下初始化过程中不能有墙的存在
    for (i = 1; i < m && obstacleGrid[i][0] == ROAD; i++)
      dp[i][0] = 1;

    // 开始 dp
    int leftVal, upVal;
    for (i = 1; i < m; i++)
    {
      for (j = 1; j < n; j++)
      {
        // 格子不能为障碍物
        if (obstacleGrid[i][j] == WALL)
          continue;

        // 有四种情况，一种是上下都是畅通的
        // 第二种是上边是墙，那么此时延续左边的数字即可
        // 第三种是左边是墙，那么此时延续上边的数字即可
        // 第四种是上、左都是墙，那么次点不通，置 0
        leftVal = obstacleGrid[i][j - 1];
        upVal = obstacleGrid[i - 1][j];
        if (leftVal != WALL && upVal != WALL)
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        else if (leftVal != WALL && upVal == WALL)
          dp[i][j] = dp[i][j - 1];
        else if (leftVal == WALL && upVal != WALL)
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = 0;
      }
    }

    return dp[m - 1][n - 1];
  }
};

int main(void)
{
  vector<vector<int>> arr1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  vector<vector<int>> arr2 = {{0, 1}, {0, 0}};
  vector<vector<int>> arr3 = {{1}};
  vector<vector<int>> arr4 = {{1, 0}};

  cout << Solution63().uniquePathsWithObstacles(arr1) << endl;
  cout << Solution63().uniquePathsWithObstacles(arr2) << endl;
  cout << Solution63().uniquePathsWithObstacles(arr3) << endl;
  cout << Solution63().uniquePathsWithObstacles(arr4) << endl;

  return 0;
}
