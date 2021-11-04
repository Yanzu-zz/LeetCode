#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 自底向上动态规划解决此问题（有了 main.cpp 中的状态定义）
class Solution198
{
public:
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    assert(n > 0);
    // memo[i] 表示考虑抢劫 nums[i...n-1) 所能获得的最大收益
    vector<int> memo(n, -1);

    // 我们看题目可知，最后一个位置的最大收益肯定就是它自己，所以这个状态就确定下来了
    // 接下来就通过这个状态转移到其它状态即可
    memo[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) // 求解 memo[i]
      for (int j = i; j < n; j++)
        // 动态转移方程
        memo[i] = max(memo[i], nums[j] + (j + 2 < n ? memo[j + 2] : 0)); // 考虑当前的收益和后面房子的收益（因为后面的最优值已经求得）

    return memo[0];
  }
};

int main()
{
  vector<int> arr1 = {1, 2, 3, 1};
  vector<int> arr2 = {2, 7, 9, 3, 1};

  cout << Solution198().rob(arr1) << endl;
  cout << Solution198().rob(arr2) << endl;

  return 0;
}
