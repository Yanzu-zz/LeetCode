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
    if (sum % 2 != 0 || maxNum > sum / 2)
      return false;

    // 上面条件都通过则说明数组一定能被分隔成两个等和数组
    int target = sum / 2;                                    // 分隔两个等和数组的和
    vector<vector<bool>> dp(n, vector<bool>(target + 1, 0)); // dp[i][j] 表示从数组的 [0，i] 下标范围内选取若干个正整数（可以是0个），是否存在一种选取方案使得被选取的正整数的和等于 j

    for (int i = 0; i < n; i++)
      dp[i][0] = true;
    dp[0][nums[0]] = true; // 第一个元素只有可能是自己的值的位置为 true

    for (int i = 1; i < n; i++)
    {
      int num = nums[i];
      for (int j = 1; j <= target; j++)
      {
        if (j > num)
        {
          // 有不选择当前数字累加 和 选择当前数组累加的情况两种，一种为 true 即为 true
          //  dp[i - 1][j - num] 别看有减号，其实表达的是 j-num 是否在数组里的意思
          dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
        }
        else
        {
          dp[i][j] = dp[i - 1][j];
        }
      }

      // 剪枝
      // 只要某个行的 target 为true，则表明一定有两个等和数组，这里不求具体的，我们直接返回 true 即可
      if (dp[i][target])
        return true;
    }

    return dp[n - 1][target];
  }
};

int main()
{
  vector<int> arr1 = {1, 2, 3, 6};
  cout << Solution416().canPartition(arr1) << endl;

  return 0;
}