#include <iostream>
#include <vector>

using namespace std;

class Solution53
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int n = nums.size();
    int dp = nums[0];
    int res = dp;

    // 按照笔记上分析的状态转移方程来就行
    for (int i = 1; i < n; i++)
    {
      dp = max(nums[i], dp + nums[i]);
      res = max(res, dp);
    }

    return res;
  }
};

int main()
{

  return 0;
}