#include <iostream>
#include <vector>

using namespace std;

/**
 * dp 解法 - 空间优化方案
 * 定义：dp[i] 表示到 i 间屋子处能 rob 到的最高利润
 * 转移方程：有 rob 和不 rob 当前屋子两种选择
 * 故 dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
 * 
 * boundary condition:
 *  dp[0]：表示当前只有一间屋子，干它！
 *  dp[1]：表示有两间，选一个 higher value 的干它
 * 
 * 我们注意到，从头到尾只需要三个滚动变量进行维护，故我们定义
 *  a: dp[i-2], b: dp[i-1], c: dp[i]
 */
class Solution198
{
public:
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    int a = nums[0], b, c;
    b = max(a, nums[1]);
    c = b;

    for (int i = 2; i < n; i++)
    {
      c = max(a + nums[i], b); // 选择抢或者不抢
      a = b;
      b = c;
    }

    return c;
  }
};

int main(void)
{
  vector<int> arr1 = {1, 2, 3, 1};
  vector<int> arr2 = {2, 7, 9, 3, 1};

  cout << Solution198().rob(arr1) << endl;
  cout << Solution198().rob(arr2) << endl;

  return 0;
}
