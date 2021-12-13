#include <iostream>
#include <vector>

using namespace std;

class Solution807
{
public:
  int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
  {
    int n = grid.size();
    vector<int> rowMax(n, 0); // 第 i 行的最高高度
    vector<int> colMax(n, 0); // 第 j 列的最高高度

    // 求出最高高度
    for (int x = 0; x < n; x++)
    {
      // 求每一行的最大值
      for (int i = 0; i < n; i++)
        rowMax[x] = max(rowMax[x], grid[x][i]);

      // 每一列
      for (int j = 0; j < n; j++)
        colMax[x] = max(colMax[x], grid[j][x]);
    }

    // 接着就能算天际线最高能加多少值
    int res = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        res += min(rowMax[i], colMax[j]) - grid[i][j];

    return res;
  }
};

int main(void)
{

  return 0;
}
