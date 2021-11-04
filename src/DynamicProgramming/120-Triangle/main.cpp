#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * 状态定义：dp[i][j] 表示到这个点所需的最小路径
 * 状态转移方程：i=0时，dp[i][j] = triangle[i][j]
 * i>0, j=0 时，dp[i][j] = triangle[i-1][j] + trianble[i][j]
 * i>0, j>triangle[i-1].size()时，dp[i][j]=triangle[i-1][j-1] + dp[i][j] 
 * i>0, 0 < j < triangle[i-1].size()时，dp[i][j] = min(triangle[i-1][j],triangle[i-1][j-1]) + triangle
 */
class Solution120
{
public:
  int minimumTotal(vector<vector<int>> &triangle)
  {
    int m = triangle.size();
    if (m == 1)
      return triangle[0][0];

    vector<vector<int>> dp(m);
    int i, j;

    // 下面就是根据我们上面定义好的状态初始化编码就行
    dp[0] = vector<int>(1, triangle[0][0]);
    int eachLineSize;
    for (i = 1; i < m; i++)
    {
      dp[i] = vector<int>(triangle.size(), INT_MAX);
      eachLineSize = triangle[i].size() - 1;
      dp[i][0] = dp[i - 1][0] + triangle[i][0];
      dp[i][eachLineSize] = dp[i - 1][eachLineSize - 1] + triangle[i][eachLineSize];
    }

    // 开始dp
    for (i = 2; i < m; i++)
    {
      eachLineSize = triangle[i].size() - 1;
      for (j = 1; j < eachLineSize; j++)
        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
    }

    // 遍历一遍最后一层数组，寻找最小值即可
    int ret = INT_MAX;
    for (j = 0; j < m; j++)
      ret = min(ret, dp[m - 1][j]);

    return ret;
  }
};

int main(void)
{
  vector<vector<int>> arr1 = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  vector<vector<int>> arr2 = {{-10}};
  vector<vector<int>> arr3 = {{5}, {-5, 7}};

  cout << Solution120().minimumTotal(arr1) << endl;
  cout << Solution120().minimumTotal(arr2) << endl;
  cout << Solution120().minimumTotal(arr3) << endl;

  return 0;
}
