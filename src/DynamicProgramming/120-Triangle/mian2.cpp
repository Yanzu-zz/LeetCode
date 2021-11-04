#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * 空间优化方案，使用长度为 m 的滚动数组从后往前更新最短路径
 * 状态定义：dp[i] 表示到这个点所需的最小路径
 * 令 triangle[i].size() = len
 * 转移方程：i=0时，dp[i] = tri[0][0]
 * i>0, j=len 时，dp[i] = dp[j-1]+ tri[i][len - 1]
 * i>0,j=0 时，dp[i] = dp[j] + tri[i][j]
 * i>0, 0<j<len 时，dp[i] = min(dp[j], dp[j-1]) + tri[i][j]
 */
class Solution120
{
public:
  int minimumTotal(vector<vector<int>> &triangle)
  {
    int m = triangle.size();

    vector<int> dp(m, INT_MAX);
    int i, j, len;

    // 初始化
    dp[0] = triangle[0][0];
    for (i = 1; i < m; i++)
    {
      len = triangle[i].size() - 1;
      // 记得要从后往前更新，不然数据覆盖顺序错误
      for (j = len; j >= 0; j--)
      {
        // 处理队尾和队首两个边界条件
        if (j == len)
          dp[j] = dp[j - 1] + triangle[i][len];
        else if (j == 0)
          dp[j] = dp[0] + triangle[i][j];
        else // 正常 dp
          dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
      }
    }

    // 初始化

    int ret = INT_MAX;
    for (j = 0; j < m; j++)
      ret = min(ret, dp[j]);

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
