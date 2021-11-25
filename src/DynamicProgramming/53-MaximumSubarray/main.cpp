#include <iostream>
#include <vector>

using namespace std;

class Solution53
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int n = nums.size();
    int res = INT_MIN;
    int dp[n] = {0};
    dp[0] = nums[0];

    // 按照笔记上分析的状态转移方程来就行
    for (int i = 1; i < n; i++)
    {
      dp[i] = max(nums[i], dp[i - 1] + nums[i]);
      res = max(res, dp[i]);
    }

    return res;
  }
};

int main()
{

  return 0;
}