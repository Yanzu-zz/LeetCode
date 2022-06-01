#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution473
{
public:
  bool dfs(vector<int> &matchsticks, int matchsticksLen, vector<int> &edges, int idx, int borderLen)
  {
    // 边界条件
    // 能到这里就说明加上全部火柴长度都不超出条件，而总长度是可以除于 4 的，则表明可以围成正方形
    if (idx == matchsticksLen)
      return true;

    // 开始爆搜
    for (int i = 0; i < 4; i++)
    {
      edges[i] += matchsticks[idx]; // 将新的火柴放进去试试是否能成功
      if (edges[i] <= borderLen && dfs(matchsticks, matchsticksLen, edges, idx + 1, borderLen))
        return true;
      edges[i] -= matchsticks[idx]; // 这个放进去后发现不行，那就拿出来
    }

    return false;
  }

  bool makesquare(vector<int> &matchsticks)
  {
    // 总长度
    int totalLen = 0;
    for (int v : matchsticks)
      totalLen += v;

    // 总长度不能分为 4 个边，则退出剪枝
    if (totalLen % 4 & 1)
      return false;

    // 一条边的长度
    int borderLen = totalLen >> 2;
    int n = matchsticks.size();
    vector<int> edges(4, 0);
    sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // 从小到大爆搜，减少搜索量
    return dfs(matchsticks, n, edges, 0, borderLen);
  }
};

int main()
{

  return 0;
}