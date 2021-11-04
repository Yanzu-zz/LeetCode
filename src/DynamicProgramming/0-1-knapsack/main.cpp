#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

// 暴力递归解法
class Knapsack01
{
private:
  // 记忆化搜索，避免重叠子问题
  vector<vector<int>> memo;

  // 用 [0...index] 的物品，填充容积为 c 的背包的最大价值
  int bestValue(const vector<int> &w, const vector<int> &v, int index, int c)
  {
    if (index < 0 || c <= 0)
      return 0;

    if (memo[index][c] != -1)
      return memo[index][c];

    // 先不考虑放当前物品入背包
    int res = bestValue(w, v, index - 1, c);
    // 接着再考虑放当前物品入背包
    // 确认当前背包的剩余容量还能装得下当前物品
    if (c >= w[index])
      // 再考虑最优解
      res = max(res, v[index] + bestValue(w, v, index - 1, c - w[index]));

    memo[index][c] = res;
    return res;
  }

public:
  int knapsack01(const vector<int> &w, const vector<int> &v, int C)
  {
    assert(w.size() == v.size());

    int n = w.size();
    memo = vector<vector<int>>(n, vector<int>(C + 1, -1));

    return bestValue(w, v, n - 1, C);
  }
};

int main()
{
  vector<int> w1 = {1, 2, 3};
  vector<int> v1 = {6, 10, 12};
  int C1 = 5;
  cout << Knapsack01().knapsack01(w1, v1, C1) << endl;

  return 0;
}
