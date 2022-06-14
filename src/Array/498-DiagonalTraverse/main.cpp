#include <iostream>
#include <vector>

using namespace std;

class Solution498
{
private:
  int m, n;
  void traverse(vector<vector<int>> &mat, vector<int> &res, int row, int col, bool &isNeedReverse)
  {
    vector<int> tmp;

    // 只用判断 列 就行
    // 当前行和列位置，若当前列 col == 0 了则表明本次到头了
    while (row >= 0 && row < m && col >= 0 && col < n)
      tmp.emplace_back(mat[row++][col--]);

    // 当占位符表明tmp需要反转时就翻转一下
    if (isNeedReverse)
    {
      int i = 0, j = tmp.size() - 1;
      while (i < j)
      {
        int xx = tmp[i];
        tmp[i++] = tmp[j];
        tmp[j--] = xx;
      }
    }

    res.insert(res.end(), tmp.begin(), tmp.end());
    isNeedReverse = !isNeedReverse;
  }

public:
  vector<int> findDiagonalOrder(vector<vector<int>> &mat)
  {
    vector<int> res;
    bool isNeedReverse = true;
    m = mat.size(), n = mat[0].size();

    if (n == 1 || m == 1)
    {
      for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
          res.emplace_back(mat[i][j]);

      return res;
    }

    // 开始模拟
    // 先搞第一行
    for (int j = 0; j < n - 1; j++)
    {
      traverse(mat, res, 0, j, isNeedReverse);
    }

    // 然后右边那一列
    for (int i = 0; i < m; i++)
    {
      traverse(mat, res, i, n - 1, isNeedReverse);
    }

    return res;
  }
};

int main()
{

  return 0;
}