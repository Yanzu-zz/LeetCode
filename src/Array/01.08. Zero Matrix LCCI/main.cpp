#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int m = matrix.size(), n = matrix[0].size();

    vector<int> row(m), col(n);
    // 标记 0 的行列
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
        if (!matrix[i][j])
          row[i] = col[j] = true;
    }

    // 然后置零
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (row[i] == 1 || col[j] == 1)
          matrix[i][j] = 0;
  }
};

int main(void)
{

  return 0;
}
