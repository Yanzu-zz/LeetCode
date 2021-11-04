#include <iostream>
#include <vector>
#include <set>

using namespace std;

/**
 * 解题思路：先遍历一遍 matrix，把遇到 0 元素的 行和列 分别加入2个集合中
 * 加入完毕后遍历集合中的行和列，将他们全部置 0
 */
class Solution73
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int m = matrix.size(), n = matrix[0].size();
    set<int> lines, rows;

    int i, j;
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        if (matrix[i][j] == 0) // 找到 0 就加入它的行列号
        {
          lines.insert(i);
          rows.insert(j);
        }

    set<int>::iterator lineIt, rowIt;
    // 置 0 加入的行
    for (lineIt = lines.begin(); lineIt != lines.end(); lineIt++)
      for (j = 0; j < n; j++)
        matrix[*lineIt][j] = 0;

    // 置 0 列
    for (rowIt = rows.begin(); rowIt != rows.end(); rowIt++)
      for (i = 0; i < m; i++)
        matrix[i][*rowIt] = 0;
  }
};

int main(void)
{

  return 0;
}
