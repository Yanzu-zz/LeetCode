#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 这题是个典型的背包问题，即在 n 个物品中选出一定物品，填满 sum/2 的背包
// 但这里不牵扯任何价值问题，刚好填满即可
class Solution416
{
private:
  // memo[i][c] 表示使用索引为 [0...i] 的这些元素，是否可以完全填充一个容量为 c 的背包
  // -1 表示未计算；0 表示不可以完全填充；1表示可以填充
  vector<vector<int>> memo;

  // 使用 nums[0...index] 判断是否能够完全填充一个容量为 sum 的背包
  // 当然，要注意使用记忆化搜索
  bool tryPartition(const vector<int> &nums, int index, int sum)
  {
    // 判断递归边界条件
    if (sum == 0) // 只有刚刚好完全塞满的情况才能算成功
      return true;
    if (sum < 0 || index < 0) // 塞过头了不行
      return false;

    if (memo[index][sum] != -1)
      return memo[index][sum]; // c 不等于0表示true

    // 查看不把当前数字塞进背包，只用前面的数字是否能塞满背包，若能，则不考虑当前数字
    // 或者考虑把当前数组塞进背包，并查看是否能塞满
    return memo[index][sum] = tryPartition(nums, index - 1, sum) ||
                              tryPartition(nums, index - 1, sum - nums[index]);
  }

public:
  // F(n, C) 考虑将 n 个物品填满容量为 C 的背包
  // 则状态转移方程为：F(i, c) = F(i-1, c) || F(i-1, c-w[i])
  // Time Complexit: O(n * sum/2) = O(n * sum)
  bool canPartition(vector<int> &nums)
  {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      assert(nums[i] > 0);
      sum += nums[i];
    }

    // 奇数无法分成两个整数
    if (sum % 2 != 0)
      return false;

    memo = vector<vector<int>>(nums.size(), vector<int>(sum / 2 + 1, -1));
    return tryPartition(nums, nums.size() - 1, sum / 2);
  }
};

int main(void)
{
  vector<int> arr1 = {1, 5, 11, 5};
  vector<int> arr2 = {1, 2, 3, 5};

  cout << Solution416().canPartition(arr1) << endl;
  cout << Solution416().canPartition(arr2) << endl;

  return 0;
}
