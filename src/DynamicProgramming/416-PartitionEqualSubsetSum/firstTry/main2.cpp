#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution416
{
public:
  // 动态规划解法
  bool canPartition(vector<int> &nums)
  {
    int sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      assert(nums[i] > 0);
      sum += nums[i];
    }

    if (sum % 2)
      return false;

    int n = nums.size();
    int C = sum / 2;
    // 用动态规划法自底向上解决的过程中，不存在某个值没解决是否塞入背包这个状态
    vector<bool> memo(C + 1, false);

    // 初始状态设置（就是根据这个已知状态一层层递推上去）
    for (int i = 0; i <= C; i++)
      memo[i] = (nums[0] == i);

    for (int i = 1; i < n; i++)
      for (int j = C; j >= nums[i]; j--)
        memo[j] = memo[j] || memo[j - nums[i]];

    return memo[C];
  }
};

int main(void)
{
  vector<int> arr1 = {5, 11, 1, 5};
  vector<int> arr2 = {1, 2, 3, 5};

  cout << Solution416().canPartition(arr1) << endl;
  cout << Solution416().canPartition(arr2) << endl;

  return 0;
}
