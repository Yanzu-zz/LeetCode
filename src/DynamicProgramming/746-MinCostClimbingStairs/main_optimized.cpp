
#include <iostream>
#include <vector>

using namespace std;

/**
 * dp解决 - 空间优化方案
 * 状态定义：minimumEnergy 表示到该级阶梯所花费的最小体力
 *  a,b,c 表示滚动变量代替 dp
 * 状态转移方程：c = min(a, b) + cost[i], a = b, b = c
 * 
 * 
 * 注意，到达阶梯顶部是要到 cost[n] 处，此时会越界，我们手动添加一个 0 到末尾即可解决问题
 */
class Solution746
{
public:
  int minCostClimbingStairs(vector<int> &cost)
  {
    int n = cost.size();
    cost.emplace_back(0);

    int a = cost[0], b = cost[1], c;
    for (int i = 2; i <= n; i++)
    {
      c = min(a, b) + cost[i];
      a = b;
      b = c;
    }

    return c;
  }
};

int main(void)
{
  vector<int> arr1 = {10, 15, 20};
  vector<int> arr2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

  cout << Solution746().minCostClimbingStairs(arr1) << endl;
  cout << Solution746().minCostClimbingStairs(arr2) << endl;

  return 0;
}
