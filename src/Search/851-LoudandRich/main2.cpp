#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution851
{
public:
  vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
  {
    int n = quiet.size();
    vector<int> inDeg(n);
    vector<vector<int>> g(n); // 拓扑排序入度图

    // 建图
    for (const auto &tmp : richer)
    {
      g[tmp[0]].emplace_back(tmp[1]);
      ++inDeg[tmp[1]];
    }

    vector<int> res(n);
    iota(res.begin(), res.end(), 0);
    queue<int> q;
    // 找出一开始入度为 0 的节点
    for (int i = 0; i < n; i++)
      if (inDeg[i] == 0)
        q.emplace(i);

    while (!q.empty())
    {
      int x = q.front();
      q.pop();

      for (int y : g[x])
      {
        if (quiet[res[x]] < quiet[res[y]])
          res[y] = res[x]; // 更新更有钱的人中又最安静的

        // 寻找下个入度为 0 的节点，保证拓扑排序继续进行
        if (--inDeg[y] == 0)
          q.emplace(y);
      }
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
