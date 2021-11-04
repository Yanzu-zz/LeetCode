#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution416
{
public:
  bool canPartition(vector<int> &nums)
  {
    int n = nums.size();
    if (n < 2)
      return false;

    // 把 nums 的所有元素都累加起来，如果是奇数，则不可能能够分隔成两份等和数组，直接返回 false
    // 累加的同时也求得数组最大元素 maxNum，若最大元素比 sum/2 还大，则表明不可能能够分隔成两份等和数组，直接返回 falsec
    int sum = 0, maxNum = INT_MIN;
    for (const auto &num : nums)
    {
      sum += num;
      maxNum = max(maxNum, num);
    }
    if (sum & 1 || maxNum > sum / 2)
      return false;

    // 上面条件都通过则说明数组一定能被分隔成两个等和数组
    int target = sum / 2;               // 分隔两个等和数组的和
    vector<bool> dp(target + 1, false); // 在计算 \textit{dp}dp 的过程中，每一行的 dpdp 值都只与上一行的 dpdp 值有关，因此只需要一个一维数组即可将空间复杂度降到 O(\textit{target})O(target)// 在计算 dp 的过程中，每一行的 dpdp 值都只与上一行的 dp 值有关，因此只需要一个一维数组即可将空间复杂度降到 O(target)
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
      int num = nums[i];
      for (int j = target; j >= num; j--)
        // 简写 dp[j] |= dp[j-num];
        dp[j] = dp[j] | dp[j - num]; // dp[j] 为上面元素能累加到的布尔值 或 当前元素加上之前的元素能累加到 j 的布尔值

      // 剪枝
      if (dp[target])
        return true;
    }

    return dp[target];
  }
};

int main()
{
  vector<int> arr1 = {1, 2, 3, 6};
  cout << Solution416().canPartition(arr1) << endl;

  return 0;
}