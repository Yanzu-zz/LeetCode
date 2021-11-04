#include <iostream>
#include <vector>

using namespace std;

/**
 * dp 解法
 * dp[i][j] 表示以 （i，j）为右下角，只包含 1 的正方形的最长边长
 * i=0 && j=0 时，dp[i][j] = matrix[i][j]
 * i>0 && j>0 时，dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
 * 即从三个方向选最小的一个值出来 + 1
 * 遇到 0 则不作任何操作
 */
class Solution221
{
private:
  int min_3(int a, int b, int c)
  {
    return min(min(a, b), c);
  }

public:
  int maximalSquare(vector<vector<char>> &matrix)
  {
    int m = matrix.size(), n = matrix[0].size();
    int i, j, ret;

    // 初始化
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = matrix[0][0] - '0';
    ret = dp[0][0];
    for (j = 1; j < n; j++)
    {
      dp[0][j] = matrix[0][j] - '0';
      ret = max(ret, dp[0][j]);
    }
    for (i = 1; i < m; i++)
    {
      dp[i][0] = matrix[i][0] - '0';
      ret = max(ret, dp[i][0]);
    }

    // 开始 dp
    for (i = 1; i < m; i++)
    {
      for (j = 1; j < n; j++)
      {
        if (matrix[i][j] == '0')
          continue;

        dp[i][j] = min_3(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
        ret = max(ret, dp[i][j]);
      }
    }

    return ret * ret; // 别忘了我们存储的是边长，需要返回平方
  }
};

int main(void)
{
  vector<vector<char>> arr1 = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
  vector<vector<char>> arr2 = {{'0', '1'}, {'1', '0'}};
  vector<vector<char>> arr3 = {{'1'}};

  cout << Solution221().maximalSquare(arr1) << endl;
  cout << Solution221().maximalSquare(arr2) << endl;
  cout << Solution221().maximalSquare(arr3) << endl;

  return 0;
}
