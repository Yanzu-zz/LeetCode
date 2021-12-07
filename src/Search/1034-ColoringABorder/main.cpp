#include <iostream>
#include <vector>

using namespace std;

class Solution1034
{
private:
  int m, n; // 矩阵的宽高
  const int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  bool inGrid(int i, int j)
  {
    return i >= 0 && i < m && j >= 0 && j < n;
  }

  void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, vector<pair<int, int>> &borders, int i, int j, int connectedColor)
  {
    // 没有边界条件，因为在循环中不符合我们的继续寻找边界条件的话，是不会产生递归的
    if (!visited[i][j])
    {
      visited[i][j] = true; // 标记当前点位走过了，下面不会取消这个标记

      bool isBorder = false;
      for (int x = 0; x < 4; x++)
      {
        int newI = i + direction[x][0];
        int newJ = j + direction[x][1];

        // 如果当前到了 grid 的边界或者，如果下一个点位（不管四个方向的哪个）的值和当前的值不一样，那么当前传入的 i,j 就是一个边界
        if (!(inGrid(newI, newJ) && grid[newI][newJ] == connectedColor))
          isBorder = true; // 标记当前点位为边界
        else if (!visited[newI][newJ])
          dfs(grid, visited, borders, newI, newJ, connectedColor);
      }
      // 如果是边界的话就加进边界数组
      if (isBorder)
        borders.emplace_back(make_pair(i, j));
    }
  }

public:
  vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color)
  {
    m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m, vector(n, false));
    vector<pair<int, int>> borders; // 在 dfs 中找到的连通分量边界点坐标
    dfs(grid, visited, borders, row, col, grid[row][col]);

    // 深搜结束后就是把记录下来的连通分量边界染色
    for (const auto &[i, j] : borders)
      grid[i][j] = color;

    return grid;
  }
};

int main(void)
{

  return 0;
}
