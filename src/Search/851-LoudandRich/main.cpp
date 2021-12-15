#include <iostream>
#include <vector>

using namespace std;

class Solution851
{
private:
  void dfs(vector<vector<int>> &g, vector<int> &quiet, vector<int> &res, int x)
  {
    // 边界条件
    if (res[x] != -1)
      return;

    res[x] = x;
    for (int y : g[x])
    {
      // 向上（更有钱的）寻找喧闹值最低的
      dfs(g, quiet, res, y);
      // 如果找到了一个比当前更有钱的且喧闹值更低的就重新赋值
      if (quiet[res[y]] < quiet[res[x]])
        res[x] = res[y];
    }
  }

public:
  vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
  {
    int n = quiet.size();
    vector<vector<int>> g(n);

    // 建图
    for (const auto &tmp : richer)
      g[tmp[1]].emplace_back(tmp[0]);

    // 计算题目要求
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++)
      dfs(g, quiet, res, i);

    return res;
  }
};

int main(void)
{

  return 0;
}
