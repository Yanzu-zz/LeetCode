#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution310
{
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
  {
    if (n == 1)
      return {0};

    vector<vector<int>> adj(n); // 邻接表
    vector<int> degree(n, 0);   // 出入度表
    queue<int> qu;

    // 初始化邻接表
    // 注意树是无向图，需要双向记录
    for (auto &edge : edges)
    {
      int a = edge[0], b = edge[1];
      adj[a].emplace_back(b);
      adj[b].emplace_back(a);
      degree[a]++;
      degree[b]++;
    }

    // 然后将叶子节点（出入度为1）入队
    // 注意，入队的是节点值，不是节点的出入度个数
    for (int i = 0; i < n; i++)
      if (degree[i] == 1)
        qu.emplace(i);

    // 接着就是拓扑排序了
    // 注意，这里要用一个变量来保存剩余节点，因为有可能中间有个节点下面链接很多个，
    // 而它只连接一个父节点，此时用 qu.size() 逻辑就错误来了
    int remainNodes = n;
    while (remainNodes > 2)
    {
      int len = qu.size();
      remainNodes -= len;
      for (int i = 0; i < len; i++)
      {
        int curr = qu.front();
        qu.pop();
        // 将下一轮的叶子节点入队
        for (int &v : adj[curr])
        {
          if (--degree[v] == 1)
            qu.emplace(v);
        }
      }
    }

    // 剩下的就是最小高度树的根节点了
    vector<int> res;
    while (qu.size())
    {
      res.emplace_back(qu.front());
      qu.pop();
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
