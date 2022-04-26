#include <iostream>
#include <vector>

using namespace std;

class Solution883
{
public:
  int projectionArea(vector<vector<int>> &grid)
  {
    int n = grid.size(), res = 0;

    for (int i = 0; i < n; i++)
    {
      int xy = 0, yz = 0, xz = 0;
      // 计算一个 grid[i] 的三视图面积
      for (int j = 0; j < n; j++)
      {
        xy += grid[i][j] != 0;
        yz = max(yz, grid[i][j]);
        xz = max(xz, grid[j][i]);
      }

      res += xy + yz + xz;
    }

    return res;
  }
};

int main(void)
{

  return 0;
}
