#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

// 动态规划解法
class Knapsack01
{
public:
  int knapsack01(const vector<int> &w, const vector<int> &v, int C)
  {
    assert(w.size() == v.size());
    int n = w.size();
    if (n == 0)
      return 0;

    tor<int>> memo(n, vector<int>(C + 1, -1));

    // 初始化第一行为0或者为第一个物品的价值
    for (int j = 0; j <= C; j++)
      memo[0][j] = (j >= w[0] ? v[0] : 0);

    for (int i = 1; i < n; i++)
    {
      for (int j = 1; j <= C; j++)
      {
        // 第一个策略：不装入当前物品，而是延续上个放入物品时的价值
        memo[i][j] = memo[i - 1][j];
        // 第二个策略：放入当前物品，并且把当前物品的价值和减去当前物品占的格子数的价值相加
        // 并且和第一个策略得到的值对比，取较大值
        // 当然，容量边界默认你懂得判断
        if (j >= w[i])
          memo[i][j] = max(memo[i][j], v[i] + memo[i - 1][j - w[i]]);
      }
    }

    return memo[n - 1][C];
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
