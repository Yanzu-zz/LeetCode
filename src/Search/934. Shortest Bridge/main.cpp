#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 右下左上 顺序方向

  int shortestBridge(vector<vector<int>> &grid)
  {
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false)); // visited 数组

    // 找到其中一个岛，将其值全变成2（其它值也行）
    bool isFindIsland = false;
    // 修改完后就是判断最近的步数了
    // 先将值为2的岛的格子入队
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (!isFindIsland && grid[i][j] == 1)
        {
          isFindIsland = true;
          dfs(grid, visited, i, j);
        }

        if (grid[i][j] == 2)
          q.emplace(i, j);
      }
    }

    visited.clear();
    visited.resize(n, vector<bool>(n, false));

    int currStep = 0;
    // 人队完就是 广搜了
    while (q.size() > 0)
    {
      int len = q.size();
      for (int k = 0; k < len; k++)
      {
        // 取出坐标
        int i = q.front().first, j = q.front().second;
        q.pop();

        visited[i][j] = true;

        for (int x = 0; x < 4; x++)
        {
          int newI = i + direction[x][0];
          int newJ = j + direction[x][1];
          if (newI >= 0 && newI < n && newJ >= 0 && newJ < n && !visited[newI][newJ])
          {
            if (grid[newI][newJ] == 0)
              q.emplace(newI, newJ);
            else if (grid[newI][newJ] == 1) // 找到直接返回
              return currStep;
          }
        }
      }

      currStep++; // 加多一次层数
    }

    return currStep;
  }

  void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y)
  {
    int n = grid.size();
    visited[x][y] = true;
    grid[x][y] = 2; // 修改为2，好为后面的判断最短距离做铺垫

    for (int i = 0; i < 4; i++)
    {
      // 下个格子
      int newX = x + direction[i][0];
      int newY = y + direction[i][1];

      if (newX >= 0 && newX < n && newY >= 0 && newY < n && !visited[newX][newY] && grid[newX][newY] == 1)
        dfs(grid, visited, newX, newY);
    }
  }
};

int main(void)
{
  vector<vector<int>> grid1 = {{0, 1}, {1, 0}};
  Solution().shortestBridge(grid1);

  return 0;
}
