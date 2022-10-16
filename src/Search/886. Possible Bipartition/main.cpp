#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool possibleBipartition(int n, vector<vector<int>> &dislikes)
  {
    vector<int> color(n + 1, 0);
    vector<vector<int>> g(n + 1);

    for (auto p : dislikes)
    {
      // 互相加入互斥数组
      g[p[0]].emplace_back(p[1]);
      g[p[1]].emplace_back(p[0]);
    }

    for (int i = 1; i <= n; i++)
    {
      if (color[i] == 0 && !dfs(i, 1, color, g))
        return false;
    }

    return true;
  }

  bool dfs(int curnode, int nowcolor, vector<int> &color, const vector<vector<int>> &g)
  {
    color[curnode] = nowcolor;
    for (auto &nextnode : g[curnode])
    {
      if (color[nextnode] && color[nextnode] == color[curnode])
      {
        return false;
      }
      if (!color[nextnode] && !dfs(nextnode, 3 ^ nowcolor, color, g))
      {
        return false;
      }
    }
    return true;
  }
};

int main(void)
{

  return 0;
}
