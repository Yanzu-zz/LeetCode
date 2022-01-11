#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution1036
{
private:
  int EDGE = 1E6, MAX = 1E5;
  long long BASE = 13331; // 映射二维坐标到一维的基数，要设置成 long long，不然下面承的时候类型还是 int 会溢出
  const int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  // BFS 函数确定是否可以走到 target 处
  // 注意，这里我们不会走完全程，而是计数走的格子多过 MAX 则表明一定能成功
  bool check(vector<int> &source, vector<int> &target, unordered_set<long long> &blockedSet)
  {
    queue<pair<int, int>> q;                      // 管理 BFS 的队列
    q.push(make_pair(source[0], source[1]));      // 初始化起始点
    unordered_set<long long> visited;             // 记录走过的格子数组，也是需要将二维打平成一维；注意，因为是将二维打平成一维，故使用 int和long 会溢出
    visited.insert(source[0] * BASE + source[1]); // 打平成一维坐标

    // 若队列空了或者走过的格子数量以及等于或者超过 MAX 了，则不用继续下去了
    while (q.size() > 0 and visited.size() <= MAX)
    {
      // 获取队列元素
      auto [x, y] = q.front();
      q.pop();

      // 走到目标点了
      if (x == target[0] and y == target[1])
        return true;

      // 没走到，则继续埋头往下走
      for (int i = 0; i < 4; i++)
      {
        int newX = x + direction[i][0];
        int newY = y + direction[i][1];

        // 注意！！！这里不是 DFS，不要下意识地使用递归了

        // 剪枝操作
        // 检查要走的新坐标是否越界
        if (!(newX >= 0 and newX < EDGE and newY >= 0 and newY < EDGE))
          continue;
        // 之前走过了也剪枝
        if (visited.count(newX * BASE + newY))
          continue;
        // 若新走的点是障碍物也剪枝
        if (blockedSet.count(newX * BASE + newY))
          continue;

        // 否则就加入队列中待 front()，并记录
        q.push(make_pair(newX, newY));
        visited.insert(newX * BASE + newY);
      }
    }

    return visited.size() > MAX;
  }

public:
  bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target)
  {
    if (blocked.size() == 0)
      return true;

    // 记录 blocked 障碍物的位置，相当于 visited 过
    unordered_set<long long> blockedSet;
    for (auto &b : blocked)
      blockedSet.insert(b[0] * BASE + b[1]);

    int n = blocked.size();
    MAX = n * (n - 1) / 2;

    // 只要两个点位都走过MAX就能成功
    return check(source, target, blockedSet) && check(target, source, blockedSet);
  }
};

int main(void)
{

  return 0;
}
