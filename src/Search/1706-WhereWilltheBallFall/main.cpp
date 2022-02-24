#include <iostream>
#include <vector>

using namespace std;

class Solution1706
{
private:
  int M, N;

  bool isInGrid(vector<vector<int>> &grid, int i, int j)
  {
    return i >= 0 && i < M && j >= 0 && j < N;
  }

  // 模拟深搜，不用递归
  int dfs(vector<vector<int>> &grid, int i, int j)
  {
    while (isInGrid(grid, i, j))
    {
      int comparedJ;
      if (grid[i][j] == 1)
        comparedJ = j + 1;
      else
        comparedJ = j - 1;

      // 判断当前位置的小球是否能够往下走（笔记情况）
      // 这里不能
      if (!isInGrid(grid, i, comparedJ))
        break;
      if (grid[i][j] != grid[i][comparedJ])
        break;

      // 到下个位置上去
      if (grid[i][j] == 1)
      {
        i = i + 1;
        j = j + 1;
      }
      else if (grid[i][j] == -1)
      {
        i = i + 1;
        j = j - 1;
      }
    }

    // 判断小球是否成功掉落到下面
    if (i >= M)
      return j;
    else
      return -1;
  }

public:
  vector<int> findBall(vector<vector<int>> &grid)
  {
    vector<int> res;
    M = grid.size();
    N = grid[0].size();

    // 开始模拟每个小球掉落的位置
    for (int j = 0; j < N; j++)
      res.emplace_back(dfs(grid, 0, j));

    return res;
  }
};

int main(void)
{

  return 0;
}
