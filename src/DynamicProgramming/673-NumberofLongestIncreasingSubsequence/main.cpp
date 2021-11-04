#include <iostream>
#include <vector>

using namespace std;

class Solution673
{
public:
  int findNumberOfLIS(vector<int> &nums)
  {
    int n = nums.size();
    // 初始化 dp 状态数组
    vector<int> dp(n, 1), count(n, 1);
    int maxVal = 0, ret = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (nums[i] > nums[j])
        {
          if (dp[j] + 1 > dp[i])
          {
            dp[i] = dp[j] + 1;
            count[i] = count[j];
          }
          else if (dp[j] + 1 == dp[i])
          {
            count[i] += count[j];
          }
        }
      }

      if (dp[i] > maxVal)
      {
        maxVal = dp[i];
        ret = count[i];
      }
      else if (dp[i] == maxVal)
      {
        ret += count[i];
      }
    }

    return ret;
  }
};

int main(void)
{
  vector<int> v1 = {1, 3, 5, 4, 7};
  vector<int> v2 = {2, 2, 2, 2, 2};
  vector<int> v3 = {1, 7, 7, 7, 7};
  vector<int> v4 = {1, 2, 4, 3, 5, 4, 7, 2};

  cout << Solution673().findNumberOfLIS(v1) << endl;
  cout << Solution673().findNumberOfLIS(v2) << endl;
  cout << Solution673().findNumberOfLIS(v3) << endl;
  cout << Solution673().findNumberOfLIS(v4) << endl;

  return 0;
}
