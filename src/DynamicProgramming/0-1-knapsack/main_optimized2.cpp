#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

// 动态规划 + 空间复杂度优化解法2（一行）
class Knapsack01
{
public:
  int knapsack01(const vector<int> &w, const vector<int> &v, int C)
  {
    assert(w.size() == v.size());
    int n = w.size();
    if (n == 0)
      return 0;

    // 我们只需要滚动一行进行参考计算即可
    vector<int> memo(C + 1, -1);
    // 初始化每个格子为0或者为第一个物品的价值
    for (int i = 0; i <= C; i++)
      memo[i] = (i >= w[0] ? v[0] : 0);

    for (int i = 1; i < n; i++)
      // 从右向左更新（不然会错误覆盖），并且要保证前面的格子数还能放下该物品
      for (int j = C; j >= w[i]; j--)
        memo[j] = max(memo[j], v[i] + memo[j - w[i]]); // 接着就是考虑放还是不放的收益高

    return memo[C];
  }
};

int main(void)
{
  vector<int> w1 = {1, 2, 3};
  vector<int> v1 = {6, 10, 12};
  int C1 = 5;
  cout << Knapsack01().knapsack01(w1, v1, C1) << endl;

  return 0;
}
