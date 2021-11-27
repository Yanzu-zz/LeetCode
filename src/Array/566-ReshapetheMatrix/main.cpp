#include <iostream>
#include <vector>

using namespace std;

class Solution566
{
public:
  vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
  {
    int n = mat.size(), m = mat[0].size();
    int total = n * m;
    // 如果需要重塑的个数与原矩阵对不上，则不可能成功，直接返回原矩阵
    if (r * c != total)
      return mat;

    vector<vector<int>> res(r, vector<int>(c));
    // 按照列的个数来 flatten 数组
    // 故不同数组的列个数不同就按照自己的列个数来即可
    for (int i = 0; i < total; i++)
      res[i / c][i % c] = mat[i / m][i % m];

    return res;
  }
};

int main()
{

  return 0;
}