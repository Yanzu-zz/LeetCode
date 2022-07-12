#include <iostream>
#include <vector>

using namespace std;

class Solution1252
{
public:
  int oddCells(int m, int n, vector<vector<int>> &indices)
  {
    vector<int> rows(m), cols(n);
    // 记录数量
    for (auto index : indices)
    {
      rows[index[0]]++;
      cols[index[1]]++;
    }

    int res = 0;
    // 统计奇数格子数量
    for (int i = 0; i < m; i++)
    {
      int curRow = rows[i];
      for (int j = 0; j < n; j++)
        if ((curRow + cols[j]) & 1)
          res++;
    }
    return res;
  }
};

int main(void)
{

  return 0;
}
