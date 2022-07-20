#include <iostream>
#include <vector>

using namespace std;

class Solution1260
{
public:
  vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
  {
    int m = grid.size(), n = grid[0].size();
    int totalSize = m * n;
    // 剪枝
    if (!(k % totalSize))
      return grid;

    vector<vector<int>> res(m, vector<int>(n));
    // 一维展开
    for (int i = 0; i < m; i++)
    {
      int j = 0;
      // 降维成一维的索引（是 shift 后的索引）
      int currIdx = (i * n + j + k) % totalSize;
      int curRow = currIdx / n, curCol = currIdx % n;
      for (; j < n; j++)
      {
        // 然后将这个一维的数组索引还原成二维赋值给返回数组
        res[curRow][curCol++] = grid[i][j];
        if (curCol >= n)
        {
          curCol = 0;
          curRow = ++curRow % m;
        }
      }
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
